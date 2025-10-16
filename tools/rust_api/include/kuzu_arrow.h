#pragma once

#include "rust/cxx.h"
#ifdef KUZU_BUNDLED
#include "main/ryu.h"
#else
#include <kuzu.hpp>
#endif

namespace ryu_arrow {

ArrowSchema query_result_get_arrow_schema(const ryu::main::QueryResult& result);
ArrowArray query_result_get_next_arrow_chunk(ryu::main::QueryResult& result, uint64_t chunkSize);

} // namespace ryu_arrow
