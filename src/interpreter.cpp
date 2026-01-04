#include "interpreter.hpp"
#include "instruction.hpp"

#include <print>
#include <string>

void Interpreter::load(const std::string &source) {
    auto tokens = lexer_.tokenize(source);
    instructions_ = parser_.parse(tokens);
}

void Interpreter::run() {
    current_inst_ = 0;
    while (current_inst_ < instructions_.size()) {
        auto& inst = instructions_[current_inst_];
        execute(inst);
        current_inst_++;
    }
}

std::string Interpreter::to_readable() {
    std::string result;
    for (const auto& inst : instructions_) {
        result += inst.to_string() + "\n";
    }
    return result;
}

void Interpreter::execute(const Inst& inst) {
    switch (inst.type) {
        case InstType::Add: executeAdd(inst); break;
        case InstType::Sub: executeSub(inst); break;
        case InstType::Load: executeLoad(inst); break;
        case InstType::Store: executeStore(inst); break;
        case InstType::Jump: executeJump(inst); break;
        case InstType::Print: executePrint(inst); break;
    }
}

void Interpreter::executeAdd(const Inst& inst) {
    auto& var = getVar(inst.var_id);
    var += inst.value;
}

void Interpreter::executeSub(const Inst& inst) {
    auto& var = getVar(inst.var_id);
    var -= inst.value;
}

void Interpreter::executeLoad(const Inst& inst) {
    auto& var = getVar(inst.var_id);
    auto& mem = getVar(MEM_VAR);
    var = getVmem(mem + inst.value);
}

void Interpreter::executeStore(const Inst& inst) {
    auto& var = getVar(inst.var_id);
    auto& mem = getVar(MEM_VAR);
    getVmem(mem + inst.value) = var;
}

void Interpreter::executeJump(const Inst& inst) {
    auto& var = getVar(inst.var_id);
    auto& jmp = getVar(JMP_VAR);
    if (jmp != 0) {
        current_inst_ = var + inst.value - 1; // -1 because run() will increment it
    }
}

void Interpreter::executePrint(const Inst& inst) {
    auto& var = getVar(inst.var_id);
    auto& mem = getVar(MEM_VAR);
    std::string output{};
    for (int i = 0; i < inst.value; i++) {
        auto value = getVmem(var + i);
        output += static_cast<uint32_t>(value);
        // output += static_cast<char>(getVmem(var + i));
    }
    std::print("{}", output);
}