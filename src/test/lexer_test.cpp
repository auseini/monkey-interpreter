#include <gtest/gtest.h>
#include <string>
#include "../token.h"
#include "../lexer.h"
TEST(LexerTest, TestNextToken) {
    std::string input = "=+(){},;";

    token::Token tests[] = {
        {token::ASSIGN, "="},
        {token::PLUS, "+"},
        {token::LPAREN, "("},
        {token::RPAREN, ")"},
        {token::LBRACE, "{"},
        {token::RBRACE, "}"},
        {token::COMMA, ","},
        {token::SEMICOLON, ";"},
        {token::ENDOFFILE, {'\0'}},
    };

    Lexer l(input);
    
    for (auto& token : tests){
        token::Token tok = l.next_token();
        EXPECT_EQ(tok.type, token.type);
        EXPECT_EQ(tok.literal, token.literal);
    }
}
