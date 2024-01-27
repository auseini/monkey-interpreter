#pragma once
#include <string>
#include "token.h"

class Lexer {
    public:
        Lexer(std::string input) : input(input) {}

        token::Token next_token() {
            read_char();
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
