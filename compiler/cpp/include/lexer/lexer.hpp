#pragma once
#include <string>
#include <vector>
#include "lexer/token.hpp"

namespace macs {

class Lexer {
public:
    explicit Lexer(std::string source);
    std::vector<Token> tokenize();

private:
    std::string source_;
};

} // namespace macs