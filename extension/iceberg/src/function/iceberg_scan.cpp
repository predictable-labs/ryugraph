#include "function/iceberg_functions.h"

namespace ryu {
namespace iceberg_extension {

using namespace function;
using namespace common;

std::unique_ptr<TableFuncBindData> scanBindFunc(main::ClientContext* context,
    const TableFuncBindInput* input) {
    return bindFuncHelper(context, input, IcebergScanFunction::name);
}

function_set IcebergScanFunction::getFunctionSet() {
    function_set functionSet;
    auto function = std::make_unique<TableFunction>(name, std::vector{LogicalTypeID::STRING});
    function->tableFunc = delta_extension::tableFunc;
    function->bindFunc = scanBindFunc;
    function->initSharedStateFunc = delta_extension::initDeltaScanSharedState;
    function->initLocalStateFunc = function::TableFunction::initEmptyLocalState;
    functionSet.push_back(std::move(function));
    return functionSet;
}

} // namespace iceberg_extension
} // namespace ryu
