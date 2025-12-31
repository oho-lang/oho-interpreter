#pragma once

#include "token.hpp"

#include <vector>
#include <unordered_set>

class Lexer {
    static std::unordered_set<std::string> TokenStrings;

    std::string source_{};
    uint32_t current_ = 0;
    TokenType current_type_{};
public:
    Lexer() = default;
    ~Lexer() = default;

    Token lexNext();

    std::vector<Token> tokenize(const std::string &source);
};