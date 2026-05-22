#pragma once
#include "ast/ast.hpp"

namespace macs {

class SemanticAnalyzer {
public:
    void analyze(const Program& program);
};

} // namespace macs