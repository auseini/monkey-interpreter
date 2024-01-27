#pragma once
#include <string>
#include "token.h"

class Lexer {
    public:
        Lexer(std::string input) : input(input), position(0), read_position(0), ch('\0') {
            read_char();
        }

        token::Token next_token() {
            token::Token tok;

            switch(ch) {
                case '=':
                    tok = {token::ASSIGN, {ch}};
                    break;
                case ';':
                    tok = {token::SEMICOLON, {ch}};
                    break;
                case '(':
                    tok = {token::LPAREN, {ch}};
                    break;
                case ')':
                    tok = {token::RPAREN, {ch}};
                    break;
                case ',':
                    tok = {token::COMMA, {ch}};
                    break;
                case '+':
                    tok = {token::PLUS, {ch}};
                    break;
                case '{':
                    tok = {token::LBRACE, {ch}};
                    break;
                case '}':
                    tok = {token::RBRACE, {ch}};
                    break;
                case '\0':
                    tok = {token::ENDOFFILE, {'\0'}};
                    break;
            }
            read_char();
            return tok;
        }

    private:
        std::string input;
        int position;
        int read_position;
        char ch;

        void read_char() {
            if (read_position >= input.length()) {
                ch = '\0';
            } else {
                ch = input[read_position];
            }

            position = read_position;
            read_position++;
        }
};
