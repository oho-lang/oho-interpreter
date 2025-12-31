#pragma once

#include "token.hpp"
#include "instruction.hpp"

#include <vector>

class Parser {
    std::vector<Token> tokens_{};
    uint32_t current_ = 0;
public:
    Parser() = default;
    ~Parser() = default;

    Inst parseNext();

    std::vector<Inst> parse(const std::vector<Token> &tokens);
};