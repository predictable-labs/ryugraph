#include "common/exception/parser.h"
#include "common/string_format.h"
#include "parser/ddl/alter.h"
#include "parser/ddl/create_sequence.h"
#include "parser/ddl/create_table.h"
#include "parser/ddl/create_type.h"
#include "parser/ddl/drop.h"
#include "parser/ddl/drop_info.h"
#include "parser/transformer.h"

using namespace ryu::common;
using namespace ryu::catalog;

namespace ryu {
namespace parser {

std::unique_ptr<Statement> Transformer::transformAlterTable(
    CypherParser::RU_AlterTableContext& ctx) {
    if (ctx.rU_AlterOptions()->rU_AddProperty()) {
        return transformAddProperty(ctx);
    }
    if (ctx.rU_AlterOptions()->rU_DropProperty()) {
        return transformDropProperty(ctx);
    }
    if (ctx.rU_AlterOptions()->rU_RenameTable()) {
        return transformRenameTable(ctx);
    }
    if (ctx.rU_AlterOptions()->rU_AddFromToConnection()) {
        return transformAddFromToConnection(ctx);
    }
    if (ctx.rU_AlterOptions()->rU_DropFromToConnection()) {
        return transformDropFromToConnection(ctx);
    }
    return transformRenameProperty(ctx);
}

std::string Transformer::getPKName(CypherParser::RU_CreateNodeTableContext& ctx) {
    auto pkCount = 0;
    std::string pkName;
    auto& propertyDefinitions = *ctx.rU_PropertyDefinitions();
    for (auto& definition : propertyDefinitions.rU_PropertyDefinition()) {
        if (definition->PRIMARY() && definition->KEY()) {
            pkCount++;
            pkName = transformPrimaryKey(*definition->rU_ColumnDefinition());
        }
    }
    if (ctx.rU_CreateNodeConstraint()) {
        // In the case where no pkName has been found, or the Node Constraint's name is different
        // than the pkName found, add the counter.
        if (pkCount == 0 || transformPrimaryKey(*ctx.rU_CreateNodeConstraint()) != pkName) {
            pkCount++;
        }
        pkName = transformPrimaryKey(*ctx.rU_CreateNodeConstraint());
    }
    if (pkCount == 0) {
        // Raise exception when no PRIMARY KEY is specified.
        throw ParserException("Can not find primary key.");
    } else if (pkCount > 1) {
        // Raise exception when multiple PRIMARY KEY are specified.
        throw ParserException("Found multiple primary keys.");
    }
    return pkName;
}

ConflictAction Transformer::transformConflictAction(CypherParser::RU_IfNotExistsContext* ctx) {
    if (ctx != nullptr) {
        return ConflictAction::ON_CONFLICT_DO_NOTHING;
    }
    return ConflictAction::ON_CONFLICT_THROW;
}

std::unique_ptr<Statement> Transformer::transformCreateNodeTable(
    CypherParser::RU_CreateNodeTableContext& ctx) {
    auto tableName = transformSchemaName(*ctx.oC_SchemaName());
    auto createTableInfo =
        CreateTableInfo(TableType::NODE, tableName, transformConflictAction(ctx.rU_IfNotExists()));
    // If CREATE NODE TABLE AS syntax
    if (ctx.oC_Query()) {
        return std::make_unique<CreateTable>(std::move(createTableInfo),
            std::make_unique<QueryScanSource>(transformQuery(*ctx.oC_Query())));
    } else {
        createTableInfo.propertyDefinitions =
            transformPropertyDefinitions(*ctx.rU_PropertyDefinitions());
        createTableInfo.extraInfo = std::make_unique<ExtraCreateNodeTableInfo>(getPKName(ctx));
        return std::make_unique<CreateTable>(std::move(createTableInfo));
    }
}

std::unique_ptr<Statement> Transformer::transformCreateRelGroup(
    CypherParser::RU_CreateRelTableContext& ctx) {
    auto tableName = transformSchemaName(*ctx.oC_SchemaName());
    std::string relMultiplicity = "MANY_MANY";
    if (ctx.oC_SymbolicName()) {
        relMultiplicity = transformSymbolicName(*ctx.oC_SymbolicName());
    }
    options_t options;
    if (ctx.rU_Options()) {
        options = transformOptions(*ctx.rU_Options());
    }
    std::vector<std::pair<std::string, std::string>> fromToPairs;
    for (auto& fromTo : ctx.rU_FromToConnections()->rU_FromToConnection()) {
        auto src = transformSchemaName(*fromTo->oC_SchemaName(0));
        auto dst = transformSchemaName(*fromTo->oC_SchemaName(1));
        fromToPairs.emplace_back(src, dst);
    }
    std::unique_ptr<ExtraCreateTableInfo> extraInfo =
        std::make_unique<ExtraCreateRelTableGroupInfo>(relMultiplicity, std::move(fromToPairs),
            std::move(options));
    auto conflictAction = transformConflictAction(ctx.rU_IfNotExists());
    auto createTableInfo = CreateTableInfo(common::TableType::REL, tableName, conflictAction);
    if (ctx.rU_PropertyDefinitions()) {
        createTableInfo.propertyDefinitions =
            transformPropertyDefinitions(*ctx.rU_PropertyDefinitions());
    }
    createTableInfo.extraInfo = std::move(extraInfo);
    if (ctx.oC_Query()) {
        auto scanSource = std::make_unique<QueryScanSource>(transformQuery(*ctx.oC_Query()));
        return std::make_unique<CreateTable>(std::move(createTableInfo), std::move(scanSource));
    } else {
        return std::make_unique<CreateTable>(std::move(createTableInfo));
    }
}

std::unique_ptr<Statement> Transformer::transformCreateSequence(
    CypherParser::RU_CreateSequenceContext& ctx) {
    auto sequenceName = transformSchemaName(*ctx.oC_SchemaName());
    auto createSequenceInfo = CreateSequenceInfo(sequenceName,
        ctx.rU_IfNotExists() ? common::ConflictAction::ON_CONFLICT_DO_NOTHING :
                               common::ConflictAction::ON_CONFLICT_THROW);
    std::unordered_set<SequenceInfoType> applied;
    for (auto seqOption : ctx.rU_SequenceOptions()) {
        SequenceInfoType type; // NOLINT(*-init-variables)
        std::string typeString;
        CypherParser::OC_IntegerLiteralContext* valCtx = nullptr;
        std::string* valOption = nullptr;
        if (seqOption->rU_StartWith()) {
            type = SequenceInfoType::START;
            typeString = "START";
            valCtx = seqOption->rU_StartWith()->oC_IntegerLiteral();
            valOption = &createSequenceInfo.startWith;
            *valOption = seqOption->rU_StartWith()->MINUS() ? "-" : "";
        } else if (seqOption->rU_IncrementBy()) {
            type = SequenceInfoType::INCREMENT;
            typeString = "INCREMENT";
            valCtx = seqOption->rU_IncrementBy()->oC_IntegerLiteral();
            valOption = &createSequenceInfo.increment;
            *valOption = seqOption->rU_IncrementBy()->MINUS() ? "-" : "";
        } else if (seqOption->rU_MinValue()) {
            type = SequenceInfoType::MINVALUE;
            typeString = "MINVALUE";
            if (!seqOption->rU_MinValue()->NO()) {
                valCtx = seqOption->rU_MinValue()->oC_IntegerLiteral();
                valOption = &createSequenceInfo.minValue;
                *valOption = seqOption->rU_MinValue()->MINUS() ? "-" : "";
            }
        } else if (seqOption->rU_MaxValue()) {
            type = SequenceInfoType::MAXVALUE;
            typeString = "MAXVALUE";
            if (!seqOption->rU_MaxValue()->NO()) {
                valCtx = seqOption->rU_MaxValue()->oC_IntegerLiteral();
                valOption = &createSequenceInfo.maxValue;
                *valOption = seqOption->rU_MaxValue()->MINUS() ? "-" : "";
            }
        } else { // seqOption->rU_Cycle()
            type = SequenceInfoType::CYCLE;
            typeString = "CYCLE";
            if (!seqOption->rU_Cycle()->NO()) {
                createSequenceInfo.cycle = true;
            }
        }
        if (applied.find(type) != applied.end()) {
            throw ParserException(typeString + " should be passed at most once.");
        }
        applied.insert(type);

        if (valCtx && valOption) {
            *valOption += valCtx->DecimalInteger()->getText();
        }
    }
    return std::make_unique<CreateSequence>(std::move(createSequenceInfo));
}

std::unique_ptr<Statement> Transformer::transformCreateType(
    CypherParser::RU_CreateTypeContext& ctx) {
    auto name = transformSchemaName(*ctx.oC_SchemaName());
    auto type = transformDataType(*ctx.rU_DataType());
    return std::make_unique<CreateType>(name, type);
}

DropType transformDropType(CypherParser::RU_DropContext& ctx) {
    if (ctx.TABLE()) {
        return DropType::TABLE;
    } else if (ctx.SEQUENCE()) {
        return DropType::SEQUENCE;
    } else if (ctx.MACRO()) {
        return DropType::MACRO;
    } else {
        RYU_UNREACHABLE;
    }
}

std::unique_ptr<Statement> Transformer::transformDrop(CypherParser::RU_DropContext& ctx) {
    auto name = transformSchemaName(*ctx.oC_SchemaName());
    auto dropType = transformDropType(ctx);
    auto conflictAction = ctx.rU_IfExists() ? common::ConflictAction::ON_CONFLICT_DO_NOTHING :
                                              common::ConflictAction::ON_CONFLICT_THROW;
    return std::make_unique<Drop>(DropInfo{std::move(name), dropType, conflictAction});
}

std::unique_ptr<Statement> Transformer::transformRenameTable(
    CypherParser::RU_AlterTableContext& ctx) {
    auto tableName = transformSchemaName(*ctx.oC_SchemaName());
    auto newName = transformSchemaName(*ctx.rU_AlterOptions()->rU_RenameTable()->oC_SchemaName());
    auto extraInfo = std::make_unique<ExtraRenameTableInfo>(std::move(newName));
    auto info = AlterInfo(AlterType::RENAME, tableName, std::move(extraInfo));
    return std::make_unique<Alter>(std::move(info));
}

std::unique_ptr<Statement> Transformer::transformAddFromToConnection(
    CypherParser::RU_AlterTableContext& ctx) {
    auto tableName = transformSchemaName(*ctx.oC_SchemaName());
    auto schemaNameCtx =
        ctx.rU_AlterOptions()->rU_AddFromToConnection()->rU_FromToConnection()->oC_SchemaName();
    RYU_ASSERT(schemaNameCtx.size() == 2);
    auto srcTableName = transformSchemaName(*schemaNameCtx[0]);
    auto dstTableName = transformSchemaName(*schemaNameCtx[1]);
    auto extraInfo = std::make_unique<ExtraAddFromToConnection>(std::move(srcTableName),
        std::move(dstTableName));
    ConflictAction action = ConflictAction::ON_CONFLICT_THROW;
    if (ctx.rU_AlterOptions()->rU_AddFromToConnection()->rU_IfNotExists()) {
        action = ConflictAction::ON_CONFLICT_DO_NOTHING;
    }
    auto info = AlterInfo(AlterType::ADD_FROM_TO_CONNECTION, std::move(tableName),
        std::move(extraInfo), action);
    return std::make_unique<Alter>(std::move(info));
}

std::unique_ptr<Statement> Transformer::transformDropFromToConnection(
    CypherParser::RU_AlterTableContext& ctx) {
    auto tableName = transformSchemaName(*ctx.oC_SchemaName());
    auto schemaNameCtx =
        ctx.rU_AlterOptions()->rU_DropFromToConnection()->rU_FromToConnection()->oC_SchemaName();
    RYU_ASSERT(schemaNameCtx.size() == 2);
    auto srcTableName = transformSchemaName(*schemaNameCtx[0]);
    auto dstTableName = transformSchemaName(*schemaNameCtx[1]);
    auto extraInfo = std::make_unique<ExtraAddFromToConnection>(std::move(srcTableName),
        std::move(dstTableName));
    ConflictAction action = ConflictAction::ON_CONFLICT_THROW;
    if (ctx.rU_AlterOptions()->rU_DropFromToConnection()->rU_IfExists()) {
        action = ConflictAction::ON_CONFLICT_DO_NOTHING;
    }
    auto info = AlterInfo(AlterType::DROP_FROM_TO_CONNECTION, std::move(tableName),
        std::move(extraInfo), action);
    return std::make_unique<Alter>(std::move(info));
}

std::unique_ptr<Statement> Transformer::transformAddProperty(
    CypherParser::RU_AlterTableContext& ctx) {
    auto tableName = transformSchemaName(*ctx.oC_SchemaName());
    auto addPropertyCtx = ctx.rU_AlterOptions()->rU_AddProperty();
    auto propertyName = transformPropertyKeyName(*addPropertyCtx->oC_PropertyKeyName());
    auto dataType = transformDataType(*addPropertyCtx->rU_DataType());
    std::unique_ptr<ParsedExpression> defaultValue = nullptr;
    if (addPropertyCtx->rU_Default()) {
        defaultValue = transformExpression(*addPropertyCtx->rU_Default()->oC_Expression());
    }
    auto extraInfo = std::make_unique<ExtraAddPropertyInfo>(std::move(propertyName),
        std::move(dataType), std::move(defaultValue));
    ConflictAction action = ConflictAction::ON_CONFLICT_THROW;
    if (addPropertyCtx->rU_IfNotExists()) {
        action = ConflictAction::ON_CONFLICT_DO_NOTHING;
    }
    auto info = AlterInfo(AlterType::ADD_PROPERTY, tableName, std::move(extraInfo), action);
    return std::make_unique<Alter>(std::move(info));
}

std::unique_ptr<Statement> Transformer::transformDropProperty(
    CypherParser::RU_AlterTableContext& ctx) {
    auto tableName = transformSchemaName(*ctx.oC_SchemaName());
    auto dropProperty = ctx.rU_AlterOptions()->rU_DropProperty();
    auto propertyName = transformPropertyKeyName(*dropProperty->oC_PropertyKeyName());
    auto extraInfo = std::make_unique<ExtraDropPropertyInfo>(std::move(propertyName));
    ConflictAction action = ConflictAction::ON_CONFLICT_THROW;
    if (dropProperty->rU_IfExists()) {
        action = ConflictAction::ON_CONFLICT_DO_NOTHING;
    }
    auto info = AlterInfo(AlterType::DROP_PROPERTY, tableName, std::move(extraInfo), action);
    return std::make_unique<Alter>(std::move(info));
}

std::unique_ptr<Statement> Transformer::transformRenameProperty(
    CypherParser::RU_AlterTableContext& ctx) {
    auto tableName = transformSchemaName(*ctx.oC_SchemaName());
    auto propertyName = transformPropertyKeyName(
        *ctx.rU_AlterOptions()->rU_RenameProperty()->oC_PropertyKeyName()[0]);
    auto newName = transformPropertyKeyName(
        *ctx.rU_AlterOptions()->rU_RenameProperty()->oC_PropertyKeyName()[1]);
    auto extraInfo = std::make_unique<ExtraRenamePropertyInfo>(propertyName, newName);
    auto info = AlterInfo(AlterType::RENAME_PROPERTY, tableName, std::move(extraInfo));
    return std::make_unique<Alter>(std::move(info));
}

std::unique_ptr<Statement> Transformer::transformCommentOn(CypherParser::RU_CommentOnContext& ctx) {
    auto tableName = transformSchemaName(*ctx.oC_SchemaName());
    auto comment = transformStringLiteral(*ctx.StringLiteral());
    auto extraInfo = std::make_unique<ExtraCommentInfo>(comment);
    auto info = AlterInfo(AlterType::COMMENT, tableName, std::move(extraInfo));
    return std::make_unique<Alter>(std::move(info));
}

std::vector<ParsedColumnDefinition> Transformer::transformColumnDefinitions(
    CypherParser::RU_ColumnDefinitionsContext& ctx) {
    std::vector<ParsedColumnDefinition> definitions;
    for (auto& definition : ctx.rU_ColumnDefinition()) {
        definitions.emplace_back(transformColumnDefinition(*definition));
    }
    return definitions;
}

ParsedColumnDefinition Transformer::transformColumnDefinition(
    CypherParser::RU_ColumnDefinitionContext& ctx) {
    auto propertyName = transformPropertyKeyName(*ctx.oC_PropertyKeyName());
    auto dataType = transformDataType(*ctx.rU_DataType());
    return ParsedColumnDefinition(propertyName, dataType);
}

std::vector<ParsedPropertyDefinition> Transformer::transformPropertyDefinitions(
    CypherParser::RU_PropertyDefinitionsContext& ctx) {
    std::vector<ParsedPropertyDefinition> definitions;
    for (auto& definition : ctx.rU_PropertyDefinition()) {
        auto columnDefinition = transformColumnDefinition(*definition->rU_ColumnDefinition());
        std::unique_ptr<ParsedExpression> defaultExpr = nullptr;
        if (definition->rU_Default()) {
            defaultExpr = transformExpression(*definition->rU_Default()->oC_Expression());
        }
        definitions.push_back(
            ParsedPropertyDefinition(std::move(columnDefinition), std::move(defaultExpr)));
    }
    return definitions;
}

static std::string convertColumnDefinitionsToString(
    const std::vector<ParsedColumnDefinition>& columnDefinitions) {
    std::string result;
    for (auto& columnDefinition : columnDefinitions) {
        result += common::stringFormat("{} {},", columnDefinition.name, columnDefinition.type);
    }
    return result.substr(0, result.length() - 1);
}

std::string Transformer::transformUnionType(CypherParser::RU_UnionTypeContext& ctx) {
    return common::stringFormat("{}({})", ctx.UNION()->getText(),
        convertColumnDefinitionsToString(transformColumnDefinitions(*ctx.rU_ColumnDefinitions())));
}

std::string Transformer::transformStructType(CypherParser::RU_StructTypeContext& ctx) {
    return common::stringFormat("{}({})", ctx.STRUCT()->getText(),
        convertColumnDefinitionsToString(transformColumnDefinitions(*ctx.rU_ColumnDefinitions())));
}

std::string Transformer::transformMapType(CypherParser::RU_MapTypeContext& ctx) {
    return common::stringFormat("{}({},{})", ctx.MAP()->getText(),
        transformDataType(*ctx.rU_DataType()[0]), transformDataType(*ctx.rU_DataType()[1]));
}

std::string Transformer::transformDecimalType(CypherParser::RU_DecimalTypeContext& ctx) {
    return ctx.getText();
}

std::string Transformer::transformDataType(CypherParser::RU_DataTypeContext& ctx) {
    if (ctx.oC_SymbolicName()) {
        return transformSymbolicName(*ctx.oC_SymbolicName());
    } else if (ctx.rU_UnionType()) {
        return transformUnionType(*ctx.rU_UnionType());
    } else if (ctx.rU_StructType()) {
        return transformStructType(*ctx.rU_StructType());
    } else if (ctx.rU_MapType()) {
        return transformMapType(*ctx.rU_MapType());
    } else if (ctx.rU_DecimalType()) {
        return transformDecimalType(*ctx.rU_DecimalType());
    } else {
        return transformDataType(*ctx.rU_DataType()) + ctx.rU_ListIdentifiers()->getText();
    }
}

std::string Transformer::transformPrimaryKey(CypherParser::RU_CreateNodeConstraintContext& ctx) {
    return transformPropertyKeyName(*ctx.oC_PropertyKeyName());
}

std::string Transformer::transformPrimaryKey(CypherParser::RU_ColumnDefinitionContext& ctx) {
    return transformPropertyKeyName(*ctx.oC_PropertyKeyName());
}

} // namespace parser
} // namespace ryu
