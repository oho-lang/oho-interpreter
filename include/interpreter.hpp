#pragma once

#include "instruction.hpp"
#include "token.hpp"
#include "lexer.hpp"
#include "parser.hpp"

#include <unordered_map>
#include <cstdint>

class Interpreter {
    static constexpr size_t MEM_VAR = 1;
    static constexpr size_t JMP_VAR = 2;

    Lexer lexer_;
    Parser parser_;
    std::vector<Inst> instructions_;
    std::size_t current_inst_ = 0;
    std::unordered_map<uint32_t, int32_t> variables_ = {
        {0, 0}, {1, 0}
    };
    std::vector<int32_t> vmem_{};
public:
    Interpreter() = default;
    ~Interpreter() = default;

    void load(const std::string &source);
    std::string to_readable();
    void run();
private:
    void execute(const Inst& inst);
    void executeAdd(const Inst& inst);
    void executeSub(const Inst& inst);
    void executeLoad(const Inst& inst);
    void executeStore(const Inst& inst);
    void executeJump(const Inst& inst);
    void executePrint(const Inst& inst);
    
    int32_t& getVar(uint32_t var_id) {
        if (variables_.find(var_id) == variables_.end()) {
            variables_[var_id] = 0;
        }
        return variables_[var_id];
    }
    int32_t& getVmem(uint32_t addr) {
        if (addr >= vmem_.size()) {
            vmem_.resize(addr + 1, 0);
        }
        return vmem_[addr];
    }
};