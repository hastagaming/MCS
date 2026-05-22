#pragma once
#include <vector>
#include "lexer/token.hpp"

namespace macs {

class Parser {
public:
    explicit Parser(const std::vector<Token>& tokens);
    void parse();

private:
    const std::vector<Token>& tokens_;
};

} // namespace macs