#pragma once
#include <iostream>
#include <cctype>
#include <string>
#include "token.h"

class Lexer {
    public:
        Lexer(std::string input) : input(input), position(0), read_position(0), ch('\0') {
            read_char();
        }

        token::Token next_token() {
            token::Token tok;

            skip_whitespace();

            switch(ch) {
                case '=':
                    tok = {token::ASSIGN, {ch}};
                    break;
                case '+':
                    tok = {token::PLUS, {ch}};
                    break;
                case '-':
                    tok = {token::MINUS, {ch}};
                    break;
                case '!':
                    tok = {token::BANG, {ch}};
                    break;
                case '/':
                    tok = {token::SLASH, {ch}};
                    break;
                case '*':
                    tok = {token::ASTERISK, {ch}};
                    break;
                case '<':
                    tok = {token::LT, {ch}};
                    break;
                case '>':
                    tok = {token::GT, {ch}};
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
                case '{':
                    tok = {token::LBRACE, {ch}};
                    break;
                case '}':
                    tok = {token::RBRACE, {ch}};
                    break;
                case '\0':
                    tok = {token::ENDOFFILE, ""};
                    break;
                default:
                    if (is_letter(ch)){
                        tok.literal = read_identifier();
                        tok.type = token::lookup_ident(tok.literal);
                        return tok;
                    } else if (is_digit(ch)) {
                        tok.type = token::INT;
                        tok.literal = read_number();
                        return tok;
                    } else {
                        tok = {token::ILLEGAL, {ch}};
                    }
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
        
        std::string read_identifier() {
            int start_position = position;
            while (is_letter(ch)){
                read_char();
            }

            return input.substr(start_position, position - start_position);
        }

        std::string read_number() {
            int start_position = position;
            while (is_digit(ch)) {
                read_char();
            }
            
            return input.substr(start_position, position - start_position);
        }

        bool is_letter(char c) {
            return std::isalpha(static_cast<unsigned char>(c)) || c == '_';
        }

        bool is_digit(char d) {
            return std::isdigit(static_cast<unsigned char>(d));
        }
        
        void skip_whitespace() {
            while (std::isspace(static_cast<unsigned char>(ch))) {
                read_char();
            }
        }
};
