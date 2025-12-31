#include "utils.hpp"

std::string readFile(const std::string &filepath) {
    std::fstream file_stream(filepath);
    if (!file_stream.is_open()) {
        throw std::runtime_error("Could not open file: " + filepath);
    }
    std::stringstream buffer;
    buffer << file_stream.rdbuf();
    return buffer.str();
}