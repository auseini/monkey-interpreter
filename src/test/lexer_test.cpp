#include <gtest/gtest.h>
#include <string>
#include "../token.h"
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
        {token::ENDOFFILE, "EOF"},
    };


    

    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7*6, 42);
}
