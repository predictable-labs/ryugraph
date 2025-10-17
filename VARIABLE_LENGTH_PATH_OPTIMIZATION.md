# Variable-Length Path Query Performance Optimization

## Problem Statement

Variable-length path queries exhibit 1000-2300x performance degradation compared to equivalent explicit multi-hop patterns on small datasets (200k nodes).

### Case 1: Basic Fixed-Length Path (1000x slower)
```cypher
// Non-recursive version: 26.15ms, returns 41,483 rows
MATCH (:A)-[]->()-[]->(:B) RETURN count(*);

// Recursive version: 28,484.25ms, returns 41,483 rows
MATCH (:A)-[*2]->(:B) RETURN count(*);
```

**Performance gap:** 1089x slower (28.5s vs 26ms for identical results)

### Case 2: Fixed-Length Path with Selective Join (2300x slower)
```cypher
// Non-recursive: 97.12ms, returns 1,113 rows
MATCH (:A)-[]->()-[]->(:B)<-(:C) RETURN count(*);

// Recursive: 220,731.62ms, returns 1,113 rows
MATCH (:A)-[*2]->(:B)<-(:C) RETURN count(*);
```

**Performance gap:** 2272x slower, where `(:B)<-(:C)` alone takes only 28.30ms and returns 33 rows

---

## Root Cause Analysis

### 1. Architectural Overhead in Query Planning

**Location:** `src/planner/plan/append_extend.cpp:99-165`

**Issue:** Variable-length paths use a fundamentally different execution architecture:

**Non-Recursive Extends (Fast Path):**
```
Input Scan → Extend(hop1) → Extend(hop2) → Filter → Output
```
- Direct pipeline integration
- No intermediate materialization
- No hash joins

**Recursive Extends (Slow Path):**
```
Input Scan → [Properties] ─┐
                             ├─ Hash Join → Output
RecursiveExtend Pipeline ───┘
  ├─ GDS BFS Algorithm
  ├─ Path Node Property Scan
  └─ Path Rel Property Scan → PathPropertyProbe
```

**Key Bottlenecks:**
- **Line 161:** Hash join to merge GDS pipeline with input scan
  - `appendHashJoin(joinConditions, JoinType::INNER, probePlan, plan, plan)`
  - Cost model penalty: `BUILD_PENALTY * buildCardinality` (line 27 in cost_model.cpp)
  - For 200k nodes, this adds ~200k × BUILD_PENALTY overhead

- **Lines 124-140:** Separate property scanning pipelines
  - `createPathNodePropertyScanPlan()` - full table scan for node properties
  - `createPathRelPropertyScanPlan()` - extend + scan for relationship properties
  - Then merged via `LogicalPathPropertyProbe`

### 2. Inefficient Execution Model

**Location:** `src/processor/operator/recursive_extend.cpp:110-154`

**Issue:** Sequential per-source-node BFS execution:

```cpp
for (auto& tableID : graph->getNodeTableIDs()) {
    for (auto offset = 0u; offset < maxOffset; ++offset) {
        // For EACH source node, run full BFS:
        computeState->initSource(sourceNodeID);
        GDSUtils::runRecursiveJoinEdgeCompute(context, *computeState, graph,
            bindData.extendDirection, bindData.upperBound, ...);
        // Materialize results with frontier-based vertex compute
        GDSUtils::runVertexCompute(context, computeState->frontierPair->getState(),
            graph, *vertexCompute);
    }
}
```

**Problems:**
1. **Sequential processing:** Each source node processed one-by-one (no batching)
2. **Full BFS overhead:** Even for `[*2]`, runs complete BFS with frontier management
3. **Frontier materialization:** Maintains `DenseSparseDynamicFrontierPair` structures
4. **Path tracking:** LinkedList-based `ParentList` for all paths across iterations

**For Case 1 example:**
- Processes potentially 200k source nodes (type :A)
- Each runs 2-iteration BFS
- Total: ~400k BFS iterations for something that could be 2 sequential extends

### 3. Missing Query Optimization

**Location:** `src/planner/plan/plan_join_order.cpp:303-324`

**Issue:** No query rewrite for bounded variable-length paths

The planner's `appendExtend()` method directly dispatches to recursive extend without checking:
```cpp
switch (rel->getRelType()) {
case QueryRelType::NON_RECURSIVE: {
    appendNonRecursiveExtend(...);
} break;
case QueryRelType::VARIABLE_LENGTH_WALK:
case QueryRelType::VARIABLE_LENGTH_TRAIL:
case QueryRelType::VARIABLE_LENGTH_ACYCLIC: {
    appendRecursiveExtend(...);  // Always goes here, even for [*2]
} break;
```

**Missing logic:**
- Detect when `lowerBound == upperBound` (fixed length like `[*2]`)
- Detect when length is small (≤ 3-5 hops)
- Rewrite to sequential extends when beneficial

### 4. No Join Pushdown for Selective Patterns (Case 2)

**Location:** `src/planner/plan/append_extend.cpp:99-165` + join planning

**Issue:** For query `MATCH (:A)-[*2]->(:B)<-(:C)`:

1. Planner executes recursive extend for **all** :A nodes → :B destinations
2. Then joins result with `(:B)<-(:C)` (33 rows)
3. Discards most results

**Optimal execution should:**
1. Execute `(:B)<-(:C)` first (33 :B nodes)
2. Pass those 33 :B nodes as output mask to recursive extend
3. Only compute paths from :A that reach those specific 33 :B nodes

**Existing infrastructure:**
- `RecursiveExtendSharedState` has `getOutputNodeMaskMap()` (recursive_extend.cpp:90)
- Semi-mask support exists (line 124: `getOutputNodeMaskMap()`)
- Just not utilized for join optimization

---

## Performance Impact Analysis

### Current Cost Model (cost_model.cpp:12-29)

**Non-Recursive Extend:**
```cpp
cost = childCost + childCardinality  // Simple linear cost
```

**Recursive Extend with Hash Join:**
```cpp
cost = probeCost + buildCost + probeCardinality +
       (BUILD_PENALTY * buildCardinality)
```

For Case 1:
- Non-recursive: ~26ms (direct extends)
- Recursive: ~28.5s (BFS + hash join)
- **Hash join overhead alone:** ~200k nodes × BUILD_PENALTY
- **BFS overhead:** 200k source nodes × 2 iterations × frontier management

For Case 2:
- Should filter to 33 :B nodes first
- Instead processes all :A → :B paths then filters
- **Wasted work:** ~40k paths computed, 1,113 kept (96% discarded)

---

## Implementation Roadmap

### Phase 1: Fixed-Length Path Fast Path (High Priority)

**Goal:** Achieve 1000x speedup for Case 1

**Approach:** Add query rewrite optimization

**Files to modify:**
1. `src/planner/plan/append_extend.cpp`
2. `src/include/planner/planner.h`
3. New file: `src/planner/plan/append_fixed_length_extend.cpp`

**Implementation steps:**

1. **Add detection logic in `appendRecursiveExtend()`:**
```cpp
void Planner::appendRecursiveExtend(...) {
    auto bindData = recursiveInfo->bindData.get();

    // OPTIMIZATION: Rewrite fixed-length paths as sequential extends
    constexpr uint16_t MAX_REWRITE_LENGTH = 3;
    if (bindData->lowerBound == bindData->upperBound &&
        bindData->lowerBound > 0 &&
        bindData->lowerBound <= MAX_REWRITE_LENGTH) {
        appendFixedLengthPathAsSequentialExtends(boundNode, nbrNode, rel,
            direction, bindData->lowerBound, plan);
        return;
    }
    // ... continue with recursive extend
}
```

2. **Implement `appendFixedLengthPathAsSequentialExtends()`:**

**Challenge:** Need to create intermediate node expressions during planning

**Solution:** Use the approach from `createPathRelPropertyScanPlan()` (append_extend.cpp:172-180):
```cpp
void Planner::appendFixedLengthPathAsSequentialExtends(
    const std::shared_ptr<NodeExpression>& boundNode,
    const std::shared_ptr<NodeExpression>& nbrNode,
    const std::shared_ptr<RelExpression>& rel,
    ExtendDirection direction,
    uint16_t pathLength,
    LogicalPlan& plan) {

    auto recursiveInfo = rel->getRecursiveInfo();
    bool extendFromSource = *boundNode == *rel->getSrcNode();

    // Create intermediate nodes (reuse rel->nodeCopy pattern)
    std::vector<std::shared_ptr<NodeExpression>> intermediateNodes;
    intermediateNodes.push_back(boundNode);

    for (uint16_t i = 1; i < pathLength; ++i) {
        // Clone recursiveInfo->nodeCopy for each intermediate hop
        auto intermediateNode = std::make_shared<NodeExpression>(
            recursiveInfo->nodeCopy->getDataType(),
            recursiveInfo->nodeCopy->getUniqueName() + "_hop" + std::to_string(i),
            recursiveInfo->nodeCopy->getVariableName(),
            recursiveInfo->nodeCopy->getEntries()
        );
        intermediateNodes.push_back(intermediateNode);
    }
    intermediateNodes.push_back(nbrNode);

    // Chain sequential extends
    for (uint16_t i = 0; i < pathLength; ++i) {
        appendNonRecursiveExtend(
            intermediateNodes[i],      // boundNode for this hop
            intermediateNodes[i + 1],   // nbrNode for this hop
            recursiveInfo->rel,         // Use inner rel from recursive info
            direction,
            extendFromSource,
            {},  // No properties needed for intermediate hops
            plan
        );
    }

    // TODO: Handle path collection if needed (for RETURN path syntax)
    // For COUNT(*) queries, this is unnecessary
}
```

3. **Update cost model:**
```cpp
// In cost_model.cpp
uint64_t CostModel::computeFixedLengthExtendCost(const LogicalPlan& childPlan,
                                                   uint16_t pathLength) {
    // Cost = base + (childCardinality × pathLength)
    return childPlan.getCost() + (childPlan.getCardinality() * pathLength);
}
```

**Expected impact:**
- Case 1: 28.5s → ~26ms (1000x improvement)
- No regression on variable-length queries (only affects fixed-length)

**Testing:**
```cypher
-- Should use fast path (all these have fixed length):
MATCH (a)-[*2]->(b) RETURN count(*);
MATCH (a)-[*3]->(b) RETURN count(*);
MATCH (a)-[*1]->(b) RETURN count(*);  // Edge case: length 1

-- Should still use recursive extend:
MATCH (a)-[*1..3]->(b) RETURN count(*);  // Variable length
MATCH (a)-[*4]->(b) RETURN count(*);     // > MAX_REWRITE_LENGTH
```

---

### Phase 2: Semi-Mask Pushdown for Selective Joins (High Priority)

**Goal:** Achieve major speedup for Case 2

**Approach:** Push selective join conditions into recursive extend as output masks

**Files to modify:**
1. `src/planner/plan/plan_join_order.cpp` (join planning)
2. `src/planner/plan/append_extend.cpp` (extend planning)
3. `src/processor/operator/recursive_extend.cpp` (execution)

**Implementation steps:**

1. **Detect selective join patterns in join planner:**

In `planInnerHashJoin()` (plan_join_order.cpp:278-310):
```cpp
void Planner::planInnerHashJoin(const SubqueryGraph& subgraph,
                                 const SubqueryGraph& otherSubgraph,
                                 const std::vector<std::shared_ptr<NodeExpression>>& joinNodes,
                                 bool flipPlan) {
    // NEW: Check if one side contains recursive extend
    bool leftHasRecursiveRel = subgraph.hasRecursiveRel();
    bool rightHasRecursiveRel = otherSubgraph.hasRecursiveRel();

    if (leftHasRecursiveRel || rightHasRecursiveRel) {
        // Check if the other side is highly selective
        auto selectiveSide = leftHasRecursiveRel ? otherSubgraph : subgraph;
        auto selectivePlan = context.getPlans(selectiveSide)[0];

        if (selectivePlan.getCardinality() < SELECTIVE_THRESHOLD) {
            // Plan with semi-mask pushdown
            planRecursiveExtendWithOutputMask(subgraph, otherSubgraph, joinNodes);
            return;
        }
    }

    // ... existing hash join logic
}
```

2. **Implement `planRecursiveExtendWithOutputMask()`:**
```cpp
void Planner::planRecursiveExtendWithOutputMask(
    const SubqueryGraph& recursiveSubgraph,
    const SubqueryGraph& selectiveSubgraph,
    const std::vector<std::shared_ptr<NodeExpression>>& joinNodes) {

    // 1. Execute selective side first
    auto selectivePlan = context.getPlans(selectiveSubgraph)[0].copy();

    // 2. Create semi-mask from selective results
    auto maskPlan = LogicalPlan();
    appendNodeSemiMask(SemiMaskTargetType::RECURSIVE_EXTEND_OUTPUT_NODE,
                       *joinNodes[0], selectivePlan, maskPlan);

    // 3. Execute recursive extend with output mask
    auto recursivePlan = context.getPlans(recursiveSubgraph)[0].copy();
    // TODO: Attach mask to RecursiveExtendSharedState

    // 4. Results are pre-filtered, just merge
    appendMerge(recursivePlan, selectivePlan, plan);
}
```

3. **Extend RecursiveExtend to use output masks:**

Currently unused but infrastructure exists:
```cpp
// In recursive_extend.cpp:124
sharedState->getOutputNodeMaskMap()  // Already available!
```

Modify `VarLenJoinsEdgeCompute::edgeCompute()` (variable_length_path.cpp:60-75):
```cpp
std::vector<nodeID_t> edgeCompute(nodeID_t boundNodeID,
                                   graph::NbrScanState::Chunk& chunk,
                                   bool fwdEdge) override {
    std::vector<nodeID_t> activeNodes;
    chunk.forEach([&](auto neighbors, auto propertyVectors, auto i) {
        auto nbrNodeID = neighbors[i];

        // NEW: Check output mask before adding to frontier
        if (outputNodeMask != nullptr &&
            !outputNodeMask->isNodeMasked(nbrNodeID)) {
            return;  // Skip this neighbor, not in target set
        }

        // ... existing path tracking logic
        activeNodes.push_back(nbrNodeID);
    });
    return activeNodes;
}
```

**Expected impact:**
- Case 2: 220s → ~100ms (2200x improvement)
- Early termination when reaching target nodes
- Significantly less path materialization

---

### Phase 3: Remove Redundant Hash Join (Medium Priority)

**Goal:** Eliminate 20-30% overhead from hash join

**Challenge:** Hash join is NOT redundant - it merges two separate pipelines:
- GDS pipeline (recursive extend results)
- Input scan pipeline (source node properties)

**Current architecture requires it**

**Approach:** Refactor to unified pipeline

**Files to modify:**
1. `src/processor/operator/recursive_extend.cpp`
2. `src/planner/plan/append_extend.cpp`

**Implementation:**

1. **Embed input node properties in RecursiveExtend operator:**
```cpp
class RecursiveExtend {
    // NEW: Store input node property expressions
    expression_vector inputNodeProperties;

    void executeInternal(ExecutionContext* context) {
        // ... existing source node iteration
        for (auto& tableID : graph->getNodeTableIDs()) {
            for (auto offset = 0u; offset < maxOffset; ++offset) {
                auto sourceNodeID = nodeID_t{offset, tableID};

                // NEW: Read input node properties during iteration
                readInputNodeProperties(sourceNodeID, inputNodeProperties);

                // Existing BFS computation
                computeState->initSource(sourceNodeID);
                GDSUtils::runRecursiveJoinEdgeCompute(...);

                // NEW: Results already include input properties
                auto writer = function->getOutputWriter(...);
                writer->includeInputProperties(inputProperties);
            }
        }
    }
};
```

2. **Remove hash join from planning:**
```cpp
void Planner::appendRecursiveExtend(...) {
    // ... existing recursive extend setup

    // NEW: Pass input node properties directly to operator
    recursiveExtend->setInputNodeProperties(getProperties(*boundNode));

    // OLD: appendHashJoin(joinConditions, JoinType::INNER, probePlan, plan, plan);
    // NEW: No join needed, just use probePlan directly
    plan = probePlan;
}
```

**Expected impact:**
- 20-30% overhead reduction
- Simplified query plans
- Better memory locality

**Trade-offs:**
- More complex RecursiveExtend operator
- Breaks clean separation between GDS and query execution

---

### Phase 4: Optimize Path Property Scanning (Low Priority)

**Goal:** 10-15% improvement for path-returning queries

**Current issue:** Separate scans for node and relationship properties

**Location:** `append_extend.cpp:122-141`

```cpp
// Two separate pipelines:
createPathNodePropertyScanPlan(node, nodeProjectionList, plan1);
createPathRelPropertyScanPlan(boundNode, nodeCopy, rel, direction,
                               extendFromSource, relProjectionList, plan2);
// Then merged by PathPropertyProbe
```

**Approach:** Unified property scanner

**Implementation:**
```cpp
void Planner::createUnifiedPathPropertyScanPlan(
    const std::shared_ptr<NodeExpression>& node,
    const std::shared_ptr<RelExpression>& rel,
    const expression_vector& nodeProperties,
    const expression_vector& relProperties,
    ExtendDirection direction,
    LogicalPlan& plan) {

    // Single pipeline that scans both node and rel properties together
    appendScanNodeTable(node->getInternalID(), node->getTableIDs(),
                        nodeProperties, plan);

    if (!relProperties.empty()) {
        // Extend and collect rel properties in same operator
        auto combinedProps = nodeProperties;
        combinedProps.insert(combinedProps.end(),
                            relProperties.begin(), relProperties.end());
        appendNonRecursiveExtend(node, nodeCopy, rel, direction,
                                 extendFromSource, combinedProps, plan);
    }
}
```

**Expected impact:**
- 10-15% for path-returning queries
- No impact on COUNT(*) queries (properties not scanned)

---

## Configuration and Tuning

### Proposed Configuration Options

Add to planner configuration:
```cpp
struct PlannerConfig {
    // Phase 1: Fixed-length path rewrite
    uint16_t maxFixedLengthRewrite = 3;
    bool enableFixedLengthRewrite = true;

    // Phase 2: Semi-mask pushdown
    cardinality_t selectiveJoinThreshold = 1000;
    bool enableSemiMaskPushdown = true;

    // Phase 3: Unified pipeline
    bool enableUnifiedRecursivePipeline = false;  // Experimental
};
```

### Performance Testing Plan

**Benchmark queries:**
```cypher
-- Fixed-length (Phase 1 target)
MATCH (a:A)-[*2]->(b:B) RETURN count(*);
MATCH (a:A)-[*3]->(b:B) RETURN count(*);

-- Selective join (Phase 2 target)
MATCH (a:A)-[*2]->(b:B)<-(c:C) WHERE c.prop = 'rare' RETURN count(*);

-- Variable-length (ensure no regression)
MATCH (a:A)-[*1..3]->(b:B) RETURN count(*);
MATCH (a:A)-[*..5]->(b:B) RETURN count(*);

-- Path return (Phase 4 target)
MATCH p = (a:A)-[*2]->(b:B) RETURN p LIMIT 100;
```

**Metrics to track:**
- Execution time
- Memory usage
- Number of intermediate results materialized
- Hash table sizes
- Frontier sizes (for recursive extends)

---

## References

### Key Files
- **Planning:** `src/planner/plan/append_extend.cpp`
- **Execution:** `src/processor/operator/recursive_extend.cpp`
- **Algorithm:** `src/function/gds/variable_length_path.cpp`
- **Cost Model:** `src/planner/join_order/cost_model.cpp`
- **Join Planning:** `src/planner/plan/plan_join_order.cpp`

### Related Data Structures
- **RJBindData:** `src/include/function/gds/rec_joins.h:14-42`
  - Contains `lowerBound`, `upperBound` for detection
- **RecursiveInfo:** `src/include/binder/expression/rel_expression.h:20-42`
  - Node/rel projection lists, predicates
- **BFS Graph:** `src/include/function/gds/bfs_graph.h`
  - Parent tracking for path reconstruction
- **Frontier:** `src/include/function/gds/gds_frontier.h`
  - Dense/sparse dynamic switching

### Existing Optimizations to Learn From
- **INL Join:** `plan_join_order.cpp:514-551` (`tryPlanINLJoin`)
  - Detects sequential scans and avoids hash joins
  - Similar pattern could apply to fixed-length paths
- **Semi-Mask:** `recursive_extend.cpp:90-91`
  - Infrastructure exists, just needs join integration
- **Property Scan:** `append_extend.cpp:172-180`
  - Shows how to create auxiliary node expressions

---

## Migration and Compatibility

### Backward Compatibility

All optimizations are **query-plan level only** - no changes to:
- Cypher syntax
- Query semantics
- Result correctness

Users should see:
- Faster queries (no behavioral changes)
- Identical result sets
- Same error messages

### Testing Strategy

1. **Correctness tests:**
   - Ensure optimized and non-optimized paths produce identical results
   - Test edge cases: length 0, length 1, very long paths
   - Test all path semantics: WALK, TRAIL, ACYCLIC

2. **Performance tests:**
   - Benchmark suite with various graph sizes
   - Test both improvements and no-regression cases
   - Memory usage profiling

3. **Integration tests:**
   - Existing test suite should pass unchanged
   - Add specific tests for optimization triggers

---

## Implementation Priority

**Priority 1 (Highest Impact):**
- Phase 1: Fixed-length path rewrite
  - Solves Case 1 (1000x improvement)
  - Clean, self-contained change
  - Low risk

**Priority 2:**
- Phase 2: Semi-mask pushdown
  - Solves Case 2 (2200x improvement)
  - Moderate complexity
  - Reuses existing infrastructure

**Priority 3:**
- Phase 3: Remove hash join
  - 20-30% incremental improvement
  - Higher complexity, architectural change
  - Can be deferred

**Priority 4:**
- Phase 4: Property scanning
  - Small impact (10-15%)
  - Only affects path-returning queries
  - Nice-to-have optimization

---

## Estimated Effort

- **Phase 1:** 2-3 days (investigation + implementation + testing)
- **Phase 2:** 3-5 days (requires join planner changes)
- **Phase 3:** 5-7 days (architectural refactoring)
- **Phase 4:** 1-2 days (straightforward optimization)

**Total for full implementation:** 11-17 days

**Recommendation:** Start with Phase 1 (quick win), then Phase 2 if needed.
