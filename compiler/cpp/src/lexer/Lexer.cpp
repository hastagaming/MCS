#include "lexer/Lexer.h"
#include <iostream>
#include <cctype>

Lexer::Lexer(const std::string& source) : source(source) {
    indentStack.push_back(0);
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (pos < source.size()) {
        skipWhitespaceAndComments();
        if (pos >= source.size()) break;

        // handle indentation at beginning of line
        if (col == 1 && source[pos] != '\n') {
            int spaces = 0;
            while (pos < source.size() && source[pos] == ' ') { spaces++; pos++; col++; }
            if (source[pos] == '\t') emitError("tabs are not allowed");

            int prev = indentStack.back();
            if (spaces > prev) {
                indentStack.push_back(spaces);
                tokens.push_back({INDENT, "", line, col});
            } else while (spaces < prev) {
                indentStack.pop_back();
                tokens.push_back({DEDENT, "", line, col});
                prev = indentStack.back();
            }
            if (spaces != prev) emitError("inconsistent indentation");
            continue;
        }

        // single-char tokens
        char c = source[pos];
        if (c == '\n') { tokens.push_back({NEWLINE, "\n", line, col}); pos++; line++; col=1; continue; }
        if (c == '{') { tokens.push_back({LBRACE, "{", line, col++}); pos++; continue; }
        // ... (simplified) 
        // For brevity, full token recognition omitted; assume complete implementation.
        emitError("unexpected character");
    }
    tokens.push_back({END_OF_FILE, "", line, col});
    return tokens;
}

void Lexer::emitError(const std::string& msg) {
    std::cerr << "\033[1;31m[MCS-ERROR-" << line << "]:\033[0m " << msg << std::endl;
    exit(1);
}