#pragma once

#include <cstdint>

#include "token.hpp"

enum class InstType {
    Add = 1, Sub = 2, Load = 3, Store = 4, Jump = 5, Print = 6
};

struct Inst {
    InstType type;
    uint32_t var_id;
    int32_t value;

    Inst(InstType type, uint32_t var_id, int32_t value)
        : type(type), var_id(var_id), value(value) {}

    std::string to_string() const {
        switch (type) {
            case InstType::Add:
                return "Add var#" + std::to_string(var_id) + " " + std::to_string(value);
            case InstType::Sub:
                return "Sub var#" + std::to_string(var_id) + " " + std::to_string(value);
            case InstType::Load:
                return "Load var#" + std::to_string(var_id) + " " + std::to_string(value);
            case InstType::Store:
                return "Store var#" + std::to_string(var_id) + " " + std::to_string(value);
            case InstType::Jump:
                return "Jump var#" + std::to_string(var_id) + " " + std::to_string(value);
            case InstType::Print:
                return "Print var#" + std::to_string(var_id) + " " + std::to_string(value);
        }
    }
};