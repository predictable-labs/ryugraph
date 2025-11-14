
ku_Statements
    : oC_Cypher ( SP? ';' SP? oC_Cypher )* SP? EOF ;

oC_Cypher
    : oC_AnyCypherOption? SP? ( oC_Statement ) ( SP? ';' )?;

oC_Statement
    : oC_Query
        | rU_CreateUser
        | rU_CreateRole
        | rU_CreateNodeTable
        | rU_CreateRelTable
        | rU_CreateSequence
        | rU_CreateType
        | rU_Drop
        | rU_AlterTable
        | rU_CopyFrom
        | rU_CopyFromByColumn
        | rU_CopyTO
        | rU_StandaloneCall
        | rU_CreateMacro
        | rU_CommentOn
        | rU_Transaction
        | rU_Extension
        | rU_ExportDatabase
        | rU_ImportDatabase
        | rU_AttachDatabase
        | rU_DetachDatabase
        | rU_UseDatabase;

rU_CopyFrom
    : COPY SP oC_SchemaName rU_ColumnNames? SP FROM SP rU_ScanSource ( SP? '(' SP? rU_Options SP? ')' )? ;

rU_ColumnNames
    : SP? '(' SP? (oC_SchemaName ( SP? ',' SP? oC_SchemaName )* SP?)? ')';

rU_ScanSource
    : rU_FilePaths
        | '(' SP? oC_Query SP? ')'
        | oC_Parameter
        | oC_Variable
        | oC_Variable '.' SP? oC_SchemaName
        | oC_FunctionInvocation ;

rU_CopyFromByColumn
    : COPY SP oC_SchemaName SP FROM SP '(' SP? StringLiteral ( SP? ',' SP? StringLiteral )* ')' SP BY SP COLUMN ;

rU_CopyTO
    : COPY SP '(' SP? oC_Query SP? ')' SP TO SP StringLiteral ( SP? '(' SP? rU_Options SP? ')' )? ;

rU_ExportDatabase
    : EXPORT SP DATABASE SP StringLiteral ( SP? '(' SP? rU_Options SP? ')' )? ;

rU_ImportDatabase
    : IMPORT SP DATABASE SP StringLiteral;

rU_AttachDatabase
    : ATTACH SP StringLiteral (SP AS SP oC_SchemaName)? SP '(' SP? DBTYPE SP oC_SymbolicName (SP? ',' SP? rU_Options)? SP? ')' ;

rU_Option
    : oC_SymbolicName (SP? '=' SP? | SP*) oC_Literal | oC_SymbolicName;

rU_Options
    : rU_Option ( SP? ',' SP? rU_Option )* ;

rU_DetachDatabase
    : DETACH SP oC_SchemaName;

rU_UseDatabase
    : USE SP oC_SchemaName;

rU_StandaloneCall
    : CALL SP oC_SymbolicName SP? '=' SP? oC_Expression
        | CALL SP oC_FunctionInvocation;

rU_CommentOn
    : COMMENT SP ON SP TABLE SP oC_SchemaName SP IS SP StringLiteral ;

rU_CreateMacro
    : CREATE SP MACRO SP oC_FunctionName SP? '(' SP? rU_PositionalArgs? SP? rU_DefaultArg? ( SP? ',' SP? rU_DefaultArg )* SP? ')' SP AS SP oC_Expression ;

rU_PositionalArgs
    : oC_SymbolicName ( SP? ',' SP? oC_SymbolicName )* ;

rU_DefaultArg
    : oC_SymbolicName SP? ':' '=' SP? oC_Literal ;

rU_FilePaths
    : '[' SP? StringLiteral ( SP? ',' SP? StringLiteral )* ']'
        | StringLiteral
        | GLOB SP? '(' SP? StringLiteral SP? ')' ;

rU_IfNotExists
    : IF SP NOT SP EXISTS ;

rU_CreateNodeTable
    : CREATE SP NODE SP TABLE SP (rU_IfNotExists SP)? oC_SchemaName ( SP? '(' SP? rU_PropertyDefinitions SP? ( ',' SP? rU_CreateNodeConstraint )? SP? ')' | SP AS SP oC_Query ) ;

rU_CreateRelTable
    : CREATE SP REL SP TABLE ( SP GROUP )? ( SP rU_IfNotExists )? SP oC_SchemaName
        SP? '(' SP?
            rU_FromToConnections SP? (
            ( ',' SP? rU_PropertyDefinitions SP? )?
            ( ',' SP? oC_SymbolicName SP? )? // Constraints
            ')'
            | ')' SP AS SP oC_Query )
         ( SP WITH SP? '(' SP? rU_Options SP? ')')? ;

rU_FromToConnections
    : rU_FromToConnection ( SP? ',' SP? rU_FromToConnection )* ;

rU_FromToConnection
    : FROM SP oC_SchemaName SP TO SP oC_SchemaName ;

rU_CreateSequence
    : CREATE SP SEQUENCE SP (rU_IfNotExists SP)? oC_SchemaName (SP rU_SequenceOptions)* ;

rU_CreateType
    : CREATE SP TYPE SP oC_SchemaName SP AS SP rU_DataType SP? ;

rU_SequenceOptions
    : rU_IncrementBy
        | rU_MinValue
        | rU_MaxValue
        | rU_StartWith
        | rU_Cycle;

rU_WithPasswd
    : SP WITH SP PASSWORD SP StringLiteral ;

rU_CreateUser
    : CREATE SP USER SP (rU_IfNotExists SP)? oC_Variable rU_WithPasswd? ;

rU_CreateRole
    : CREATE SP ROLE SP (rU_IfNotExists SP)? oC_Variable ;

rU_IncrementBy : INCREMENT SP ( BY SP )? MINUS? oC_IntegerLiteral ;

rU_MinValue : (NO SP MINVALUE) | (MINVALUE SP MINUS? oC_IntegerLiteral) ;

rU_MaxValue : (NO SP MAXVALUE) | (MAXVALUE SP MINUS? oC_IntegerLiteral) ;

rU_StartWith : START SP ( WITH SP )? MINUS? oC_IntegerLiteral ;

rU_Cycle : (NO SP)? CYCLE ;

rU_IfExists
    : IF SP EXISTS ;

rU_Drop
    : DROP SP (TABLE | SEQUENCE | MACRO) SP (rU_IfExists SP)? oC_SchemaName ;

rU_AlterTable
    : ALTER SP TABLE SP oC_SchemaName SP rU_AlterOptions ;

rU_AlterOptions
    : rU_AddProperty
        | rU_DropProperty
        | rU_RenameTable
        | rU_RenameProperty
        | rU_AddFromToConnection
        | rU_DropFromToConnection;

rU_AddProperty
    : ADD SP (rU_IfNotExists SP)? oC_PropertyKeyName SP rU_DataType ( SP rU_Default )? ;

rU_Default
    : DEFAULT SP oC_Expression ;

rU_DropProperty
    : DROP SP (rU_IfExists SP)? oC_PropertyKeyName ;

rU_RenameTable
    : RENAME SP TO SP oC_SchemaName ;

rU_RenameProperty
    : RENAME SP oC_PropertyKeyName SP TO SP oC_PropertyKeyName ;

rU_AddFromToConnection
    : ADD SP (rU_IfNotExists SP)? rU_FromToConnection ;

rU_DropFromToConnection
    : DROP SP (rU_IfExists SP)? rU_FromToConnection ;

rU_ColumnDefinitions: rU_ColumnDefinition ( SP? ',' SP? rU_ColumnDefinition )* ;

rU_ColumnDefinition : oC_PropertyKeyName SP rU_DataType ;

rU_PropertyDefinitions : rU_PropertyDefinition ( SP? ',' SP? rU_PropertyDefinition )* ;

rU_PropertyDefinition : rU_ColumnDefinition ( SP rU_Default )? ( SP PRIMARY SP KEY)?;

rU_CreateNodeConstraint : PRIMARY SP KEY SP? '(' SP? oC_PropertyKeyName SP? ')' ;

DECIMAL: ( 'D' | 'd' ) ( 'E' | 'e' ) ( 'C' | 'c' ) ( 'I' | 'i' ) ( 'M' | 'm' ) ( 'A' | 'a' ) ( 'L' | 'l' ) ;

rU_UnionType
    : UNION SP? '(' SP? rU_ColumnDefinitions SP? ')' ;

rU_StructType
    : STRUCT SP? '(' SP? rU_ColumnDefinitions SP? ')' ;

rU_MapType
    : MAP SP? '(' SP? rU_DataType SP? ',' SP? rU_DataType SP? ')' ;

rU_DecimalType
    : DECIMAL SP? '(' SP? oC_IntegerLiteral SP? ',' SP? oC_IntegerLiteral SP? ')' ;

rU_DataType
    : oC_SymbolicName
        | rU_DataType rU_ListIdentifiers
        | rU_UnionType
        | rU_StructType
        | rU_MapType
        | rU_DecimalType ;

rU_ListIdentifiers : rU_ListIdentifier ( rU_ListIdentifier )* ;

rU_ListIdentifier : '[' oC_IntegerLiteral? ']' ;

oC_AnyCypherOption
    : oC_Explain
        | oC_Profile ;

oC_Explain
    : EXPLAIN (SP LOGICAL)? ;

oC_Profile
    : PROFILE ;

rU_Transaction
    : BEGIN SP TRANSACTION
        | BEGIN SP TRANSACTION SP READ SP ONLY
        | COMMIT
        | ROLLBACK
        | CHECKPOINT;

rU_Extension
    : rU_LoadExtension
        | rU_InstallExtension
        | rU_UninstallExtension
        | rU_UpdateExtension ;

rU_LoadExtension
    : LOAD SP (EXTENSION SP)? ( StringLiteral | oC_Variable ) ;

rU_InstallExtension
    : (FORCE SP)? INSTALL SP oC_Variable (SP FROM SP StringLiteral)?;

rU_UninstallExtension
    : UNINSTALL SP oC_Variable;

rU_UpdateExtension
    : UPDATE SP oC_Variable;

oC_Query
    : oC_RegularQuery ;

oC_RegularQuery
    : oC_SingleQuery ( SP? oC_Union )*
        | (oC_Return SP? )+ oC_SingleQuery { notifyReturnNotAtEnd($ctx->start); }
        ;

oC_Union
     :  ( UNION SP ALL SP? oC_SingleQuery )
         | ( UNION SP? oC_SingleQuery ) ;

oC_SingleQuery
    : oC_SinglePartQuery
        | oC_MultiPartQuery
        ;

oC_SinglePartQuery
    : ( oC_ReadingClause SP? )* oC_Return
        | ( ( oC_ReadingClause SP? )* oC_UpdatingClause ( SP? oC_UpdatingClause )* ( SP? oC_Return )? )
        ;

oC_MultiPartQuery
    : ( rU_QueryPart SP? )+ oC_SinglePartQuery;

rU_QueryPart
    : (oC_ReadingClause SP? )* ( oC_UpdatingClause SP? )* oC_With ;

oC_UpdatingClause
    : oC_Create
        | oC_Merge
        | oC_Set
        | oC_Delete
        ;

oC_ReadingClause
    : oC_Match
        | oC_Unwind
        | rU_InQueryCall
        | rU_LoadFrom
        ;

rU_LoadFrom
    :  LOAD ( SP WITH SP HEADERS SP? '(' SP? rU_ColumnDefinitions SP? ')' )? SP FROM SP rU_ScanSource (SP? '(' SP? rU_Options SP? ')')? (SP? oC_Where)? ;


oC_YieldItem
         :  ( oC_Variable SP AS SP )? oC_Variable ;

oC_YieldItems
          :  oC_YieldItem ( SP? ',' SP? oC_YieldItem )* ;

rU_InQueryCall
    : CALL SP oC_FunctionInvocation (SP? oC_Where)? ( SP? YIELD SP oC_YieldItems )? ;

oC_Match
    : ( OPTIONAL SP )? MATCH SP? oC_Pattern ( SP oC_Where )? ( SP rU_Hint )? ;

rU_Hint
    : HINT SP rU_JoinNode;

rU_JoinNode
    :  rU_JoinNode SP JOIN SP rU_JoinNode
        | rU_JoinNode ( SP MULTI_JOIN SP oC_SchemaName)+
        | '(' SP? rU_JoinNode SP? ')'
        | oC_SchemaName ;

oC_Unwind : UNWIND SP? oC_Expression SP AS SP oC_Variable ;

oC_Create
    : CREATE SP? oC_Pattern ;

// For unknown reason, openCypher use oC_PatternPart instead of oC_Pattern. There should be no difference in terms of planning.
// So we choose to be consistent with oC_Create and use oC_Pattern instead.
oC_Merge : MERGE SP? oC_Pattern ( SP oC_MergeAction )* ;

oC_MergeAction
    :  ( ON SP MATCH SP oC_Set )
        | ( ON SP CREATE SP oC_Set )
        ;

oC_Set
    : SET SP? oC_SetItem ( SP? ',' SP? oC_SetItem )*
        | SET SP? oC_Atom SP? '=' SP? rU_Properties;

oC_SetItem
    : ( oC_PropertyExpression SP? '=' SP? oC_Expression ) ;

oC_Delete
    : ( DETACH SP )? DELETE SP? oC_Expression ( SP? ',' SP? oC_Expression )*;

oC_With
    : WITH oC_ProjectionBody ( SP? oC_Where )? ;

oC_Return
    : RETURN oC_ProjectionBody ;

oC_ProjectionBody
    : ( SP? DISTINCT )? SP oC_ProjectionItems (SP oC_Order )? ( SP oC_Skip )? ( SP oC_Limit )? ;

oC_ProjectionItems
    : ( STAR ( SP? ',' SP? oC_ProjectionItem )* )
        | ( oC_ProjectionItem ( SP? ',' SP? oC_ProjectionItem )* )
        ;

STAR : '*' ;

oC_ProjectionItem
    : ( oC_Expression SP AS SP oC_Variable )
        | oC_Expression
        ;

oC_Order
    : ORDER SP BY SP oC_SortItem ( ',' SP? oC_SortItem )* ;

oC_Skip
    :  L_SKIP SP oC_Expression ;

L_SKIP : ( 'S' | 's' ) ( 'K' | 'k' ) ( 'I' | 'i' ) ( 'P' | 'p' ) ;

oC_Limit
    : LIMIT SP oC_Expression ;

oC_SortItem
    : oC_Expression ( SP? ( ASCENDING | ASC | DESCENDING | DESC ) )? ;

oC_Where
    : WHERE SP oC_Expression ;

oC_Pattern
    : oC_PatternPart ( SP? ',' SP? oC_PatternPart )* ;

oC_PatternPart
    :  ( oC_Variable SP? '=' SP? oC_AnonymousPatternPart )
        | oC_AnonymousPatternPart ;

oC_AnonymousPatternPart
    : oC_PatternElement ;

oC_PatternElement
    : ( oC_NodePattern ( SP? oC_PatternElementChain )* )
        | ( '(' oC_PatternElement ')' )
        ;

oC_NodePattern
    : '(' SP? ( oC_Variable SP? )? ( oC_NodeLabels SP? )? ( rU_Properties SP? )? ')' ;

oC_PatternElementChain
    : oC_RelationshipPattern SP? oC_NodePattern ;

oC_RelationshipPattern
    : ( oC_LeftArrowHead SP? oC_Dash SP? oC_RelationshipDetail? SP? oC_Dash )
        | ( oC_Dash SP? oC_RelationshipDetail? SP? oC_Dash SP? oC_RightArrowHead )
        | ( oC_Dash SP? oC_RelationshipDetail? SP? oC_Dash )
        ;

oC_RelationshipDetail
    : '[' SP? ( oC_Variable SP? )? ( oC_RelationshipTypes SP? )? ( rU_RecursiveDetail SP? )? ( rU_Properties SP? )? ']' ;

// The original oC_Properties definition is  oC_MapLiteral | oC_Parameter.
// We choose to not support parameter as properties which will be the decision for a long time.
// We then substitute with oC_MapLiteral definition. We create oC_MapLiteral only when we decide to add MAP type.
rU_Properties
    : '{' SP? ( oC_PropertyKeyName SP? ':' SP? oC_Expression SP? ( ',' SP? oC_PropertyKeyName SP? ':' SP? oC_Expression SP? )* )? '}';

oC_RelationshipTypes
    :  ':' SP? oC_RelTypeName ( SP? '|' ':'? SP? oC_RelTypeName )* ;

oC_NodeLabels
    :  ':' SP? oC_LabelName ( SP? ('|' ':'? | ':') SP? oC_LabelName )* ;

rU_RecursiveDetail
    : '*' ( SP? rU_RecursiveType)? ( SP? oC_RangeLiteral )? ( SP? rU_RecursiveComprehension )? ;

rU_RecursiveType
    : (ALL SP)? WSHORTEST SP? '(' SP? oC_PropertyKeyName SP? ')'
        | SHORTEST
        | ALL SP SHORTEST
        | TRAIL
        | ACYCLIC ;

oC_RangeLiteral
    :  oC_LowerBound? SP? DOTDOT SP? oC_UpperBound?
        | oC_IntegerLiteral ;

rU_RecursiveComprehension
    : '(' SP? oC_Variable SP? ',' SP? oC_Variable ( SP? '|' SP? oC_Where SP? )? ( SP? '|' SP? rU_RecursiveProjectionItems SP? ',' SP? rU_RecursiveProjectionItems SP? )? ')' ;

rU_RecursiveProjectionItems
    : '{' SP? oC_ProjectionItems? SP? '}' ;

oC_LowerBound
    : DecimalInteger ;

oC_UpperBound
    : DecimalInteger ;

oC_LabelName
    : oC_SchemaName ;

oC_RelTypeName
    : oC_SchemaName ;

oC_Expression
    : oC_OrExpression ;

oC_OrExpression
    : oC_XorExpression ( SP OR SP oC_XorExpression )* ;

oC_XorExpression
    : oC_AndExpression ( SP XOR SP oC_AndExpression )* ;

oC_AndExpression
    : oC_NotExpression ( SP AND SP oC_NotExpression )* ;

oC_NotExpression
    : ( NOT SP? )*  oC_ComparisonExpression;

oC_ComparisonExpression
    : rU_BitwiseOrOperatorExpression ( SP? rU_ComparisonOperator SP? rU_BitwiseOrOperatorExpression )?
        | rU_BitwiseOrOperatorExpression ( SP? INVALID_NOT_EQUAL SP? rU_BitwiseOrOperatorExpression ) { notifyInvalidNotEqualOperator($INVALID_NOT_EQUAL); }
        | rU_BitwiseOrOperatorExpression SP? rU_ComparisonOperator SP? rU_BitwiseOrOperatorExpression ( SP? rU_ComparisonOperator SP? rU_BitwiseOrOperatorExpression )+ { notifyNonBinaryComparison($ctx->start); }
        ;

rU_ComparisonOperator : '=' | '<>' | '<' | '<=' | '>' | '>=' ;

INVALID_NOT_EQUAL : '!=' ;

rU_BitwiseOrOperatorExpression
    : rU_BitwiseAndOperatorExpression ( SP? '|' SP? rU_BitwiseAndOperatorExpression )* ;

rU_BitwiseAndOperatorExpression
    : rU_BitShiftOperatorExpression ( SP? '&' SP? rU_BitShiftOperatorExpression )* ;

rU_BitShiftOperatorExpression
    : oC_AddOrSubtractExpression ( SP? rU_BitShiftOperator SP? oC_AddOrSubtractExpression )* ;

rU_BitShiftOperator : '>>' | '<<' ;

oC_AddOrSubtractExpression
    : oC_MultiplyDivideModuloExpression ( SP? rU_AddOrSubtractOperator SP? oC_MultiplyDivideModuloExpression )* ;

rU_AddOrSubtractOperator : '+' | '-' ;

oC_MultiplyDivideModuloExpression
    : oC_PowerOfExpression ( SP? rU_MultiplyDivideModuloOperator SP? oC_PowerOfExpression )* ;

rU_MultiplyDivideModuloOperator : '*' | '/' | '%' ;

oC_PowerOfExpression
    : oC_StringListNullOperatorExpression ( SP? '^' SP? oC_StringListNullOperatorExpression )* ;

oC_StringListNullOperatorExpression
    : oC_UnaryAddSubtractOrFactorialExpression ( oC_StringOperatorExpression | oC_ListOperatorExpression+ | oC_NullOperatorExpression )? ;

oC_ListOperatorExpression
    : ( SP IN SP? oC_PropertyOrLabelsExpression )
        | ( '[' oC_Expression ']' )
        | ( '[' oC_Expression? ( COLON | DOTDOT ) oC_Expression? ']' ) ;

COLON : ':' ;

DOTDOT : '..' ;

oC_StringOperatorExpression
    :  ( oC_RegularExpression | ( SP STARTS SP WITH ) | ( SP ENDS SP WITH ) | ( SP CONTAINS ) ) SP? oC_PropertyOrLabelsExpression ;

oC_RegularExpression
    :  SP? '=~' ;

oC_NullOperatorExpression
    : ( SP IS SP NULL )
        | ( SP IS SP NOT SP NULL ) ;

MINUS : '-' ;

FACTORIAL : '!' ;

oC_UnaryAddSubtractOrFactorialExpression
    : ( MINUS SP? )* oC_PropertyOrLabelsExpression (SP? FACTORIAL)? ;

oC_PropertyOrLabelsExpression
    : oC_Atom ( SP? oC_PropertyLookup )* ;

oC_Atom
    : oC_Literal
        | oC_Parameter
        | oC_CaseExpression
        | oC_ParenthesizedExpression
        | oC_FunctionInvocation
        | oC_PathPatterns
        | oC_ExistCountSubquery
        | oC_Variable
        | oC_Quantifier
        ;

oC_Quantifier
    :  ( ALL SP? '(' SP? oC_FilterExpression SP? ')' )
        | ( ANY SP? '(' SP? oC_FilterExpression SP? ')' )
        | ( NONE SP? '(' SP? oC_FilterExpression SP? ')' )
        | ( SINGLE SP? '(' SP? oC_FilterExpression SP? ')' )
        ;

oC_FilterExpression
    :  oC_IdInColl SP oC_Where ;

oC_IdInColl
    :  oC_Variable SP IN SP oC_Expression ;

oC_Literal
    : oC_NumberLiteral
        | StringLiteral
        | oC_BooleanLiteral
        | NULL
        | oC_ListLiteral
        | rU_StructLiteral
        ;

oC_BooleanLiteral
    : TRUE
        | FALSE
        ;

oC_ListLiteral
    :  '[' SP? ( oC_Expression SP? ( rU_ListEntry SP? )* )? ']' ;

rU_ListEntry
    : ',' SP? oC_Expression? ;

rU_StructLiteral
    :  '{' SP? rU_StructField SP? ( ',' SP? rU_StructField SP? )* '}' ;

rU_StructField
    :   ( oC_SymbolicName | StringLiteral ) SP? ':' SP? oC_Expression ;

oC_ParenthesizedExpression
    : '(' SP? oC_Expression SP? ')' ;

oC_FunctionInvocation
    : COUNT SP? '(' SP? '*' SP? ')'
        | CAST SP? '(' SP? rU_FunctionParameter SP? ( ( AS SP? rU_DataType ) | ( ',' SP? rU_FunctionParameter ) ) SP? ')'
        | oC_FunctionName SP? '(' SP? ( DISTINCT SP? )? ( rU_FunctionParameter SP? ( ',' SP? rU_FunctionParameter SP? )* )? ')' ;

oC_FunctionName
    : oC_SymbolicName ;

rU_FunctionParameter
    : ( oC_SymbolicName SP? ':' '=' SP? )? oC_Expression
        | rU_LambdaParameter ;

rU_LambdaParameter
    : rU_LambdaVars SP? '-' '>' SP? oC_Expression SP? ;

rU_LambdaVars
    : oC_SymbolicName
    | '(' SP? oC_SymbolicName SP? ( ',' SP? oC_SymbolicName SP?)* ')' ;

oC_PathPatterns
    : oC_NodePattern ( SP? oC_PatternElementChain )+;

oC_ExistCountSubquery
    : (EXISTS | COUNT) SP? '{' SP? MATCH SP? oC_Pattern ( SP? oC_Where )? ( SP? rU_Hint )? SP? '}' ;

oC_PropertyLookup
    : '.' SP? ( oC_PropertyKeyName | STAR ) ;

oC_CaseExpression
    :  ( ( CASE ( SP? oC_CaseAlternative )+ ) | ( CASE SP? oC_Expression ( SP? oC_CaseAlternative )+ ) ) ( SP? ELSE SP? oC_Expression )? SP? END ;

oC_CaseAlternative
    :  WHEN SP? oC_Expression SP? THEN SP? oC_Expression ;

oC_Variable
    : oC_SymbolicName ;

StringLiteral
    : ( '"' ( StringLiteral_0 | EscapedChar )* '"' )
        | ( '\'' ( StringLiteral_1 | EscapedChar )* '\'' )
        ;

EscapedChar
    : '\\' ( '\\' | '\'' | '"' | ( 'B' | 'b' ) | ( 'F' | 'f' ) | ( 'N' | 'n' ) | ( 'R' | 'r' ) | ( 'T' | 't' ) | ( ( 'X' | 'x' ) ( HexDigit HexDigit ) ) | ( ( 'U' | 'u' ) ( HexDigit HexDigit HexDigit HexDigit ) ) | ( ( 'U' | 'u' ) ( HexDigit HexDigit HexDigit HexDigit HexDigit HexDigit HexDigit HexDigit ) ) ) ;

oC_NumberLiteral
    : oC_DoubleLiteral
        | oC_IntegerLiteral
        ;

oC_Parameter
    : '$' ( oC_SymbolicName | DecimalInteger ) ;

oC_PropertyExpression
    : oC_Atom SP? oC_PropertyLookup ;

oC_PropertyKeyName
    : oC_SchemaName ;

oC_IntegerLiteral
    : DecimalInteger ;

DecimalInteger
    : ZeroDigit
        | ( NonZeroDigit ( Digit )* )
        ;

HexLetter
    : ( 'A' | 'a' )
        | ( 'B' | 'b' )
        | ( 'C' | 'c' )
        | ( 'D' | 'd' )
        | ( 'E' | 'e' )
        | ( 'F' | 'f' )
        ;

HexDigit
    : Digit
        | HexLetter
        ;

Digit
    : ZeroDigit
        | NonZeroDigit
        ;

NonZeroDigit
    : NonZeroOctDigit
        | '8'
        | '9'
        ;

NonZeroOctDigit
    : '1'
        | '2'
        | '3'
        | '4'
        | '5'
        | '6'
        | '7'
        ;

ZeroDigit
    : '0' ;

oC_DoubleLiteral
    : ExponentDecimalReal
        | RegularDecimalReal
        ;

ExponentDecimalReal
    : ( ( Digit )+ | ( ( Digit )+ '.' ( Digit )+ ) | ( '.' ( Digit )+ ) ) ( 'E' | 'e' ) '-'? ( Digit )+ ;

RegularDecimalReal
    : ( Digit )* '.' ( Digit )+ ;

oC_SchemaName
    : oC_SymbolicName ;

oC_SymbolicName
    : UnescapedSymbolicName
        | EscapedSymbolicName {if ($EscapedSymbolicName.text == "``") { notifyEmptyToken($EscapedSymbolicName); }}
        | HexLetter
        | rU_NonReservedKeywords
        ;

// example of BEGIN and END: TCKWith2.Scenario1
rU_NonReservedKeywords
    : COMMENT
        | ADD
        | ALTER
        | AS
        | ATTACH
        | BEGIN
        | BY
        | CALL
        | CHECKPOINT
        | COMMENT
        | COMMIT
        | CONTAINS
        | COPY
        | COUNT
        | CYCLE
        | DATABASE
        | DECIMAL
        | DELETE
        | DETACH
        | DROP
        | EXPLAIN
        | EXPORT
        | EXTENSION
        | FORCE
        | GRAPH
        | IF
        | IS
        | IMPORT
        | INCREMENT
        | KEY
        | LOAD
        | LOGICAL
        | MATCH
        | MAXVALUE
        | MERGE
        | MINVALUE
        | NO
        | NODE
        | PROJECT
        | READ
        | REL
        | RENAME
        | RETURN
        | ROLLBACK
        | ROLE
        | SEQUENCE
        | SET
        | START
        | STRUCT
        | L_SKIP
        | LIMIT
        | TRANSACTION
        | TYPE
        | USE
        | UNINSTALL
        | UPDATE
        | WRITE
        | FROM
        | TO
        | YIELD
        | USER
        | PASSWORD
        | MAP
        ;

UnescapedSymbolicName
    : IdentifierStart ( IdentifierPart )* ;

IdentifierStart
    : ID_Start
        | Pc
        ;

IdentifierPart
    : ID_Continue
        | Sc
        ;

EscapedSymbolicName
    : ( '`' ( EscapedSymbolicName_0 )* '`' )+ ;

SP
  : ( WHITESPACE )+ ;

WHITESPACE
    : SPACE
        | TAB
        | LF
        | VT
        | FF
        | CR
        | FS
        | GS
        | RS
        | US
        | '\u1680'
        | '\u180e'
        | '\u2000'
        | '\u2001'
        | '\u2002'
        | '\u2003'
        | '\u2004'
        | '\u2005'
        | '\u2006'
        | '\u2008'
        | '\u2009'
        | '\u200a'
        | '\u2028'
        | '\u2029'
        | '\u205f'
        | '\u3000'
        | '\u00a0'
        | '\u2007'
        | '\u202f'
        | CypherComment
        ;

CypherComment
    : ( '/*' ( Comment_1 | ( '*' Comment_2 ) )* '*/' )
        | ( '//' ( Comment_3 )* CR? ( LF | EOF ) )
        ;

oC_LeftArrowHead
    : '<'
        | '\u27e8'
        | '\u3008'
        | '\ufe64'
        | '\uff1c'
        ;

oC_RightArrowHead
    : '>'
        | '\u27e9'
        | '\u3009'
        | '\ufe65'
        | '\uff1e'
        ;

oC_Dash
    : '-'
        | '\u00ad'
        | '\u2010'
        | '\u2011'
        | '\u2012'
        | '\u2013'
        | '\u2014'
        | '\u2015'
        | '\u2212'
        | '\ufe58'
        | '\ufe63'
        | '\uff0d'
        ;

fragment FF : [\f] ;

fragment EscapedSymbolicName_0 : ~[`] ;

fragment RS : [\u001E] ;

fragment ID_Continue : [\p{ID_Continue}] ;

fragment Comment_1 : ~[*] ;

fragment StringLiteral_1 : ~['\\] ;

fragment Comment_3 : ~[\n\r] ;

fragment Comment_2 : ~[/] ;

fragment GS : [\u001D] ;

fragment FS : [\u001C] ;

fragment CR : [\r] ;

fragment Sc : [\p{Sc}] ;

fragment SPACE : [ ] ;

fragment Pc : [\p{Pc}] ;

fragment TAB : [\t] ;

fragment StringLiteral_0 : ~["\\] ;

fragment LF : [\n] ;

fragment VT : [\u000B] ;

fragment US : [\u001F] ;

fragment ID_Start : [\p{ID_Start}] ;

// This is used to capture unknown lexer input (e.g. !) to avoid parser exception.
Unknown : .;
