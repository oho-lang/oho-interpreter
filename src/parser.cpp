#include "parser.hpp"

Inst Parser::parseNext() {
    auto& type = tokens_[current_++];
    auto& var = tokens_[current_++];
    auto& value = tokens_[current_++];
    return Inst(static_cast<InstType>(type.value), var.value, value.value);
}

std::vector<Inst> Parser::parse(const std::vector<Token> &tokens) {
    this->tokens_ = tokens;
    this->current_ = 0;
    std::vector<Inst> instructions;

    while (current_ < tokens.size()) {
        instructions.push_back(parseNext());
    }

    return instructions;
}