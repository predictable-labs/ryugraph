#include "parser/transformer.h"
#include "parser/use_database.h"

namespace ryu {
namespace parser {

std::unique_ptr<Statement> Transformer::transformUseDatabase(
    CypherParser::RU_UseDatabaseContext& ctx) {
    auto dbName = transformSchemaName(*ctx.oC_SchemaName());
    return std::make_unique<UseDatabase>(std::move(dbName));
}

} // namespace parser
} // namespace ryu
