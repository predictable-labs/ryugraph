#pragma once

#include "common/exception/internal.h"
#include "common/string_format.h"

namespace ryu {
namespace common {

[[noreturn]] inline void ryuAssertFailureInternal(const char* condition_name, const char* file,
    int linenr) {
    // LCOV_EXCL_START
    throw InternalException(stringFormat("Assertion failed in file \"{}\" on line {}: {}", file,
        linenr, condition_name));
    // LCOV_EXCL_STOP
}

#define RYU_ASSERT_UNCONDITIONAL(condition)                                                        \
    static_cast<bool>(condition) ?                                                                 \
        void(0) :                                                                                  \
        ryu::common::ryuAssertFailureInternal(#condition, __FILE__, __LINE__)

#if defined(RYU_RUNTIME_CHECKS) || !defined(NDEBUG)
#define RUNTIME_CHECK(code) code
#define RYU_ASSERT(condition) RYU_ASSERT_UNCONDITIONAL(condition)
#else
#define RYU_ASSERT(condition) void(0)
#define RUNTIME_CHECK(code) void(0)
#endif

#define RYU_UNREACHABLE                                                                            \
    /* LCOV_EXCL_START */ [[unlikely]] ryu::common::ryuAssertFailureInternal("RYU_UNREACHABLE",    \
        __FILE__, __LINE__) /* LCOV_EXCL_STOP */
#define RYU_UNUSED(expr) (void)(expr)

} // namespace common
} // namespace ryu
