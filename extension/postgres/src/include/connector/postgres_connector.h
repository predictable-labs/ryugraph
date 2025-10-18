#pragma once

#include "connector/duckdb_connector.h"

namespace ryu {
namespace postgres_extension {

class PostgresConnector : public duckdb_extension::DuckDBConnector {
public:
    void connect(const std::string& dbPath, const std::string& catalogName,
        const std::string& schemaName, main::ClientContext* context) override;
};

} // namespace postgres_extension
} // namespace ryu
