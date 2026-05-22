#pragma once
#include <string>

namespace macs {

enum class TokenType {
    Keyword,
    Identifier,
    Number,
    String,
    Symbol,
    Operator,
    Comment,
    Eof
};

struct Token {
    TokenType type;
    std::string lexeme;
    int line;
    int column;
};

} // namespace macs