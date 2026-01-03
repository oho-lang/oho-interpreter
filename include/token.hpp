#pragma once

#include <cstdint>
#include <string>
#include "instruction.hpp"

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

constexpr const char* CN_O    = "\xe5\x93\xa6";   // 哦
constexpr const char* CN_HO   = "\xe9\xbd\x81";   // 齁
constexpr const char* CN_BANG = "\xef\xbc\x81";   // ！
constexpr const char* JP_O    = "\xe3\x82\xaa";   // オ
constexpr const char* JP_HO   = "\xe3\x83\x9b";   // ホ
constexpr const char* JP_BANG = "\xef\xbc\x81";   // ！