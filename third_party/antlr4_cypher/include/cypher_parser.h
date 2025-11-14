
// Generated from Cypher.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  CypherParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, T__34 = 35, T__35 = 36, T__36 = 37, T__37 = 38, 
    T__38 = 39, T__39 = 40, T__40 = 41, T__41 = 42, T__42 = 43, T__43 = 44, 
    ACYCLIC = 45, ANY = 46, ADD = 47, ALL = 48, ALTER = 49, AND = 50, AS = 51, 
    ASC = 52, ASCENDING = 53, ATTACH = 54, BEGIN = 55, BY = 56, CALL = 57, 
    CASE = 58, CAST = 59, CHECKPOINT = 60, COLUMN = 61, COMMENT = 62, COMMIT = 63, 
    COMMIT_SKIP_CHECKPOINT = 64, CONTAINS = 65, COPY = 66, COUNT = 67, CREATE = 68, 
    CYCLE = 69, DATABASE = 70, DBTYPE = 71, DEFAULT = 72, DELETE = 73, DESC = 74, 
    DESCENDING = 75, DETACH = 76, DISTINCT = 77, DROP = 78, ELSE = 79, END = 80, 
    ENDS = 81, EXISTS = 82, EXPLAIN = 83, EXPORT = 84, EXTENSION = 85, FALSE = 86, 
    FROM = 87, FORCE = 88, GLOB = 89, GRAPH = 90, GROUP = 91, HEADERS = 92, 
    HINT = 93, IMPORT = 94, IF = 95, IN = 96, INCREMENT = 97, INSTALL = 98, 
    IS = 99, JOIN = 100, KEY = 101, LIMIT = 102, LOAD = 103, LOGICAL = 104, 
    MACRO = 105, MATCH = 106, MAXVALUE = 107, MERGE = 108, MINVALUE = 109, 
    MULTI_JOIN = 110, NO = 111, NODE = 112, NOT = 113, NONE = 114, NULL_ = 115, 
    ON = 116, ONLY = 117, OPTIONAL = 118, OR = 119, ORDER = 120, PRIMARY = 121, 
    PROFILE = 122, PROJECT = 123, READ = 124, REL = 125, RENAME = 126, RETURN = 127, 
    ROLLBACK = 128, ROLLBACK_SKIP_CHECKPOINT = 129, SEQUENCE = 130, SET = 131, 
    SHORTEST = 132, START = 133, STARTS = 134, STRUCT = 135, TABLE = 136, 
    THEN = 137, TO = 138, TRAIL = 139, TRANSACTION = 140, TRUE = 141, TYPE = 142, 
    UNION = 143, UNWIND = 144, UNINSTALL = 145, UPDATE = 146, USE = 147, 
    WHEN = 148, WHERE = 149, WITH = 150, WRITE = 151, WSHORTEST = 152, XOR = 153, 
    SINGLE = 154, YIELD = 155, USER = 156, PASSWORD = 157, ROLE = 158, MAP = 159, 
    DECIMAL = 160, STAR = 161, L_SKIP = 162, INVALID_NOT_EQUAL = 163, COLON = 164, 
    DOTDOT = 165, MINUS = 166, FACTORIAL = 167, StringLiteral = 168, EscapedChar = 169, 
    DecimalInteger = 170, HexLetter = 171, HexDigit = 172, Digit = 173, 
    NonZeroDigit = 174, NonZeroOctDigit = 175, ZeroDigit = 176, ExponentDecimalReal = 177, 
    RegularDecimalReal = 178, UnescapedSymbolicName = 179, IdentifierStart = 180, 
    IdentifierPart = 181, EscapedSymbolicName = 182, SP = 183, WHITESPACE = 184, 
    CypherComment = 185, Unknown = 186
  };

  enum {
    RuleKu_Statements = 0, RuleOC_Cypher = 1, RuleOC_Statement = 2, RuleRU_CopyFrom = 3, 
    RuleRU_ColumnNames = 4, RuleRU_ScanSource = 5, RuleRU_CopyFromByColumn = 6, 
    RuleRU_CopyTO = 7, RuleRU_ExportDatabase = 8, RuleRU_ImportDatabase = 9, 
    RuleRU_AttachDatabase = 10, RuleRU_Option = 11, RuleRU_Options = 12, 
    RuleRU_DetachDatabase = 13, RuleRU_UseDatabase = 14, RuleRU_StandaloneCall = 15, 
    RuleRU_CommentOn = 16, RuleRU_CreateMacro = 17, RuleRU_PositionalArgs = 18, 
    RuleRU_DefaultArg = 19, RuleRU_FilePaths = 20, RuleRU_IfNotExists = 21, 
    RuleRU_CreateNodeTable = 22, RuleRU_CreateRelTable = 23, RuleRU_FromToConnections = 24, 
    RuleRU_FromToConnection = 25, RuleRU_CreateSequence = 26, RuleRU_CreateType = 27, 
    RuleRU_SequenceOptions = 28, RuleRU_WithPasswd = 29, RuleRU_CreateUser = 30, 
    RuleRU_CreateRole = 31, RuleRU_IncrementBy = 32, RuleRU_MinValue = 33, 
    RuleRU_MaxValue = 34, RuleRU_StartWith = 35, RuleRU_Cycle = 36, RuleRU_IfExists = 37, 
    RuleRU_Drop = 38, RuleRU_AlterTable = 39, RuleRU_AlterOptions = 40, 
    RuleRU_AddProperty = 41, RuleRU_Default = 42, RuleRU_DropProperty = 43, 
    RuleRU_RenameTable = 44, RuleRU_RenameProperty = 45, RuleRU_AddFromToConnection = 46, 
    RuleRU_DropFromToConnection = 47, RuleRU_ColumnDefinitions = 48, RuleRU_ColumnDefinition = 49, 
    RuleRU_PropertyDefinitions = 50, RuleRU_PropertyDefinition = 51, RuleRU_CreateNodeConstraint = 52, 
    RuleRU_UnionType = 53, RuleRU_StructType = 54, RuleRU_MapType = 55, 
    RuleRU_DecimalType = 56, RuleRU_DataType = 57, RuleRU_ListIdentifiers = 58, 
    RuleRU_ListIdentifier = 59, RuleOC_AnyCypherOption = 60, RuleOC_Explain = 61, 
    RuleOC_Profile = 62, RuleRU_Transaction = 63, RuleRU_Extension = 64, 
    RuleRU_LoadExtension = 65, RuleRU_InstallExtension = 66, RuleRU_UninstallExtension = 67, 
    RuleRU_UpdateExtension = 68, RuleOC_Query = 69, RuleOC_RegularQuery = 70, 
    RuleOC_Union = 71, RuleOC_SingleQuery = 72, RuleOC_SinglePartQuery = 73, 
    RuleOC_MultiPartQuery = 74, RuleRU_QueryPart = 75, RuleOC_UpdatingClause = 76, 
    RuleOC_ReadingClause = 77, RuleRU_LoadFrom = 78, RuleOC_YieldItem = 79, 
    RuleOC_YieldItems = 80, RuleRU_InQueryCall = 81, RuleOC_Match = 82, 
    RuleRU_Hint = 83, RuleRU_JoinNode = 84, RuleOC_Unwind = 85, RuleOC_Create = 86, 
    RuleOC_Merge = 87, RuleOC_MergeAction = 88, RuleOC_Set = 89, RuleOC_SetItem = 90, 
    RuleOC_Delete = 91, RuleOC_With = 92, RuleOC_Return = 93, RuleOC_ProjectionBody = 94, 
    RuleOC_ProjectionItems = 95, RuleOC_ProjectionItem = 96, RuleOC_Order = 97, 
    RuleOC_Skip = 98, RuleOC_Limit = 99, RuleOC_SortItem = 100, RuleOC_Where = 101, 
    RuleOC_Pattern = 102, RuleOC_PatternPart = 103, RuleOC_AnonymousPatternPart = 104, 
    RuleOC_PatternElement = 105, RuleOC_NodePattern = 106, RuleOC_PatternElementChain = 107, 
    RuleOC_RelationshipPattern = 108, RuleOC_RelationshipDetail = 109, RuleRU_Properties = 110, 
    RuleOC_RelationshipTypes = 111, RuleOC_NodeLabels = 112, RuleRU_RecursiveDetail = 113, 
    RuleRU_RecursiveType = 114, RuleOC_RangeLiteral = 115, RuleRU_RecursiveComprehension = 116, 
    RuleRU_RecursiveProjectionItems = 117, RuleOC_LowerBound = 118, RuleOC_UpperBound = 119, 
    RuleOC_LabelName = 120, RuleOC_RelTypeName = 121, RuleOC_Expression = 122, 
    RuleOC_OrExpression = 123, RuleOC_XorExpression = 124, RuleOC_AndExpression = 125, 
    RuleOC_NotExpression = 126, RuleOC_ComparisonExpression = 127, RuleRU_ComparisonOperator = 128, 
    RuleRU_BitwiseOrOperatorExpression = 129, RuleRU_BitwiseAndOperatorExpression = 130, 
    RuleRU_BitShiftOperatorExpression = 131, RuleRU_BitShiftOperator = 132, 
    RuleOC_AddOrSubtractExpression = 133, RuleRU_AddOrSubtractOperator = 134, 
    RuleOC_MultiplyDivideModuloExpression = 135, RuleRU_MultiplyDivideModuloOperator = 136, 
    RuleOC_PowerOfExpression = 137, RuleOC_StringListNullOperatorExpression = 138, 
    RuleOC_ListOperatorExpression = 139, RuleOC_StringOperatorExpression = 140, 
    RuleOC_RegularExpression = 141, RuleOC_NullOperatorExpression = 142, 
    RuleOC_UnaryAddSubtractOrFactorialExpression = 143, RuleOC_PropertyOrLabelsExpression = 144, 
    RuleOC_Atom = 145, RuleOC_Quantifier = 146, RuleOC_FilterExpression = 147, 
    RuleOC_IdInColl = 148, RuleOC_Literal = 149, RuleOC_BooleanLiteral = 150, 
    RuleOC_ListLiteral = 151, RuleRU_ListEntry = 152, RuleRU_StructLiteral = 153, 
    RuleRU_StructField = 154, RuleOC_ParenthesizedExpression = 155, RuleOC_FunctionInvocation = 156, 
    RuleOC_FunctionName = 157, RuleRU_FunctionParameter = 158, RuleRU_LambdaParameter = 159, 
    RuleRU_LambdaVars = 160, RuleOC_PathPatterns = 161, RuleOC_ExistCountSubquery = 162, 
    RuleOC_PropertyLookup = 163, RuleOC_CaseExpression = 164, RuleOC_CaseAlternative = 165, 
    RuleOC_Variable = 166, RuleOC_NumberLiteral = 167, RuleOC_Parameter = 168, 
    RuleOC_PropertyExpression = 169, RuleOC_PropertyKeyName = 170, RuleOC_IntegerLiteral = 171, 
    RuleOC_DoubleLiteral = 172, RuleOC_SchemaName = 173, RuleOC_SymbolicName = 174, 
    RuleRU_NonReservedKeywords = 175, RuleOC_LeftArrowHead = 176, RuleOC_RightArrowHead = 177, 
    RuleOC_Dash = 178
  };

  explicit CypherParser(antlr4::TokenStream *input);

  CypherParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~CypherParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class Ku_StatementsContext;
  class OC_CypherContext;
  class OC_StatementContext;
  class RU_CopyFromContext;
  class RU_ColumnNamesContext;
  class RU_ScanSourceContext;
  class RU_CopyFromByColumnContext;
  class RU_CopyTOContext;
  class RU_ExportDatabaseContext;
  class RU_ImportDatabaseContext;
  class RU_AttachDatabaseContext;
  class RU_OptionContext;
  class RU_OptionsContext;
  class RU_DetachDatabaseContext;
  class RU_UseDatabaseContext;
  class RU_StandaloneCallContext;
  class RU_CommentOnContext;
  class RU_CreateMacroContext;
  class RU_PositionalArgsContext;
  class RU_DefaultArgContext;
  class RU_FilePathsContext;
  class RU_IfNotExistsContext;
  class RU_CreateNodeTableContext;
  class RU_CreateRelTableContext;
  class RU_FromToConnectionsContext;
  class RU_FromToConnectionContext;
  class RU_CreateSequenceContext;
  class RU_CreateTypeContext;
  class RU_SequenceOptionsContext;
  class RU_WithPasswdContext;
  class RU_CreateUserContext;
  class RU_CreateRoleContext;
  class RU_IncrementByContext;
  class RU_MinValueContext;
  class RU_MaxValueContext;
  class RU_StartWithContext;
  class RU_CycleContext;
  class RU_IfExistsContext;
  class RU_DropContext;
  class RU_AlterTableContext;
  class RU_AlterOptionsContext;
  class RU_AddPropertyContext;
  class RU_DefaultContext;
  class RU_DropPropertyContext;
  class RU_RenameTableContext;
  class RU_RenamePropertyContext;
  class RU_AddFromToConnectionContext;
  class RU_DropFromToConnectionContext;
  class RU_ColumnDefinitionsContext;
  class RU_ColumnDefinitionContext;
  class RU_PropertyDefinitionsContext;
  class RU_PropertyDefinitionContext;
  class RU_CreateNodeConstraintContext;
  class RU_UnionTypeContext;
  class RU_StructTypeContext;
  class RU_MapTypeContext;
  class RU_DecimalTypeContext;
  class RU_DataTypeContext;
  class RU_ListIdentifiersContext;
  class RU_ListIdentifierContext;
  class OC_AnyCypherOptionContext;
  class OC_ExplainContext;
  class OC_ProfileContext;
  class RU_TransactionContext;
  class RU_ExtensionContext;
  class RU_LoadExtensionContext;
  class RU_InstallExtensionContext;
  class RU_UninstallExtensionContext;
  class RU_UpdateExtensionContext;
  class OC_QueryContext;
  class OC_RegularQueryContext;
  class OC_UnionContext;
  class OC_SingleQueryContext;
  class OC_SinglePartQueryContext;
  class OC_MultiPartQueryContext;
  class RU_QueryPartContext;
  class OC_UpdatingClauseContext;
  class OC_ReadingClauseContext;
  class RU_LoadFromContext;
  class OC_YieldItemContext;
  class OC_YieldItemsContext;
  class RU_InQueryCallContext;
  class OC_MatchContext;
  class RU_HintContext;
  class RU_JoinNodeContext;
  class OC_UnwindContext;
  class OC_CreateContext;
  class OC_MergeContext;
  class OC_MergeActionContext;
  class OC_SetContext;
  class OC_SetItemContext;
  class OC_DeleteContext;
  class OC_WithContext;
  class OC_ReturnContext;
  class OC_ProjectionBodyContext;
  class OC_ProjectionItemsContext;
  class OC_ProjectionItemContext;
  class OC_OrderContext;
  class OC_SkipContext;
  class OC_LimitContext;
  class OC_SortItemContext;
  class OC_WhereContext;
  class OC_PatternContext;
  class OC_PatternPartContext;
  class OC_AnonymousPatternPartContext;
  class OC_PatternElementContext;
  class OC_NodePatternContext;
  class OC_PatternElementChainContext;
  class OC_RelationshipPatternContext;
  class OC_RelationshipDetailContext;
  class RU_PropertiesContext;
  class OC_RelationshipTypesContext;
  class OC_NodeLabelsContext;
  class RU_RecursiveDetailContext;
  class RU_RecursiveTypeContext;
  class OC_RangeLiteralContext;
  class RU_RecursiveComprehensionContext;
  class RU_RecursiveProjectionItemsContext;
  class OC_LowerBoundContext;
  class OC_UpperBoundContext;
  class OC_LabelNameContext;
  class OC_RelTypeNameContext;
  class OC_ExpressionContext;
  class OC_OrExpressionContext;
  class OC_XorExpressionContext;
  class OC_AndExpressionContext;
  class OC_NotExpressionContext;
  class OC_ComparisonExpressionContext;
  class RU_ComparisonOperatorContext;
  class RU_BitwiseOrOperatorExpressionContext;
  class RU_BitwiseAndOperatorExpressionContext;
  class RU_BitShiftOperatorExpressionContext;
  class RU_BitShiftOperatorContext;
  class OC_AddOrSubtractExpressionContext;
  class RU_AddOrSubtractOperatorContext;
  class OC_MultiplyDivideModuloExpressionContext;
  class RU_MultiplyDivideModuloOperatorContext;
  class OC_PowerOfExpressionContext;
  class OC_StringListNullOperatorExpressionContext;
  class OC_ListOperatorExpressionContext;
  class OC_StringOperatorExpressionContext;
  class OC_RegularExpressionContext;
  class OC_NullOperatorExpressionContext;
  class OC_UnaryAddSubtractOrFactorialExpressionContext;
  class OC_PropertyOrLabelsExpressionContext;
  class OC_AtomContext;
  class OC_QuantifierContext;
  class OC_FilterExpressionContext;
  class OC_IdInCollContext;
  class OC_LiteralContext;
  class OC_BooleanLiteralContext;
  class OC_ListLiteralContext;
  class RU_ListEntryContext;
  class RU_StructLiteralContext;
  class RU_StructFieldContext;
  class OC_ParenthesizedExpressionContext;
  class OC_FunctionInvocationContext;
  class OC_FunctionNameContext;
  class RU_FunctionParameterContext;
  class RU_LambdaParameterContext;
  class RU_LambdaVarsContext;
  class OC_PathPatternsContext;
  class OC_ExistCountSubqueryContext;
  class OC_PropertyLookupContext;
  class OC_CaseExpressionContext;
  class OC_CaseAlternativeContext;
  class OC_VariableContext;
  class OC_NumberLiteralContext;
  class OC_ParameterContext;
  class OC_PropertyExpressionContext;
  class OC_PropertyKeyNameContext;
  class OC_IntegerLiteralContext;
  class OC_DoubleLiteralContext;
  class OC_SchemaNameContext;
  class OC_SymbolicNameContext;
  class RU_NonReservedKeywordsContext;
  class OC_LeftArrowHeadContext;
  class OC_RightArrowHeadContext;
  class OC_DashContext; 

  class  Ku_StatementsContext : public antlr4::ParserRuleContext {
  public:
    Ku_StatementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OC_CypherContext *> oC_Cypher();
    OC_CypherContext* oC_Cypher(size_t i);
    antlr4::tree::TerminalNode *EOF();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  Ku_StatementsContext* ku_Statements();

  class  OC_CypherContext : public antlr4::ParserRuleContext {
  public:
    OC_CypherContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_StatementContext *oC_Statement();
    OC_AnyCypherOptionContext *oC_AnyCypherOption();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  OC_CypherContext* oC_Cypher();

  class  OC_StatementContext : public antlr4::ParserRuleContext {
  public:
    OC_StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_QueryContext *oC_Query();
    RU_CreateUserContext *rU_CreateUser();
    RU_CreateRoleContext *rU_CreateRole();
    RU_CreateNodeTableContext *rU_CreateNodeTable();
    RU_CreateRelTableContext *rU_CreateRelTable();
    RU_CreateSequenceContext *rU_CreateSequence();
    RU_CreateTypeContext *rU_CreateType();
    RU_DropContext *rU_Drop();
    RU_AlterTableContext *rU_AlterTable();
    RU_CopyFromContext *rU_CopyFrom();
    RU_CopyFromByColumnContext *rU_CopyFromByColumn();
    RU_CopyTOContext *rU_CopyTO();
    RU_StandaloneCallContext *rU_StandaloneCall();
    RU_CreateMacroContext *rU_CreateMacro();
    RU_CommentOnContext *rU_CommentOn();
    RU_TransactionContext *rU_Transaction();
    RU_ExtensionContext *rU_Extension();
    RU_ExportDatabaseContext *rU_ExportDatabase();
    RU_ImportDatabaseContext *rU_ImportDatabase();
    RU_AttachDatabaseContext *rU_AttachDatabase();
    RU_DetachDatabaseContext *rU_DetachDatabase();
    RU_UseDatabaseContext *rU_UseDatabase();

   
  };

  OC_StatementContext* oC_Statement();

  class  RU_CopyFromContext : public antlr4::ParserRuleContext {
  public:
    RU_CopyFromContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COPY();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_SchemaNameContext *oC_SchemaName();
    antlr4::tree::TerminalNode *FROM();
    RU_ScanSourceContext *rU_ScanSource();
    RU_ColumnNamesContext *rU_ColumnNames();
    RU_OptionsContext *rU_Options();

   
  };

  RU_CopyFromContext* rU_CopyFrom();

  class  RU_ColumnNamesContext : public antlr4::ParserRuleContext {
  public:
    RU_ColumnNamesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    std::vector<OC_SchemaNameContext *> oC_SchemaName();
    OC_SchemaNameContext* oC_SchemaName(size_t i);

   
  };

  RU_ColumnNamesContext* rU_ColumnNames();

  class  RU_ScanSourceContext : public antlr4::ParserRuleContext {
  public:
    RU_ScanSourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RU_FilePathsContext *rU_FilePaths();
    OC_QueryContext *oC_Query();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_ParameterContext *oC_Parameter();
    OC_VariableContext *oC_Variable();
    OC_SchemaNameContext *oC_SchemaName();
    OC_FunctionInvocationContext *oC_FunctionInvocation();

   
  };

  RU_ScanSourceContext* rU_ScanSource();

  class  RU_CopyFromByColumnContext : public antlr4::ParserRuleContext {
  public:
    RU_CopyFromByColumnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COPY();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_SchemaNameContext *oC_SchemaName();
    antlr4::tree::TerminalNode *FROM();
    std::vector<antlr4::tree::TerminalNode *> StringLiteral();
    antlr4::tree::TerminalNode* StringLiteral(size_t i);
    antlr4::tree::TerminalNode *BY();
    antlr4::tree::TerminalNode *COLUMN();

   
  };

  RU_CopyFromByColumnContext* rU_CopyFromByColumn();

  class  RU_CopyTOContext : public antlr4::ParserRuleContext {
  public:
    RU_CopyTOContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COPY();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_QueryContext *oC_Query();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *StringLiteral();
    RU_OptionsContext *rU_Options();

   
  };

  RU_CopyTOContext* rU_CopyTO();

  class  RU_ExportDatabaseContext : public antlr4::ParserRuleContext {
  public:
    RU_ExportDatabaseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXPORT();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *DATABASE();
    antlr4::tree::TerminalNode *StringLiteral();
    RU_OptionsContext *rU_Options();

   
  };

  RU_ExportDatabaseContext* rU_ExportDatabase();

  class  RU_ImportDatabaseContext : public antlr4::ParserRuleContext {
  public:
    RU_ImportDatabaseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IMPORT();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *DATABASE();
    antlr4::tree::TerminalNode *StringLiteral();

   
  };

  RU_ImportDatabaseContext* rU_ImportDatabase();

  class  RU_AttachDatabaseContext : public antlr4::ParserRuleContext {
  public:
    RU_AttachDatabaseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ATTACH();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *StringLiteral();
    antlr4::tree::TerminalNode *DBTYPE();
    OC_SymbolicNameContext *oC_SymbolicName();
    antlr4::tree::TerminalNode *AS();
    OC_SchemaNameContext *oC_SchemaName();
    RU_OptionsContext *rU_Options();

   
  };

  RU_AttachDatabaseContext* rU_AttachDatabase();

  class  RU_OptionContext : public antlr4::ParserRuleContext {
  public:
    RU_OptionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_SymbolicNameContext *oC_SymbolicName();
    OC_LiteralContext *oC_Literal();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  RU_OptionContext* rU_Option();

  class  RU_OptionsContext : public antlr4::ParserRuleContext {
  public:
    RU_OptionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RU_OptionContext *> rU_Option();
    RU_OptionContext* rU_Option(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  RU_OptionsContext* rU_Options();

  class  RU_DetachDatabaseContext : public antlr4::ParserRuleContext {
  public:
    RU_DetachDatabaseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DETACH();
    antlr4::tree::TerminalNode *SP();
    OC_SchemaNameContext *oC_SchemaName();

   
  };

  RU_DetachDatabaseContext* rU_DetachDatabase();

  class  RU_UseDatabaseContext : public antlr4::ParserRuleContext {
  public:
    RU_UseDatabaseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *USE();
    antlr4::tree::TerminalNode *SP();
    OC_SchemaNameContext *oC_SchemaName();

   
  };

  RU_UseDatabaseContext* rU_UseDatabase();

  class  RU_StandaloneCallContext : public antlr4::ParserRuleContext {
  public:
    RU_StandaloneCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CALL();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_SymbolicNameContext *oC_SymbolicName();
    OC_ExpressionContext *oC_Expression();
    OC_FunctionInvocationContext *oC_FunctionInvocation();

   
  };

  RU_StandaloneCallContext* rU_StandaloneCall();

  class  RU_CommentOnContext : public antlr4::ParserRuleContext {
  public:
    RU_CommentOnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMENT();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *ON();
    antlr4::tree::TerminalNode *TABLE();
    OC_SchemaNameContext *oC_SchemaName();
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *StringLiteral();

   
  };

  RU_CommentOnContext* rU_CommentOn();

  class  RU_CreateMacroContext : public antlr4::ParserRuleContext {
  public:
    RU_CreateMacroContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CREATE();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *MACRO();
    OC_FunctionNameContext *oC_FunctionName();
    antlr4::tree::TerminalNode *AS();
    OC_ExpressionContext *oC_Expression();
    RU_PositionalArgsContext *rU_PositionalArgs();
    std::vector<RU_DefaultArgContext *> rU_DefaultArg();
    RU_DefaultArgContext* rU_DefaultArg(size_t i);

   
  };

  RU_CreateMacroContext* rU_CreateMacro();

  class  RU_PositionalArgsContext : public antlr4::ParserRuleContext {
  public:
    RU_PositionalArgsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OC_SymbolicNameContext *> oC_SymbolicName();
    OC_SymbolicNameContext* oC_SymbolicName(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  RU_PositionalArgsContext* rU_PositionalArgs();

  class  RU_DefaultArgContext : public antlr4::ParserRuleContext {
  public:
    RU_DefaultArgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_SymbolicNameContext *oC_SymbolicName();
    antlr4::tree::TerminalNode *COLON();
    OC_LiteralContext *oC_Literal();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  RU_DefaultArgContext* rU_DefaultArg();

  class  RU_FilePathsContext : public antlr4::ParserRuleContext {
  public:
    RU_FilePathsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> StringLiteral();
    antlr4::tree::TerminalNode* StringLiteral(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *GLOB();

   
  };

  RU_FilePathsContext* rU_FilePaths();

  class  RU_IfNotExistsContext : public antlr4::ParserRuleContext {
  public:
    RU_IfNotExistsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *EXISTS();

   
  };

  RU_IfNotExistsContext* rU_IfNotExists();

  class  RU_CreateNodeTableContext : public antlr4::ParserRuleContext {
  public:
    RU_CreateNodeTableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CREATE();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *NODE();
    antlr4::tree::TerminalNode *TABLE();
    OC_SchemaNameContext *oC_SchemaName();
    RU_PropertyDefinitionsContext *rU_PropertyDefinitions();
    antlr4::tree::TerminalNode *AS();
    OC_QueryContext *oC_Query();
    RU_IfNotExistsContext *rU_IfNotExists();
    RU_CreateNodeConstraintContext *rU_CreateNodeConstraint();

   
  };

  RU_CreateNodeTableContext* rU_CreateNodeTable();

  class  RU_CreateRelTableContext : public antlr4::ParserRuleContext {
  public:
    RU_CreateRelTableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CREATE();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *REL();
    antlr4::tree::TerminalNode *TABLE();
    OC_SchemaNameContext *oC_SchemaName();
    RU_FromToConnectionsContext *rU_FromToConnections();
    antlr4::tree::TerminalNode *AS();
    OC_QueryContext *oC_Query();
    antlr4::tree::TerminalNode *GROUP();
    RU_IfNotExistsContext *rU_IfNotExists();
    antlr4::tree::TerminalNode *WITH();
    RU_OptionsContext *rU_Options();
    RU_PropertyDefinitionsContext *rU_PropertyDefinitions();
    OC_SymbolicNameContext *oC_SymbolicName();

   
  };

  RU_CreateRelTableContext* rU_CreateRelTable();

  class  RU_FromToConnectionsContext : public antlr4::ParserRuleContext {
  public:
    RU_FromToConnectionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RU_FromToConnectionContext *> rU_FromToConnection();
    RU_FromToConnectionContext* rU_FromToConnection(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  RU_FromToConnectionsContext* rU_FromToConnections();

  class  RU_FromToConnectionContext : public antlr4::ParserRuleContext {
  public:
    RU_FromToConnectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FROM();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    std::vector<OC_SchemaNameContext *> oC_SchemaName();
    OC_SchemaNameContext* oC_SchemaName(size_t i);
    antlr4::tree::TerminalNode *TO();

   
  };

  RU_FromToConnectionContext* rU_FromToConnection();

  class  RU_CreateSequenceContext : public antlr4::ParserRuleContext {
  public:
    RU_CreateSequenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CREATE();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *SEQUENCE();
    OC_SchemaNameContext *oC_SchemaName();
    RU_IfNotExistsContext *rU_IfNotExists();
    std::vector<RU_SequenceOptionsContext *> rU_SequenceOptions();
    RU_SequenceOptionsContext* rU_SequenceOptions(size_t i);

   
  };

  RU_CreateSequenceContext* rU_CreateSequence();

  class  RU_CreateTypeContext : public antlr4::ParserRuleContext {
  public:
    RU_CreateTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CREATE();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *TYPE();
    OC_SchemaNameContext *oC_SchemaName();
    antlr4::tree::TerminalNode *AS();
    RU_DataTypeContext *rU_DataType();

   
  };

  RU_CreateTypeContext* rU_CreateType();

  class  RU_SequenceOptionsContext : public antlr4::ParserRuleContext {
  public:
    RU_SequenceOptionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RU_IncrementByContext *rU_IncrementBy();
    RU_MinValueContext *rU_MinValue();
    RU_MaxValueContext *rU_MaxValue();
    RU_StartWithContext *rU_StartWith();
    RU_CycleContext *rU_Cycle();

   
  };

  RU_SequenceOptionsContext* rU_SequenceOptions();

  class  RU_WithPasswdContext : public antlr4::ParserRuleContext {
  public:
    RU_WithPasswdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *PASSWORD();
    antlr4::tree::TerminalNode *StringLiteral();

   
  };

  RU_WithPasswdContext* rU_WithPasswd();

  class  RU_CreateUserContext : public antlr4::ParserRuleContext {
  public:
    RU_CreateUserContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CREATE();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *USER();
    OC_VariableContext *oC_Variable();
    RU_IfNotExistsContext *rU_IfNotExists();
    RU_WithPasswdContext *rU_WithPasswd();

   
  };

  RU_CreateUserContext* rU_CreateUser();

  class  RU_CreateRoleContext : public antlr4::ParserRuleContext {
  public:
    RU_CreateRoleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CREATE();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *ROLE();
    OC_VariableContext *oC_Variable();
    RU_IfNotExistsContext *rU_IfNotExists();

   
  };

  RU_CreateRoleContext* rU_CreateRole();

  class  RU_IncrementByContext : public antlr4::ParserRuleContext {
  public:
    RU_IncrementByContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INCREMENT();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_IntegerLiteralContext *oC_IntegerLiteral();
    antlr4::tree::TerminalNode *BY();
    antlr4::tree::TerminalNode *MINUS();

   
  };

  RU_IncrementByContext* rU_IncrementBy();

  class  RU_MinValueContext : public antlr4::ParserRuleContext {
  public:
    RU_MinValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NO();
    antlr4::tree::TerminalNode *SP();
    antlr4::tree::TerminalNode *MINVALUE();
    OC_IntegerLiteralContext *oC_IntegerLiteral();
    antlr4::tree::TerminalNode *MINUS();

   
  };

  RU_MinValueContext* rU_MinValue();

  class  RU_MaxValueContext : public antlr4::ParserRuleContext {
  public:
    RU_MaxValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NO();
    antlr4::tree::TerminalNode *SP();
    antlr4::tree::TerminalNode *MAXVALUE();
    OC_IntegerLiteralContext *oC_IntegerLiteral();
    antlr4::tree::TerminalNode *MINUS();

   
  };

  RU_MaxValueContext* rU_MaxValue();

  class  RU_StartWithContext : public antlr4::ParserRuleContext {
  public:
    RU_StartWithContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *START();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_IntegerLiteralContext *oC_IntegerLiteral();
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *MINUS();

   
  };

  RU_StartWithContext* rU_StartWith();

  class  RU_CycleContext : public antlr4::ParserRuleContext {
  public:
    RU_CycleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CYCLE();
    antlr4::tree::TerminalNode *NO();
    antlr4::tree::TerminalNode *SP();

   
  };

  RU_CycleContext* rU_Cycle();

  class  RU_IfExistsContext : public antlr4::ParserRuleContext {
  public:
    RU_IfExistsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *SP();
    antlr4::tree::TerminalNode *EXISTS();

   
  };

  RU_IfExistsContext* rU_IfExists();

  class  RU_DropContext : public antlr4::ParserRuleContext {
  public:
    RU_DropContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DROP();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_SchemaNameContext *oC_SchemaName();
    antlr4::tree::TerminalNode *TABLE();
    antlr4::tree::TerminalNode *SEQUENCE();
    antlr4::tree::TerminalNode *MACRO();
    RU_IfExistsContext *rU_IfExists();

   
  };

  RU_DropContext* rU_Drop();

  class  RU_AlterTableContext : public antlr4::ParserRuleContext {
  public:
    RU_AlterTableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALTER();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *TABLE();
    OC_SchemaNameContext *oC_SchemaName();
    RU_AlterOptionsContext *rU_AlterOptions();

   
  };

  RU_AlterTableContext* rU_AlterTable();

  class  RU_AlterOptionsContext : public antlr4::ParserRuleContext {
  public:
    RU_AlterOptionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RU_AddPropertyContext *rU_AddProperty();
    RU_DropPropertyContext *rU_DropProperty();
    RU_RenameTableContext *rU_RenameTable();
    RU_RenamePropertyContext *rU_RenameProperty();
    RU_AddFromToConnectionContext *rU_AddFromToConnection();
    RU_DropFromToConnectionContext *rU_DropFromToConnection();

   
  };

  RU_AlterOptionsContext* rU_AlterOptions();

  class  RU_AddPropertyContext : public antlr4::ParserRuleContext {
  public:
    RU_AddPropertyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADD();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_PropertyKeyNameContext *oC_PropertyKeyName();
    RU_DataTypeContext *rU_DataType();
    RU_IfNotExistsContext *rU_IfNotExists();
    RU_DefaultContext *rU_Default();

   
  };

  RU_AddPropertyContext* rU_AddProperty();

  class  RU_DefaultContext : public antlr4::ParserRuleContext {
  public:
    RU_DefaultContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFAULT();
    antlr4::tree::TerminalNode *SP();
    OC_ExpressionContext *oC_Expression();

   
  };

  RU_DefaultContext* rU_Default();

  class  RU_DropPropertyContext : public antlr4::ParserRuleContext {
  public:
    RU_DropPropertyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DROP();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_PropertyKeyNameContext *oC_PropertyKeyName();
    RU_IfExistsContext *rU_IfExists();

   
  };

  RU_DropPropertyContext* rU_DropProperty();

  class  RU_RenameTableContext : public antlr4::ParserRuleContext {
  public:
    RU_RenameTableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RENAME();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *TO();
    OC_SchemaNameContext *oC_SchemaName();

   
  };

  RU_RenameTableContext* rU_RenameTable();

  class  RU_RenamePropertyContext : public antlr4::ParserRuleContext {
  public:
    RU_RenamePropertyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RENAME();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    std::vector<OC_PropertyKeyNameContext *> oC_PropertyKeyName();
    OC_PropertyKeyNameContext* oC_PropertyKeyName(size_t i);
    antlr4::tree::TerminalNode *TO();

   
  };

  RU_RenamePropertyContext* rU_RenameProperty();

  class  RU_AddFromToConnectionContext : public antlr4::ParserRuleContext {
  public:
    RU_AddFromToConnectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADD();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    RU_FromToConnectionContext *rU_FromToConnection();
    RU_IfNotExistsContext *rU_IfNotExists();

   
  };

  RU_AddFromToConnectionContext* rU_AddFromToConnection();

  class  RU_DropFromToConnectionContext : public antlr4::ParserRuleContext {
  public:
    RU_DropFromToConnectionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DROP();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    RU_FromToConnectionContext *rU_FromToConnection();
    RU_IfExistsContext *rU_IfExists();

   
  };

  RU_DropFromToConnectionContext* rU_DropFromToConnection();

  class  RU_ColumnDefinitionsContext : public antlr4::ParserRuleContext {
  public:
    RU_ColumnDefinitionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RU_ColumnDefinitionContext *> rU_ColumnDefinition();
    RU_ColumnDefinitionContext* rU_ColumnDefinition(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  RU_ColumnDefinitionsContext* rU_ColumnDefinitions();

  class  RU_ColumnDefinitionContext : public antlr4::ParserRuleContext {
  public:
    RU_ColumnDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_PropertyKeyNameContext *oC_PropertyKeyName();
    antlr4::tree::TerminalNode *SP();
    RU_DataTypeContext *rU_DataType();

   
  };

  RU_ColumnDefinitionContext* rU_ColumnDefinition();

  class  RU_PropertyDefinitionsContext : public antlr4::ParserRuleContext {
  public:
    RU_PropertyDefinitionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RU_PropertyDefinitionContext *> rU_PropertyDefinition();
    RU_PropertyDefinitionContext* rU_PropertyDefinition(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  RU_PropertyDefinitionsContext* rU_PropertyDefinitions();

  class  RU_PropertyDefinitionContext : public antlr4::ParserRuleContext {
  public:
    RU_PropertyDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RU_ColumnDefinitionContext *rU_ColumnDefinition();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    RU_DefaultContext *rU_Default();
    antlr4::tree::TerminalNode *PRIMARY();
    antlr4::tree::TerminalNode *KEY();

   
  };

  RU_PropertyDefinitionContext* rU_PropertyDefinition();

  class  RU_CreateNodeConstraintContext : public antlr4::ParserRuleContext {
  public:
    RU_CreateNodeConstraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PRIMARY();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *KEY();
    OC_PropertyKeyNameContext *oC_PropertyKeyName();

   
  };

  RU_CreateNodeConstraintContext* rU_CreateNodeConstraint();

  class  RU_UnionTypeContext : public antlr4::ParserRuleContext {
  public:
    RU_UnionTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNION();
    RU_ColumnDefinitionsContext *rU_ColumnDefinitions();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  RU_UnionTypeContext* rU_UnionType();

  class  RU_StructTypeContext : public antlr4::ParserRuleContext {
  public:
    RU_StructTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRUCT();
    RU_ColumnDefinitionsContext *rU_ColumnDefinitions();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  RU_StructTypeContext* rU_StructType();

  class  RU_MapTypeContext : public antlr4::ParserRuleContext {
  public:
    RU_MapTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MAP();
    std::vector<RU_DataTypeContext *> rU_DataType();
    RU_DataTypeContext* rU_DataType(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  RU_MapTypeContext* rU_MapType();

  class  RU_DecimalTypeContext : public antlr4::ParserRuleContext {
  public:
    RU_DecimalTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DECIMAL();
    std::vector<OC_IntegerLiteralContext *> oC_IntegerLiteral();
    OC_IntegerLiteralContext* oC_IntegerLiteral(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  RU_DecimalTypeContext* rU_DecimalType();

  class  RU_DataTypeContext : public antlr4::ParserRuleContext {
  public:
    RU_DataTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_SymbolicNameContext *oC_SymbolicName();
    RU_UnionTypeContext *rU_UnionType();
    RU_StructTypeContext *rU_StructType();
    RU_MapTypeContext *rU_MapType();
    RU_DecimalTypeContext *rU_DecimalType();
    RU_DataTypeContext *rU_DataType();
    RU_ListIdentifiersContext *rU_ListIdentifiers();

   
  };

  RU_DataTypeContext* rU_DataType();
  RU_DataTypeContext* rU_DataType(int precedence);
  class  RU_ListIdentifiersContext : public antlr4::ParserRuleContext {
  public:
    RU_ListIdentifiersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RU_ListIdentifierContext *> rU_ListIdentifier();
    RU_ListIdentifierContext* rU_ListIdentifier(size_t i);

   
  };

  RU_ListIdentifiersContext* rU_ListIdentifiers();

  class  RU_ListIdentifierContext : public antlr4::ParserRuleContext {
  public:
    RU_ListIdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_IntegerLiteralContext *oC_IntegerLiteral();

   
  };

  RU_ListIdentifierContext* rU_ListIdentifier();

  class  OC_AnyCypherOptionContext : public antlr4::ParserRuleContext {
  public:
    OC_AnyCypherOptionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_ExplainContext *oC_Explain();
    OC_ProfileContext *oC_Profile();

   
  };

  OC_AnyCypherOptionContext* oC_AnyCypherOption();

  class  OC_ExplainContext : public antlr4::ParserRuleContext {
  public:
    OC_ExplainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXPLAIN();
    antlr4::tree::TerminalNode *SP();
    antlr4::tree::TerminalNode *LOGICAL();

   
  };

  OC_ExplainContext* oC_Explain();

  class  OC_ProfileContext : public antlr4::ParserRuleContext {
  public:
    OC_ProfileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROFILE();

   
  };

  OC_ProfileContext* oC_Profile();

  class  RU_TransactionContext : public antlr4::ParserRuleContext {
  public:
    RU_TransactionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BEGIN();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *TRANSACTION();
    antlr4::tree::TerminalNode *READ();
    antlr4::tree::TerminalNode *ONLY();
    antlr4::tree::TerminalNode *COMMIT();
    antlr4::tree::TerminalNode *ROLLBACK();
    antlr4::tree::TerminalNode *CHECKPOINT();

   
  };

  RU_TransactionContext* rU_Transaction();

  class  RU_ExtensionContext : public antlr4::ParserRuleContext {
  public:
    RU_ExtensionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RU_LoadExtensionContext *rU_LoadExtension();
    RU_InstallExtensionContext *rU_InstallExtension();
    RU_UninstallExtensionContext *rU_UninstallExtension();
    RU_UpdateExtensionContext *rU_UpdateExtension();

   
  };

  RU_ExtensionContext* rU_Extension();

  class  RU_LoadExtensionContext : public antlr4::ParserRuleContext {
  public:
    RU_LoadExtensionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOAD();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *StringLiteral();
    OC_VariableContext *oC_Variable();
    antlr4::tree::TerminalNode *EXTENSION();

   
  };

  RU_LoadExtensionContext* rU_LoadExtension();

  class  RU_InstallExtensionContext : public antlr4::ParserRuleContext {
  public:
    RU_InstallExtensionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INSTALL();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_VariableContext *oC_Variable();
    antlr4::tree::TerminalNode *FORCE();
    antlr4::tree::TerminalNode *FROM();
    antlr4::tree::TerminalNode *StringLiteral();

   
  };

  RU_InstallExtensionContext* rU_InstallExtension();

  class  RU_UninstallExtensionContext : public antlr4::ParserRuleContext {
  public:
    RU_UninstallExtensionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNINSTALL();
    antlr4::tree::TerminalNode *SP();
    OC_VariableContext *oC_Variable();

   
  };

  RU_UninstallExtensionContext* rU_UninstallExtension();

  class  RU_UpdateExtensionContext : public antlr4::ParserRuleContext {
  public:
    RU_UpdateExtensionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UPDATE();
    antlr4::tree::TerminalNode *SP();
    OC_VariableContext *oC_Variable();

   
  };

  RU_UpdateExtensionContext* rU_UpdateExtension();

  class  OC_QueryContext : public antlr4::ParserRuleContext {
  public:
    OC_QueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_RegularQueryContext *oC_RegularQuery();

   
  };

  OC_QueryContext* oC_Query();

  class  OC_RegularQueryContext : public antlr4::ParserRuleContext {
  public:
    OC_RegularQueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_SingleQueryContext *oC_SingleQuery();
    std::vector<OC_UnionContext *> oC_Union();
    OC_UnionContext* oC_Union(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    std::vector<OC_ReturnContext *> oC_Return();
    OC_ReturnContext* oC_Return(size_t i);

   
  };

  OC_RegularQueryContext* oC_RegularQuery();

  class  OC_UnionContext : public antlr4::ParserRuleContext {
  public:
    OC_UnionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNION();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *ALL();
    OC_SingleQueryContext *oC_SingleQuery();

   
  };

  OC_UnionContext* oC_Union();

  class  OC_SingleQueryContext : public antlr4::ParserRuleContext {
  public:
    OC_SingleQueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_SinglePartQueryContext *oC_SinglePartQuery();
    OC_MultiPartQueryContext *oC_MultiPartQuery();

   
  };

  OC_SingleQueryContext* oC_SingleQuery();

  class  OC_SinglePartQueryContext : public antlr4::ParserRuleContext {
  public:
    OC_SinglePartQueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_ReturnContext *oC_Return();
    std::vector<OC_ReadingClauseContext *> oC_ReadingClause();
    OC_ReadingClauseContext* oC_ReadingClause(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    std::vector<OC_UpdatingClauseContext *> oC_UpdatingClause();
    OC_UpdatingClauseContext* oC_UpdatingClause(size_t i);

   
  };

  OC_SinglePartQueryContext* oC_SinglePartQuery();

  class  OC_MultiPartQueryContext : public antlr4::ParserRuleContext {
  public:
    OC_MultiPartQueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_SinglePartQueryContext *oC_SinglePartQuery();
    std::vector<RU_QueryPartContext *> rU_QueryPart();
    RU_QueryPartContext* rU_QueryPart(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  OC_MultiPartQueryContext* oC_MultiPartQuery();

  class  RU_QueryPartContext : public antlr4::ParserRuleContext {
  public:
    RU_QueryPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_WithContext *oC_With();
    std::vector<OC_ReadingClauseContext *> oC_ReadingClause();
    OC_ReadingClauseContext* oC_ReadingClause(size_t i);
    std::vector<OC_UpdatingClauseContext *> oC_UpdatingClause();
    OC_UpdatingClauseContext* oC_UpdatingClause(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  RU_QueryPartContext* rU_QueryPart();

  class  OC_UpdatingClauseContext : public antlr4::ParserRuleContext {
  public:
    OC_UpdatingClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_CreateContext *oC_Create();
    OC_MergeContext *oC_Merge();
    OC_SetContext *oC_Set();
    OC_DeleteContext *oC_Delete();

   
  };

  OC_UpdatingClauseContext* oC_UpdatingClause();

  class  OC_ReadingClauseContext : public antlr4::ParserRuleContext {
  public:
    OC_ReadingClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_MatchContext *oC_Match();
    OC_UnwindContext *oC_Unwind();
    RU_InQueryCallContext *rU_InQueryCall();
    RU_LoadFromContext *rU_LoadFrom();

   
  };

  OC_ReadingClauseContext* oC_ReadingClause();

  class  RU_LoadFromContext : public antlr4::ParserRuleContext {
  public:
    RU_LoadFromContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOAD();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *FROM();
    RU_ScanSourceContext *rU_ScanSource();
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *HEADERS();
    RU_ColumnDefinitionsContext *rU_ColumnDefinitions();
    RU_OptionsContext *rU_Options();
    OC_WhereContext *oC_Where();

   
  };

  RU_LoadFromContext* rU_LoadFrom();

  class  OC_YieldItemContext : public antlr4::ParserRuleContext {
  public:
    OC_YieldItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OC_VariableContext *> oC_Variable();
    OC_VariableContext* oC_Variable(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *AS();

   
  };

  OC_YieldItemContext* oC_YieldItem();

  class  OC_YieldItemsContext : public antlr4::ParserRuleContext {
  public:
    OC_YieldItemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OC_YieldItemContext *> oC_YieldItem();
    OC_YieldItemContext* oC_YieldItem(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  OC_YieldItemsContext* oC_YieldItems();

  class  RU_InQueryCallContext : public antlr4::ParserRuleContext {
  public:
    RU_InQueryCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CALL();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_FunctionInvocationContext *oC_FunctionInvocation();
    OC_WhereContext *oC_Where();
    antlr4::tree::TerminalNode *YIELD();
    OC_YieldItemsContext *oC_YieldItems();

   
  };

  RU_InQueryCallContext* rU_InQueryCall();

  class  OC_MatchContext : public antlr4::ParserRuleContext {
  public:
    OC_MatchContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MATCH();
    OC_PatternContext *oC_Pattern();
    antlr4::tree::TerminalNode *OPTIONAL();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_WhereContext *oC_Where();
    RU_HintContext *rU_Hint();

   
  };

  OC_MatchContext* oC_Match();

  class  RU_HintContext : public antlr4::ParserRuleContext {
  public:
    RU_HintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HINT();
    antlr4::tree::TerminalNode *SP();
    RU_JoinNodeContext *rU_JoinNode();

   
  };

  RU_HintContext* rU_Hint();

  class  RU_JoinNodeContext : public antlr4::ParserRuleContext {
  public:
    RU_JoinNodeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RU_JoinNodeContext *> rU_JoinNode();
    RU_JoinNodeContext* rU_JoinNode(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    std::vector<OC_SchemaNameContext *> oC_SchemaName();
    OC_SchemaNameContext* oC_SchemaName(size_t i);
    antlr4::tree::TerminalNode *JOIN();
    std::vector<antlr4::tree::TerminalNode *> MULTI_JOIN();
    antlr4::tree::TerminalNode* MULTI_JOIN(size_t i);

   
  };

  RU_JoinNodeContext* rU_JoinNode();
  RU_JoinNodeContext* rU_JoinNode(int precedence);
  class  OC_UnwindContext : public antlr4::ParserRuleContext {
  public:
    OC_UnwindContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNWIND();
    OC_ExpressionContext *oC_Expression();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *AS();
    OC_VariableContext *oC_Variable();

   
  };

  OC_UnwindContext* oC_Unwind();

  class  OC_CreateContext : public antlr4::ParserRuleContext {
  public:
    OC_CreateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CREATE();
    OC_PatternContext *oC_Pattern();
    antlr4::tree::TerminalNode *SP();

   
  };

  OC_CreateContext* oC_Create();

  class  OC_MergeContext : public antlr4::ParserRuleContext {
  public:
    OC_MergeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MERGE();
    OC_PatternContext *oC_Pattern();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    std::vector<OC_MergeActionContext *> oC_MergeAction();
    OC_MergeActionContext* oC_MergeAction(size_t i);

   
  };

  OC_MergeContext* oC_Merge();

  class  OC_MergeActionContext : public antlr4::ParserRuleContext {
  public:
    OC_MergeActionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ON();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *MATCH();
    OC_SetContext *oC_Set();
    antlr4::tree::TerminalNode *CREATE();

   
  };

  OC_MergeActionContext* oC_MergeAction();

  class  OC_SetContext : public antlr4::ParserRuleContext {
  public:
    OC_SetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SET();
    std::vector<OC_SetItemContext *> oC_SetItem();
    OC_SetItemContext* oC_SetItem(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_AtomContext *oC_Atom();
    RU_PropertiesContext *rU_Properties();

   
  };

  OC_SetContext* oC_Set();

  class  OC_SetItemContext : public antlr4::ParserRuleContext {
  public:
    OC_SetItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_PropertyExpressionContext *oC_PropertyExpression();
    OC_ExpressionContext *oC_Expression();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  OC_SetItemContext* oC_SetItem();

  class  OC_DeleteContext : public antlr4::ParserRuleContext {
  public:
    OC_DeleteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DELETE();
    std::vector<OC_ExpressionContext *> oC_Expression();
    OC_ExpressionContext* oC_Expression(size_t i);
    antlr4::tree::TerminalNode *DETACH();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  OC_DeleteContext* oC_Delete();

  class  OC_WithContext : public antlr4::ParserRuleContext {
  public:
    OC_WithContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WITH();
    OC_ProjectionBodyContext *oC_ProjectionBody();
    OC_WhereContext *oC_Where();
    antlr4::tree::TerminalNode *SP();

   
  };

  OC_WithContext* oC_With();

  class  OC_ReturnContext : public antlr4::ParserRuleContext {
  public:
    OC_ReturnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    OC_ProjectionBodyContext *oC_ProjectionBody();

   
  };

  OC_ReturnContext* oC_Return();

  class  OC_ProjectionBodyContext : public antlr4::ParserRuleContext {
  public:
    OC_ProjectionBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_ProjectionItemsContext *oC_ProjectionItems();
    antlr4::tree::TerminalNode *DISTINCT();
    OC_OrderContext *oC_Order();
    OC_SkipContext *oC_Skip();
    OC_LimitContext *oC_Limit();

   
  };

  OC_ProjectionBodyContext* oC_ProjectionBody();

  class  OC_ProjectionItemsContext : public antlr4::ParserRuleContext {
  public:
    OC_ProjectionItemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STAR();
    std::vector<OC_ProjectionItemContext *> oC_ProjectionItem();
    OC_ProjectionItemContext* oC_ProjectionItem(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  OC_ProjectionItemsContext* oC_ProjectionItems();

  class  OC_ProjectionItemContext : public antlr4::ParserRuleContext {
  public:
    OC_ProjectionItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_ExpressionContext *oC_Expression();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *AS();
    OC_VariableContext *oC_Variable();

   
  };

  OC_ProjectionItemContext* oC_ProjectionItem();

  class  OC_OrderContext : public antlr4::ParserRuleContext {
  public:
    OC_OrderContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ORDER();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *BY();
    std::vector<OC_SortItemContext *> oC_SortItem();
    OC_SortItemContext* oC_SortItem(size_t i);

   
  };

  OC_OrderContext* oC_Order();

  class  OC_SkipContext : public antlr4::ParserRuleContext {
  public:
    OC_SkipContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *L_SKIP();
    antlr4::tree::TerminalNode *SP();
    OC_ExpressionContext *oC_Expression();

   
  };

  OC_SkipContext* oC_Skip();

  class  OC_LimitContext : public antlr4::ParserRuleContext {
  public:
    OC_LimitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LIMIT();
    antlr4::tree::TerminalNode *SP();
    OC_ExpressionContext *oC_Expression();

   
  };

  OC_LimitContext* oC_Limit();

  class  OC_SortItemContext : public antlr4::ParserRuleContext {
  public:
    OC_SortItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_ExpressionContext *oC_Expression();
    antlr4::tree::TerminalNode *ASCENDING();
    antlr4::tree::TerminalNode *ASC();
    antlr4::tree::TerminalNode *DESCENDING();
    antlr4::tree::TerminalNode *DESC();
    antlr4::tree::TerminalNode *SP();

   
  };

  OC_SortItemContext* oC_SortItem();

  class  OC_WhereContext : public antlr4::ParserRuleContext {
  public:
    OC_WhereContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHERE();
    antlr4::tree::TerminalNode *SP();
    OC_ExpressionContext *oC_Expression();

   
  };

  OC_WhereContext* oC_Where();

  class  OC_PatternContext : public antlr4::ParserRuleContext {
  public:
    OC_PatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OC_PatternPartContext *> oC_PatternPart();
    OC_PatternPartContext* oC_PatternPart(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  OC_PatternContext* oC_Pattern();

  class  OC_PatternPartContext : public antlr4::ParserRuleContext {
  public:
    OC_PatternPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_VariableContext *oC_Variable();
    OC_AnonymousPatternPartContext *oC_AnonymousPatternPart();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  OC_PatternPartContext* oC_PatternPart();

  class  OC_AnonymousPatternPartContext : public antlr4::ParserRuleContext {
  public:
    OC_AnonymousPatternPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_PatternElementContext *oC_PatternElement();

   
  };

  OC_AnonymousPatternPartContext* oC_AnonymousPatternPart();

  class  OC_PatternElementContext : public antlr4::ParserRuleContext {
  public:
    OC_PatternElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_NodePatternContext *oC_NodePattern();
    std::vector<OC_PatternElementChainContext *> oC_PatternElementChain();
    OC_PatternElementChainContext* oC_PatternElementChain(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_PatternElementContext *oC_PatternElement();

   
  };

  OC_PatternElementContext* oC_PatternElement();

  class  OC_NodePatternContext : public antlr4::ParserRuleContext {
  public:
    OC_NodePatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_VariableContext *oC_Variable();
    OC_NodeLabelsContext *oC_NodeLabels();
    RU_PropertiesContext *rU_Properties();

   
  };

  OC_NodePatternContext* oC_NodePattern();

  class  OC_PatternElementChainContext : public antlr4::ParserRuleContext {
  public:
    OC_PatternElementChainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_RelationshipPatternContext *oC_RelationshipPattern();
    OC_NodePatternContext *oC_NodePattern();
    antlr4::tree::TerminalNode *SP();

   
  };

  OC_PatternElementChainContext* oC_PatternElementChain();

  class  OC_RelationshipPatternContext : public antlr4::ParserRuleContext {
  public:
    OC_RelationshipPatternContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_LeftArrowHeadContext *oC_LeftArrowHead();
    std::vector<OC_DashContext *> oC_Dash();
    OC_DashContext* oC_Dash(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_RelationshipDetailContext *oC_RelationshipDetail();
    OC_RightArrowHeadContext *oC_RightArrowHead();

   
  };

  OC_RelationshipPatternContext* oC_RelationshipPattern();

  class  OC_RelationshipDetailContext : public antlr4::ParserRuleContext {
  public:
    OC_RelationshipDetailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_VariableContext *oC_Variable();
    OC_RelationshipTypesContext *oC_RelationshipTypes();
    RU_RecursiveDetailContext *rU_RecursiveDetail();
    RU_PropertiesContext *rU_Properties();

   
  };

  OC_RelationshipDetailContext* oC_RelationshipDetail();

  class  RU_PropertiesContext : public antlr4::ParserRuleContext {
  public:
    RU_PropertiesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    std::vector<OC_PropertyKeyNameContext *> oC_PropertyKeyName();
    OC_PropertyKeyNameContext* oC_PropertyKeyName(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<OC_ExpressionContext *> oC_Expression();
    OC_ExpressionContext* oC_Expression(size_t i);

   
  };

  RU_PropertiesContext* rU_Properties();

  class  OC_RelationshipTypesContext : public antlr4::ParserRuleContext {
  public:
    OC_RelationshipTypesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<OC_RelTypeNameContext *> oC_RelTypeName();
    OC_RelTypeNameContext* oC_RelTypeName(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  OC_RelationshipTypesContext* oC_RelationshipTypes();

  class  OC_NodeLabelsContext : public antlr4::ParserRuleContext {
  public:
    OC_NodeLabelsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<OC_LabelNameContext *> oC_LabelName();
    OC_LabelNameContext* oC_LabelName(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  OC_NodeLabelsContext* oC_NodeLabels();

  class  RU_RecursiveDetailContext : public antlr4::ParserRuleContext {
  public:
    RU_RecursiveDetailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STAR();
    RU_RecursiveTypeContext *rU_RecursiveType();
    OC_RangeLiteralContext *oC_RangeLiteral();
    RU_RecursiveComprehensionContext *rU_RecursiveComprehension();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  RU_RecursiveDetailContext* rU_RecursiveDetail();

  class  RU_RecursiveTypeContext : public antlr4::ParserRuleContext {
  public:
    RU_RecursiveTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WSHORTEST();
    OC_PropertyKeyNameContext *oC_PropertyKeyName();
    antlr4::tree::TerminalNode *ALL();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *SHORTEST();
    antlr4::tree::TerminalNode *TRAIL();
    antlr4::tree::TerminalNode *ACYCLIC();

   
  };

  RU_RecursiveTypeContext* rU_RecursiveType();

  class  OC_RangeLiteralContext : public antlr4::ParserRuleContext {
  public:
    OC_RangeLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOTDOT();
    OC_LowerBoundContext *oC_LowerBound();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_UpperBoundContext *oC_UpperBound();
    OC_IntegerLiteralContext *oC_IntegerLiteral();

   
  };

  OC_RangeLiteralContext* oC_RangeLiteral();

  class  RU_RecursiveComprehensionContext : public antlr4::ParserRuleContext {
  public:
    RU_RecursiveComprehensionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OC_VariableContext *> oC_Variable();
    OC_VariableContext* oC_Variable(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_WhereContext *oC_Where();
    std::vector<RU_RecursiveProjectionItemsContext *> rU_RecursiveProjectionItems();
    RU_RecursiveProjectionItemsContext* rU_RecursiveProjectionItems(size_t i);

   
  };

  RU_RecursiveComprehensionContext* rU_RecursiveComprehension();

  class  RU_RecursiveProjectionItemsContext : public antlr4::ParserRuleContext {
  public:
    RU_RecursiveProjectionItemsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_ProjectionItemsContext *oC_ProjectionItems();

   
  };

  RU_RecursiveProjectionItemsContext* rU_RecursiveProjectionItems();

  class  OC_LowerBoundContext : public antlr4::ParserRuleContext {
  public:
    OC_LowerBoundContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DecimalInteger();

   
  };

  OC_LowerBoundContext* oC_LowerBound();

  class  OC_UpperBoundContext : public antlr4::ParserRuleContext {
  public:
    OC_UpperBoundContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DecimalInteger();

   
  };

  OC_UpperBoundContext* oC_UpperBound();

  class  OC_LabelNameContext : public antlr4::ParserRuleContext {
  public:
    OC_LabelNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_SchemaNameContext *oC_SchemaName();

   
  };

  OC_LabelNameContext* oC_LabelName();

  class  OC_RelTypeNameContext : public antlr4::ParserRuleContext {
  public:
    OC_RelTypeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_SchemaNameContext *oC_SchemaName();

   
  };

  OC_RelTypeNameContext* oC_RelTypeName();

  class  OC_ExpressionContext : public antlr4::ParserRuleContext {
  public:
    OC_ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_OrExpressionContext *oC_OrExpression();

   
  };

  OC_ExpressionContext* oC_Expression();

  class  OC_OrExpressionContext : public antlr4::ParserRuleContext {
  public:
    OC_OrExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OC_XorExpressionContext *> oC_XorExpression();
    OC_XorExpressionContext* oC_XorExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OR();
    antlr4::tree::TerminalNode* OR(size_t i);

   
  };

  OC_OrExpressionContext* oC_OrExpression();

  class  OC_XorExpressionContext : public antlr4::ParserRuleContext {
  public:
    OC_XorExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OC_AndExpressionContext *> oC_AndExpression();
    OC_AndExpressionContext* oC_AndExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    std::vector<antlr4::tree::TerminalNode *> XOR();
    antlr4::tree::TerminalNode* XOR(size_t i);

   
  };

  OC_XorExpressionContext* oC_XorExpression();

  class  OC_AndExpressionContext : public antlr4::ParserRuleContext {
  public:
    OC_AndExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OC_NotExpressionContext *> oC_NotExpression();
    OC_NotExpressionContext* oC_NotExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);

   
  };

  OC_AndExpressionContext* oC_AndExpression();

  class  OC_NotExpressionContext : public antlr4::ParserRuleContext {
  public:
    OC_NotExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_ComparisonExpressionContext *oC_ComparisonExpression();
    std::vector<antlr4::tree::TerminalNode *> NOT();
    antlr4::tree::TerminalNode* NOT(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  OC_NotExpressionContext* oC_NotExpression();

  class  OC_ComparisonExpressionContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *invalid_not_equalToken = nullptr;
    OC_ComparisonExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RU_BitwiseOrOperatorExpressionContext *> rU_BitwiseOrOperatorExpression();
    RU_BitwiseOrOperatorExpressionContext* rU_BitwiseOrOperatorExpression(size_t i);
    std::vector<RU_ComparisonOperatorContext *> rU_ComparisonOperator();
    RU_ComparisonOperatorContext* rU_ComparisonOperator(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *INVALID_NOT_EQUAL();

   
  };

  OC_ComparisonExpressionContext* oC_ComparisonExpression();

  class  RU_ComparisonOperatorContext : public antlr4::ParserRuleContext {
  public:
    RU_ComparisonOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  RU_ComparisonOperatorContext* rU_ComparisonOperator();

  class  RU_BitwiseOrOperatorExpressionContext : public antlr4::ParserRuleContext {
  public:
    RU_BitwiseOrOperatorExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RU_BitwiseAndOperatorExpressionContext *> rU_BitwiseAndOperatorExpression();
    RU_BitwiseAndOperatorExpressionContext* rU_BitwiseAndOperatorExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  RU_BitwiseOrOperatorExpressionContext* rU_BitwiseOrOperatorExpression();

  class  RU_BitwiseAndOperatorExpressionContext : public antlr4::ParserRuleContext {
  public:
    RU_BitwiseAndOperatorExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RU_BitShiftOperatorExpressionContext *> rU_BitShiftOperatorExpression();
    RU_BitShiftOperatorExpressionContext* rU_BitShiftOperatorExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  RU_BitwiseAndOperatorExpressionContext* rU_BitwiseAndOperatorExpression();

  class  RU_BitShiftOperatorExpressionContext : public antlr4::ParserRuleContext {
  public:
    RU_BitShiftOperatorExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OC_AddOrSubtractExpressionContext *> oC_AddOrSubtractExpression();
    OC_AddOrSubtractExpressionContext* oC_AddOrSubtractExpression(size_t i);
    std::vector<RU_BitShiftOperatorContext *> rU_BitShiftOperator();
    RU_BitShiftOperatorContext* rU_BitShiftOperator(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  RU_BitShiftOperatorExpressionContext* rU_BitShiftOperatorExpression();

  class  RU_BitShiftOperatorContext : public antlr4::ParserRuleContext {
  public:
    RU_BitShiftOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  RU_BitShiftOperatorContext* rU_BitShiftOperator();

  class  OC_AddOrSubtractExpressionContext : public antlr4::ParserRuleContext {
  public:
    OC_AddOrSubtractExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OC_MultiplyDivideModuloExpressionContext *> oC_MultiplyDivideModuloExpression();
    OC_MultiplyDivideModuloExpressionContext* oC_MultiplyDivideModuloExpression(size_t i);
    std::vector<RU_AddOrSubtractOperatorContext *> rU_AddOrSubtractOperator();
    RU_AddOrSubtractOperatorContext* rU_AddOrSubtractOperator(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  OC_AddOrSubtractExpressionContext* oC_AddOrSubtractExpression();

  class  RU_AddOrSubtractOperatorContext : public antlr4::ParserRuleContext {
  public:
    RU_AddOrSubtractOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MINUS();

   
  };

  RU_AddOrSubtractOperatorContext* rU_AddOrSubtractOperator();

  class  OC_MultiplyDivideModuloExpressionContext : public antlr4::ParserRuleContext {
  public:
    OC_MultiplyDivideModuloExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OC_PowerOfExpressionContext *> oC_PowerOfExpression();
    OC_PowerOfExpressionContext* oC_PowerOfExpression(size_t i);
    std::vector<RU_MultiplyDivideModuloOperatorContext *> rU_MultiplyDivideModuloOperator();
    RU_MultiplyDivideModuloOperatorContext* rU_MultiplyDivideModuloOperator(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  OC_MultiplyDivideModuloExpressionContext* oC_MultiplyDivideModuloExpression();

  class  RU_MultiplyDivideModuloOperatorContext : public antlr4::ParserRuleContext {
  public:
    RU_MultiplyDivideModuloOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STAR();

   
  };

  RU_MultiplyDivideModuloOperatorContext* rU_MultiplyDivideModuloOperator();

  class  OC_PowerOfExpressionContext : public antlr4::ParserRuleContext {
  public:
    OC_PowerOfExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OC_StringListNullOperatorExpressionContext *> oC_StringListNullOperatorExpression();
    OC_StringListNullOperatorExpressionContext* oC_StringListNullOperatorExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  OC_PowerOfExpressionContext* oC_PowerOfExpression();

  class  OC_StringListNullOperatorExpressionContext : public antlr4::ParserRuleContext {
  public:
    OC_StringListNullOperatorExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_UnaryAddSubtractOrFactorialExpressionContext *oC_UnaryAddSubtractOrFactorialExpression();
    OC_StringOperatorExpressionContext *oC_StringOperatorExpression();
    OC_NullOperatorExpressionContext *oC_NullOperatorExpression();
    std::vector<OC_ListOperatorExpressionContext *> oC_ListOperatorExpression();
    OC_ListOperatorExpressionContext* oC_ListOperatorExpression(size_t i);

   
  };

  OC_StringListNullOperatorExpressionContext* oC_StringListNullOperatorExpression();

  class  OC_ListOperatorExpressionContext : public antlr4::ParserRuleContext {
  public:
    OC_ListOperatorExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *IN();
    OC_PropertyOrLabelsExpressionContext *oC_PropertyOrLabelsExpression();
    std::vector<OC_ExpressionContext *> oC_Expression();
    OC_ExpressionContext* oC_Expression(size_t i);
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *DOTDOT();

   
  };

  OC_ListOperatorExpressionContext* oC_ListOperatorExpression();

  class  OC_StringOperatorExpressionContext : public antlr4::ParserRuleContext {
  public:
    OC_StringOperatorExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_PropertyOrLabelsExpressionContext *oC_PropertyOrLabelsExpression();
    OC_RegularExpressionContext *oC_RegularExpression();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *STARTS();
    antlr4::tree::TerminalNode *WITH();
    antlr4::tree::TerminalNode *ENDS();
    antlr4::tree::TerminalNode *CONTAINS();

   
  };

  OC_StringOperatorExpressionContext* oC_StringOperatorExpression();

  class  OC_RegularExpressionContext : public antlr4::ParserRuleContext {
  public:
    OC_RegularExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SP();

   
  };

  OC_RegularExpressionContext* oC_RegularExpression();

  class  OC_NullOperatorExpressionContext : public antlr4::ParserRuleContext {
  public:
    OC_NullOperatorExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *NULL_();
    antlr4::tree::TerminalNode *NOT();

   
  };

  OC_NullOperatorExpressionContext* oC_NullOperatorExpression();

  class  OC_UnaryAddSubtractOrFactorialExpressionContext : public antlr4::ParserRuleContext {
  public:
    OC_UnaryAddSubtractOrFactorialExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_PropertyOrLabelsExpressionContext *oC_PropertyOrLabelsExpression();
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);
    antlr4::tree::TerminalNode *FACTORIAL();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  OC_UnaryAddSubtractOrFactorialExpressionContext* oC_UnaryAddSubtractOrFactorialExpression();

  class  OC_PropertyOrLabelsExpressionContext : public antlr4::ParserRuleContext {
  public:
    OC_PropertyOrLabelsExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_AtomContext *oC_Atom();
    std::vector<OC_PropertyLookupContext *> oC_PropertyLookup();
    OC_PropertyLookupContext* oC_PropertyLookup(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  OC_PropertyOrLabelsExpressionContext* oC_PropertyOrLabelsExpression();

  class  OC_AtomContext : public antlr4::ParserRuleContext {
  public:
    OC_AtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_LiteralContext *oC_Literal();
    OC_ParameterContext *oC_Parameter();
    OC_CaseExpressionContext *oC_CaseExpression();
    OC_ParenthesizedExpressionContext *oC_ParenthesizedExpression();
    OC_FunctionInvocationContext *oC_FunctionInvocation();
    OC_PathPatternsContext *oC_PathPatterns();
    OC_ExistCountSubqueryContext *oC_ExistCountSubquery();
    OC_VariableContext *oC_Variable();
    OC_QuantifierContext *oC_Quantifier();

   
  };

  OC_AtomContext* oC_Atom();

  class  OC_QuantifierContext : public antlr4::ParserRuleContext {
  public:
    OC_QuantifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ALL();
    OC_FilterExpressionContext *oC_FilterExpression();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *ANY();
    antlr4::tree::TerminalNode *NONE();
    antlr4::tree::TerminalNode *SINGLE();

   
  };

  OC_QuantifierContext* oC_Quantifier();

  class  OC_FilterExpressionContext : public antlr4::ParserRuleContext {
  public:
    OC_FilterExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_IdInCollContext *oC_IdInColl();
    antlr4::tree::TerminalNode *SP();
    OC_WhereContext *oC_Where();

   
  };

  OC_FilterExpressionContext* oC_FilterExpression();

  class  OC_IdInCollContext : public antlr4::ParserRuleContext {
  public:
    OC_IdInCollContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_VariableContext *oC_Variable();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *IN();
    OC_ExpressionContext *oC_Expression();

   
  };

  OC_IdInCollContext* oC_IdInColl();

  class  OC_LiteralContext : public antlr4::ParserRuleContext {
  public:
    OC_LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_NumberLiteralContext *oC_NumberLiteral();
    antlr4::tree::TerminalNode *StringLiteral();
    OC_BooleanLiteralContext *oC_BooleanLiteral();
    antlr4::tree::TerminalNode *NULL_();
    OC_ListLiteralContext *oC_ListLiteral();
    RU_StructLiteralContext *rU_StructLiteral();

   
  };

  OC_LiteralContext* oC_Literal();

  class  OC_BooleanLiteralContext : public antlr4::ParserRuleContext {
  public:
    OC_BooleanLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();

   
  };

  OC_BooleanLiteralContext* oC_BooleanLiteral();

  class  OC_ListLiteralContext : public antlr4::ParserRuleContext {
  public:
    OC_ListLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_ExpressionContext *oC_Expression();
    std::vector<RU_ListEntryContext *> rU_ListEntry();
    RU_ListEntryContext* rU_ListEntry(size_t i);

   
  };

  OC_ListLiteralContext* oC_ListLiteral();

  class  RU_ListEntryContext : public antlr4::ParserRuleContext {
  public:
    RU_ListEntryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SP();
    OC_ExpressionContext *oC_Expression();

   
  };

  RU_ListEntryContext* rU_ListEntry();

  class  RU_StructLiteralContext : public antlr4::ParserRuleContext {
  public:
    RU_StructLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RU_StructFieldContext *> rU_StructField();
    RU_StructFieldContext* rU_StructField(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  RU_StructLiteralContext* rU_StructLiteral();

  class  RU_StructFieldContext : public antlr4::ParserRuleContext {
  public:
    RU_StructFieldContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COLON();
    OC_ExpressionContext *oC_Expression();
    OC_SymbolicNameContext *oC_SymbolicName();
    antlr4::tree::TerminalNode *StringLiteral();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  RU_StructFieldContext* rU_StructField();

  class  OC_ParenthesizedExpressionContext : public antlr4::ParserRuleContext {
  public:
    OC_ParenthesizedExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_ExpressionContext *oC_Expression();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  OC_ParenthesizedExpressionContext* oC_ParenthesizedExpression();

  class  OC_FunctionInvocationContext : public antlr4::ParserRuleContext {
  public:
    OC_FunctionInvocationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COUNT();
    antlr4::tree::TerminalNode *STAR();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *CAST();
    std::vector<RU_FunctionParameterContext *> rU_FunctionParameter();
    RU_FunctionParameterContext* rU_FunctionParameter(size_t i);
    antlr4::tree::TerminalNode *AS();
    RU_DataTypeContext *rU_DataType();
    OC_FunctionNameContext *oC_FunctionName();
    antlr4::tree::TerminalNode *DISTINCT();

   
  };

  OC_FunctionInvocationContext* oC_FunctionInvocation();

  class  OC_FunctionNameContext : public antlr4::ParserRuleContext {
  public:
    OC_FunctionNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_SymbolicNameContext *oC_SymbolicName();

   
  };

  OC_FunctionNameContext* oC_FunctionName();

  class  RU_FunctionParameterContext : public antlr4::ParserRuleContext {
  public:
    RU_FunctionParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_ExpressionContext *oC_Expression();
    OC_SymbolicNameContext *oC_SymbolicName();
    antlr4::tree::TerminalNode *COLON();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    RU_LambdaParameterContext *rU_LambdaParameter();

   
  };

  RU_FunctionParameterContext* rU_FunctionParameter();

  class  RU_LambdaParameterContext : public antlr4::ParserRuleContext {
  public:
    RU_LambdaParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RU_LambdaVarsContext *rU_LambdaVars();
    antlr4::tree::TerminalNode *MINUS();
    OC_ExpressionContext *oC_Expression();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  RU_LambdaParameterContext* rU_LambdaParameter();

  class  RU_LambdaVarsContext : public antlr4::ParserRuleContext {
  public:
    RU_LambdaVarsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OC_SymbolicNameContext *> oC_SymbolicName();
    OC_SymbolicNameContext* oC_SymbolicName(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  RU_LambdaVarsContext* rU_LambdaVars();

  class  OC_PathPatternsContext : public antlr4::ParserRuleContext {
  public:
    OC_PathPatternsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_NodePatternContext *oC_NodePattern();
    std::vector<OC_PatternElementChainContext *> oC_PatternElementChain();
    OC_PatternElementChainContext* oC_PatternElementChain(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  OC_PathPatternsContext* oC_PathPatterns();

  class  OC_ExistCountSubqueryContext : public antlr4::ParserRuleContext {
  public:
    OC_ExistCountSubqueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MATCH();
    OC_PatternContext *oC_Pattern();
    antlr4::tree::TerminalNode *EXISTS();
    antlr4::tree::TerminalNode *COUNT();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    OC_WhereContext *oC_Where();
    RU_HintContext *rU_Hint();

   
  };

  OC_ExistCountSubqueryContext* oC_ExistCountSubquery();

  class  OC_PropertyLookupContext : public antlr4::ParserRuleContext {
  public:
    OC_PropertyLookupContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_PropertyKeyNameContext *oC_PropertyKeyName();
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *SP();

   
  };

  OC_PropertyLookupContext* oC_PropertyLookup();

  class  OC_CaseExpressionContext : public antlr4::ParserRuleContext {
  public:
    OC_CaseExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *ELSE();
    std::vector<OC_ExpressionContext *> oC_Expression();
    OC_ExpressionContext* oC_Expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);
    antlr4::tree::TerminalNode *CASE();
    std::vector<OC_CaseAlternativeContext *> oC_CaseAlternative();
    OC_CaseAlternativeContext* oC_CaseAlternative(size_t i);

   
  };

  OC_CaseExpressionContext* oC_CaseExpression();

  class  OC_CaseAlternativeContext : public antlr4::ParserRuleContext {
  public:
    OC_CaseAlternativeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHEN();
    std::vector<OC_ExpressionContext *> oC_Expression();
    OC_ExpressionContext* oC_Expression(size_t i);
    antlr4::tree::TerminalNode *THEN();
    std::vector<antlr4::tree::TerminalNode *> SP();
    antlr4::tree::TerminalNode* SP(size_t i);

   
  };

  OC_CaseAlternativeContext* oC_CaseAlternative();

  class  OC_VariableContext : public antlr4::ParserRuleContext {
  public:
    OC_VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_SymbolicNameContext *oC_SymbolicName();

   
  };

  OC_VariableContext* oC_Variable();

  class  OC_NumberLiteralContext : public antlr4::ParserRuleContext {
  public:
    OC_NumberLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_DoubleLiteralContext *oC_DoubleLiteral();
    OC_IntegerLiteralContext *oC_IntegerLiteral();

   
  };

  OC_NumberLiteralContext* oC_NumberLiteral();

  class  OC_ParameterContext : public antlr4::ParserRuleContext {
  public:
    OC_ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_SymbolicNameContext *oC_SymbolicName();
    antlr4::tree::TerminalNode *DecimalInteger();

   
  };

  OC_ParameterContext* oC_Parameter();

  class  OC_PropertyExpressionContext : public antlr4::ParserRuleContext {
  public:
    OC_PropertyExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_AtomContext *oC_Atom();
    OC_PropertyLookupContext *oC_PropertyLookup();
    antlr4::tree::TerminalNode *SP();

   
  };

  OC_PropertyExpressionContext* oC_PropertyExpression();

  class  OC_PropertyKeyNameContext : public antlr4::ParserRuleContext {
  public:
    OC_PropertyKeyNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_SchemaNameContext *oC_SchemaName();

   
  };

  OC_PropertyKeyNameContext* oC_PropertyKeyName();

  class  OC_IntegerLiteralContext : public antlr4::ParserRuleContext {
  public:
    OC_IntegerLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DecimalInteger();

   
  };

  OC_IntegerLiteralContext* oC_IntegerLiteral();

  class  OC_DoubleLiteralContext : public antlr4::ParserRuleContext {
  public:
    OC_DoubleLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ExponentDecimalReal();
    antlr4::tree::TerminalNode *RegularDecimalReal();

   
  };

  OC_DoubleLiteralContext* oC_DoubleLiteral();

  class  OC_SchemaNameContext : public antlr4::ParserRuleContext {
  public:
    OC_SchemaNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OC_SymbolicNameContext *oC_SymbolicName();

   
  };

  OC_SchemaNameContext* oC_SchemaName();

  class  OC_SymbolicNameContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *escapedsymbolicnameToken = nullptr;
    OC_SymbolicNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UnescapedSymbolicName();
    antlr4::tree::TerminalNode *EscapedSymbolicName();
    antlr4::tree::TerminalNode *HexLetter();
    RU_NonReservedKeywordsContext *rU_NonReservedKeywords();

   
  };

  OC_SymbolicNameContext* oC_SymbolicName();

  class  RU_NonReservedKeywordsContext : public antlr4::ParserRuleContext {
  public:
    RU_NonReservedKeywordsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COMMENT();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *ALTER();
    antlr4::tree::TerminalNode *AS();
    antlr4::tree::TerminalNode *ATTACH();
    antlr4::tree::TerminalNode *BEGIN();
    antlr4::tree::TerminalNode *BY();
    antlr4::tree::TerminalNode *CALL();
    antlr4::tree::TerminalNode *CHECKPOINT();
    antlr4::tree::TerminalNode *COMMIT();
    antlr4::tree::TerminalNode *CONTAINS();
    antlr4::tree::TerminalNode *COPY();
    antlr4::tree::TerminalNode *COUNT();
    antlr4::tree::TerminalNode *CYCLE();
    antlr4::tree::TerminalNode *DATABASE();
    antlr4::tree::TerminalNode *DECIMAL();
    antlr4::tree::TerminalNode *DELETE();
    antlr4::tree::TerminalNode *DETACH();
    antlr4::tree::TerminalNode *DROP();
    antlr4::tree::TerminalNode *EXPLAIN();
    antlr4::tree::TerminalNode *EXPORT();
    antlr4::tree::TerminalNode *EXTENSION();
    antlr4::tree::TerminalNode *FORCE();
    antlr4::tree::TerminalNode *GRAPH();
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *IS();
    antlr4::tree::TerminalNode *IMPORT();
    antlr4::tree::TerminalNode *INCREMENT();
    antlr4::tree::TerminalNode *KEY();
    antlr4::tree::TerminalNode *LOAD();
    antlr4::tree::TerminalNode *LOGICAL();
    antlr4::tree::TerminalNode *MATCH();
    antlr4::tree::TerminalNode *MAXVALUE();
    antlr4::tree::TerminalNode *MERGE();
    antlr4::tree::TerminalNode *MINVALUE();
    antlr4::tree::TerminalNode *NO();
    antlr4::tree::TerminalNode *NODE();
    antlr4::tree::TerminalNode *PROJECT();
    antlr4::tree::TerminalNode *READ();
    antlr4::tree::TerminalNode *REL();
    antlr4::tree::TerminalNode *RENAME();
    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *ROLLBACK();
    antlr4::tree::TerminalNode *ROLE();
    antlr4::tree::TerminalNode *SEQUENCE();
    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *START();
    antlr4::tree::TerminalNode *STRUCT();
    antlr4::tree::TerminalNode *L_SKIP();
    antlr4::tree::TerminalNode *LIMIT();
    antlr4::tree::TerminalNode *TRANSACTION();
    antlr4::tree::TerminalNode *TYPE();
    antlr4::tree::TerminalNode *USE();
    antlr4::tree::TerminalNode *UNINSTALL();
    antlr4::tree::TerminalNode *UPDATE();
    antlr4::tree::TerminalNode *WRITE();
    antlr4::tree::TerminalNode *FROM();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *YIELD();
    antlr4::tree::TerminalNode *USER();
    antlr4::tree::TerminalNode *PASSWORD();
    antlr4::tree::TerminalNode *MAP();

   
  };

  RU_NonReservedKeywordsContext* rU_NonReservedKeywords();

  class  OC_LeftArrowHeadContext : public antlr4::ParserRuleContext {
  public:
    OC_LeftArrowHeadContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  OC_LeftArrowHeadContext* oC_LeftArrowHead();

  class  OC_RightArrowHeadContext : public antlr4::ParserRuleContext {
  public:
    OC_RightArrowHeadContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

   
  };

  OC_RightArrowHeadContext* oC_RightArrowHead();

  class  OC_DashContext : public antlr4::ParserRuleContext {
  public:
    OC_DashContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MINUS();

   
  };

  OC_DashContext* oC_Dash();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool rU_DataTypeSempred(RU_DataTypeContext *_localctx, size_t predicateIndex);
  bool rU_JoinNodeSempred(RU_JoinNodeContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

      virtual void notifyQueryNotConcludeWithReturn(antlr4::Token* startToken) {};
      virtual void notifyNodePatternWithoutParentheses(std::string nodeName, antlr4::Token* startToken) {};
      virtual void notifyInvalidNotEqualOperator(antlr4::Token* startToken) {};
      virtual void notifyEmptyToken(antlr4::Token* startToken) {};
      virtual void notifyReturnNotAtEnd(antlr4::Token* startToken) {};
      virtual void notifyNonBinaryComparison(antlr4::Token* startToken) {};

};

