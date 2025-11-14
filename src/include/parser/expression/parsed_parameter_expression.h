#pragma once

#include "common/assert.h"
#include "parsed_expression.h"

namespace ryu {
namespace parser {

class ParsedParameterExpression : public ParsedExpression {
public:
    explicit ParsedParameterExpression(std::string parameterName, std::string raw)
        : ParsedExpression{common::ExpressionType::PARAMETER, std::move(raw)},
          parameterName{std::move(parameterName)} {}

    inline std::string getParameterName() const { return parameterName; }

    static std::unique_ptr<ParsedParameterExpression> deserialize(common::Deserializer&) {
        RYU_UNREACHABLE;
    }

    inline std::unique_ptr<ParsedExpression> copy() const override { RYU_UNREACHABLE; }

private:
    void serializeInternal(common::Serializer&) const override { RYU_UNREACHABLE; }

private:
    std::string parameterName;
};

} // namespace parser
} // namespace ryu
