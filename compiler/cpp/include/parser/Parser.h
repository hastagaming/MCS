#pragma once
#include "lexer/Lexer.h"
#include "ast/AST.h"
#include <memory>

class Parser {
public:
    Parser(const std::vector<Token>& tokens);
    std::unique_ptr<Program> parse();
private:
    const std::vector<Token>& tokens;
    size_t idx = 0;
    const Token& peek();
    const Token& advance();
    bool match(TokenType t);
    void expect(TokenType t);
    void error(const std::string& msg);
    // recursive descent methods
    std::unique_ptr<ASTNode> parseTopLevel();
    std::unique_ptr<FunctionDef> parseFunction(bool isStart);
    // ... many more
};