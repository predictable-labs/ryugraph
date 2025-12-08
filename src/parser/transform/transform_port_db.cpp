#include "parser/port_db.h"
#include "parser/transformer.h"

using namespace ryu::common;

namespace ryu {
namespace parser {

std::unique_ptr<Statement> Transformer::transformExportDatabase(
    CypherParser::RU_ExportDatabaseContext& ctx) {
    std::string filePath = transformStringLiteral(*ctx.StringLiteral());
    auto exportDB = std::make_unique<ExportDB>(std::move(filePath));
    if (ctx.rU_Options()) {
        exportDB->setParsingOption(transformOptions(*ctx.rU_Options()));
    }
    return exportDB;
}

std::unique_ptr<Statement> Transformer::transformImportDatabase(
    CypherParser::RU_ImportDatabaseContext& ctx) {
    std::string filePath = transformStringLiteral(*ctx.StringLiteral());
    return std::make_unique<ImportDB>(std::move(filePath));
}

} // namespace parser
} // namespace ryu
