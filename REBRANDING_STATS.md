# Rebranding Progress Statistics

*Generated: $(date)*

## ✅ Completed Directories (0 remaining references)

### 1. Extension Folder
- **Status**: ✅ Complete
- **Key Changes**: LLM docs URLs, Neo4j functions, test file extensions (.kuzu_extension → .ryu_extension)

### 2. Examples Folder
- **Status**: ✅ Complete
- **Key Changes**: C/C++/Rust API updates, package names, imports

### 3. Benchmark Folder
- **Status**: ✅ Complete
- **Key Changes**: Python imports, API calls, function names, database files (.kuzu → .ryu)

### 4. Src Folder
- **Status**: ✅ Complete (excluding intentional C API and vendored libs)
- **Key Changes**: Class names, constants, extension config, URLs, documentation
- **Intentionally NOT changed**:
  - C API types (have ryu_* aliases)
  - Vendored: kuzu_parquet, kuzu_apache
  - Magic bytes "KUZU" (backward compatibility)

## 📋 Pending Directories

### 1. Scripts Folder ⚠️
- **Total References**: ~217
- **Priority**: HIGH (infrastructure critical)
- **Sample issues**:
  - `kuzu.h` file references
  - `kuzu_shell` binary names
  - `KUZU_ROOT` variable names
  - Build script paths

### 2. Dataset Folder
- **Total References**: ~0
- **Priority**: LOW
- **Status**: Verify if any test data needs updates

### 3. Test Folder
- **Total References**: ~0 (from initial scan)
- **Priority**: MEDIUM
- **Status**: Needs verification - may have test files with embedded kuzu strings

### 4. Tools Folder
- **Total References**: ~0 (from initial scan)
- **Priority**: MEDIUM
- **Status**: Needs deeper analysis for language-specific bindings

### 5. CMake Files
- **Files with references**: Many
- **Priority**: HIGH
- **Common issues**:
  - Project names
  - Target names
  - Install paths
  - Package configurations

### 6. Root Documentation
- **Files**: README.md, CONTRIBUTING.md, etc.
- **Priority**: HIGH (user-facing)
- **Status**: Needs systematic update

## 📊 Breakdown by Type

| Category | References | Action |
|----------|-----------|---------|
| C API types | ~800+ | ✅ Keep (have aliases) |
| Vendored libs | ~100+ | ✅ Keep (third-party) |
| Scripts | ~217 | ⚠️ UPDATE |
| CMake files | ~50+ | ⚠️ UPDATE |
| Root docs | ~30+ | ⚠️ UPDATE |
| Dataset | ~0 | ✓ Verify |
| Tests | ~0 | ✓ Verify |
| Tools | ~0 | ✓ Verify |

## 🎯 Recommended Action Plan

1. **Scripts** - Critical for builds (217 refs)
2. **CMake** - Build system configuration
3. **Root Docs** - User-facing (README, etc.)
4. **Tools** - Deep dive into language bindings
5. **Tests** - Verify test file content
6. **Dataset** - Verify if updates needed

## 📝 Quick Reference Guide

### What to Change:
- ✅ User-facing strings and messages
- ✅ Documentation and comments
- ✅ URLs: kuzudb.com → ryugraph.com
- ✅ Class/function names in application code
- ✅ File/directory names
- ✅ Package names
- ✅ Binary/executable names

### What NOT to Change:
- ❌ C API types: kuzu_value, kuzu_state, etc. (have ryu_* aliases)
- ❌ Vendored namespaces: kuzu_parquet, kuzu_apache
- ❌ Storage magic bytes: "KUZU"
- ❌ Internal implementation names (unless user-facing)

## 🔍 Search Commands

```bash
# Count references in a directory
grep -r "kuzu\|Kuzu\|KUZU" <directory> --include="*.ext" | wc -l

# Find files with references
grep -rl "kuzu\|Kuzu\|KUZU" <directory> --include="*.ext"

# Exclude C API and vendored
grep -r "kuzu" src | grep -v "kuzu_parquet\|kuzu_apache\|kuzu_value\|kuzu_state"
```
