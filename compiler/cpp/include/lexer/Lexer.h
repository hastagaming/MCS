#pragma once
#include <string>
#include <vector>
#include <unordered_map>

enum TokenType {
    // keywords
    KW_FUNC, KW_ST, KW_LET, KW_MUT, KW_COMP, KW_IS, KW_NOT, KW_IF,
    KW_BUT, KW_ELIF, KW_ELSE, KW_LOOP, KW_BREAK, KW_CONTINUE, KW_WAITING,
    KW_NON, KW_TS, KW_SHP, KW_IMPL, KW_WHEN, KW_COPY, KW_REF,
    KW_JSON, KW_URL, KW_IMG, KW_SAFE, KW_DEFER, KW_GUARD,
    KW_USMD, KW_USE, KW_EVENT, KW_LISTEN, KW_NATIVE, KW_SPAWN, KW_TASK,
    KW_ENUM, KW_SYS, KW_DB, KW_HTTP, KW_FILE, KW_WEB,
    // literals
    LIT_INT, LIT_FLOAT, LIT_STRING, LIT_BOOL,
    // identifiers & operators
    IDENT,
    LBRACE, RBRACE, LPAREN, RPAREN, LBRACK, RBRACK,
    COLON, SEMI, COMMA, ARROW, FAT_ARROW, DOT, DBLCOLON,
    PLUS, MINUS, STAR, SLASH, PERCENT,
    ASSIGN, EQUAL, NOTEQUAL, AND, OR, NOTOP,
    // special
    INDENT, DEDENT, NEWLINE, END_OF_FILE
};

struct Token {
    TokenType type;
    std::string lexeme;
    int line, col;
};

class Lexer {
public:
    Lexer(const std::string& source);
    std::vector<Token> tokenize();
private:
    std::string source;
    size_t pos = 0;
    int line = 1, col = 1;
    std::vector<int> indentStack;
    void skipWhitespaceAndComments();
    Token indentOrDedent();
    Token readString();
    Token readNumber();
    Token readIdentifierOrKeyword();
    Token readOperator();
    void emitError(const std::string& msg);
};