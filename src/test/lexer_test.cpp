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
        {token::ENDOFFILE, ""},
    };

    Lexer l(input);
    
    for (auto& token : tests){
        token::Token tok = l.next_token();
        EXPECT_EQ(tok.type, token.type);
        EXPECT_EQ(tok.literal, token.literal);
    }
}

TEST(LexerTest, TestSimpleProgram) {

    std::string input =
        "let five = 5;"
        "let ten = 10;"
        "let add = fn(x, y) {"
        " x+y;"
        "};"
        "let result = add(five, ten);";
        

    token::Token tests[] = {
        {token::LET, "let"},
        {token::IDENT, "five"},
        {token::ASSIGN, "="},
        {token::INT, "5"},
        {token::SEMICOLON, ";"},
        {token::LET, "let"},
        {token::IDENT, "ten"},
        {token::ASSIGN, "="},
        {token::INT, "10"},
        {token::SEMICOLON, ";"},
        {token::LET, "let"},
        {token::IDENT, "add"},
        {token::ASSIGN, "="},
        {token::FUNCTION, "fn"},
        {token::LPAREN, "("},
        {token::IDENT, "x"},
        {token::COMMA, ","},
        {token::IDENT, "y"},
        {token::RPAREN, ")"},
        {token::LBRACE, "{"},
        {token::IDENT, "x"},
        {token::PLUS, "+"},
        {token::IDENT, "y"},
        {token::SEMICOLON, ";"},
        {token::RBRACE, "}"},
        {token::SEMICOLON, ";"},
        {token::LET, "let"},
        {token::IDENT, "result"},
        {token::ASSIGN, "="},
        {token::IDENT, "add"},
        {token::LPAREN, "("},
        {token::IDENT, "five"},
        {token::COMMA, ","},
        {token::IDENT, "ten"},
        {token::RPAREN, ")"},
        {token::SEMICOLON, ";"},
        {token::ENDOFFILE, ""}
    };

    Lexer l(input);

    for (auto& token : tests){
        token::Token tok = l.next_token();
        EXPECT_EQ(tok.type, token.type);
        EXPECT_EQ(tok.literal, token.literal);
    }
}

TEST(LexerTest, TestSimpleProgramWithMoreOperators) {

    std::string input =
        "let five = 5;"
        "let ten = 10;"
        "let add = fn(x, y) {"
        " x+y;"
        "};"
        "let result = add(five, ten);"
        "!-/*5;"
        "5 < 10 > 5;";
        

    token::Token tests[] = {
        {token::LET, "let"},
        {token::IDENT, "five"},
        {token::ASSIGN, "="},
        {token::INT, "5"},
        {token::SEMICOLON, ";"},
        {token::LET, "let"},
        {token::IDENT, "ten"},
        {token::ASSIGN, "="},
        {token::INT, "10"},
        {token::SEMICOLON, ";"},
        {token::LET, "let"},
        {token::IDENT, "add"},
        {token::ASSIGN, "="},
        {token::FUNCTION, "fn"},
        {token::LPAREN, "("},
        {token::IDENT, "x"},
        {token::COMMA, ","},
        {token::IDENT, "y"},
        {token::RPAREN, ")"},
        {token::LBRACE, "{"},
        {token::IDENT, "x"},
        {token::PLUS, "+"},
        {token::IDENT, "y"},
        {token::SEMICOLON, ";"},
        {token::RBRACE, "}"},
        {token::SEMICOLON, ";"},
        {token::LET, "let"},
        {token::IDENT, "result"},
        {token::ASSIGN, "="},
        {token::IDENT, "add"},
        {token::LPAREN, "("},
        {token::IDENT, "five"},
        {token::COMMA, ","},
        {token::IDENT, "ten"},
        {token::RPAREN, ")"},
        {token::SEMICOLON, ";"},
        {token::BANG, "!"},
        {token::MINUS, "-"},
        {token::SLASH, "/"},
        {token::ASTERISK, "*"},
        {token::INT, "5"},
        {token::SEMICOLON, ";"},
        {token::INT, "5"},
        {token::LT, "<"},
        {token::INT, "10"},
        {token::GT, ">"},
        {token::INT, "5"},
        {token::SEMICOLON, ";"},
        {token::ENDOFFILE, ""}
    };

    Lexer l(input);

    for (auto& token : tests){
        token::Token tok = l.next_token();
        EXPECT_EQ(tok.type, token.type);
        EXPECT_EQ(tok.literal, token.literal);
    }
}
