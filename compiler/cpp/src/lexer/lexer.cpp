#include "lexer/lexer.hpp"

namespace macs {

Lexer::Lexer(std::string source) : source_(std::move(source)) {}

std::vector<Token> Lexer::tokenize() {
    return {};
}

} // namespace macs