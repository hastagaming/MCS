#pragma once
#include "ast/ast.hpp"
#include <string>

namespace macs {

class CodeGen {
public:
    std::string emitLLVMIR(const Program& program);
};

} // namespace macs