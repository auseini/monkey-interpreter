#pragma once
#include <string>

namespace token {

    struct Token {
        std::string type;
        std::string literal;
    };

    typedef const std::string token;
    token ILLEGAL = "ILLEGAL";
    token ENDOFFILE= "EOF";

    //identifiers + literals
    token IDENT = "IDENT";
    token INT = "INT";

    //operators
    token ASSIGN = "=";
    token PLUS = "+";

    // delimiters
    token COMMA = ",";
    token SEMICOLON = ";";
    token LPAREN = "(";
    token RPAREN = ")";
    token LBRACE = "{";
    token RBRACE = "}";

    // keywords
    token FUNCTION = "FUNCTION";
    token LET = "LET";
};
