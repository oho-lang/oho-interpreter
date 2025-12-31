#pragma once

#include <cstdint>
#include <string>

enum class TokenType {
    O, Ho, Bang
};

struct Token {
    TokenType type;
    int32_t value;

    Token(TokenType type, int32_t value)
        : type(type), value(value) {}

    std::string to_string() const {
        switch (type) {
            case TokenType::O:
                return "O(" + std::to_string(value) + ")";
            case TokenType::Ho:
                return "Ho(" + std::to_string(value) + ")";
            case TokenType::Bang:
                return "Bang(" + std::to_string(value) + ")";
        }
    }
};

constexpr size_t STEP = 3;

constexpr std::string CN_O = "哦";
constexpr std::string CN_HO = "齁";
constexpr std::string CN_BANG = "！";
constexpr std::string JP_O = "オ";
constexpr std::string JP_HO = "ホ";
constexpr std::string JP_BANG = "！";