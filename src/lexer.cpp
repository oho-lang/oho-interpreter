#include "lexer.hpp"
#include "token.hpp"

std::unordered_set<std::string> Lexer::TokenStrings = std::unordered_set<std::string>{
    CN_O, CN_HO, CN_BANG,
    JP_O, JP_HO, JP_BANG
};

Token Lexer::lexNext() {
    uint32_t count = 0;
    auto lex_type = current_type_;
    switch (lex_type) {
        case TokenType::O:
            while (source_.substr(current_, STEP) == CN_O || source_.substr(current_, STEP) == JP_O) {
                count++;
                current_ += STEP;
            }
            current_type_ = TokenType::Ho;
            break;
        case TokenType::Ho:
            while (source_.substr(current_, STEP) == CN_HO || source_.substr(current_, STEP) == JP_HO) {
                count++;
                current_ += STEP;
            }
            current_type_ = TokenType::Bang;
            break;
        case TokenType::Bang:
            while (source_.substr(current_, STEP) == CN_BANG || source_.substr(current_, STEP) == JP_BANG) {
                count++;
                current_ += STEP;
            }
            current_type_ = TokenType::O;
            break;
    }
    if (count == 0) {
        throw std::runtime_error("Lexing error: unexpected token at position " + std::to_string(current_));
    }
    return Token(lex_type, count);
}

std::vector<Token> Lexer::tokenize(const std::string &source) {
    this->source_ = source;
    this->current_ = 0;
    this->current_type_ = TokenType::O;
    std::vector<Token> tokens;

    while (current_ < source.size()) {
        while (TokenStrings.find(source_.substr(current_, STEP)) == TokenStrings.end()) {
            current_++;
        }
        tokens.push_back(lexNext());
    }

    return tokens;
}