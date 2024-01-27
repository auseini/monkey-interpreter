#pragma once
#include <string>
#include <unordered_map>

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

    const std::unordered_map<std::string, token> keywords = {{"fn", FUNCTION}, {"let", LET}};
    
    inline token lookup_ident(std::string ident) {
        if(keywords.find(ident) != keywords.end()) {
            return keywords.at(ident);
        }

        return IDENT;
    }
};
