#include "utils.hpp"
#include <fstream>
#include <sstream>

std::string readFile(const std::string &filepath) {
    std::fstream file_stream(filepath);
    if (!file_stream.is_open()) {
        throw std::runtime_error("Could not open file: " + filepath);
    }
    std::stringstream buffer;
    buffer << file_stream.rdbuf();
    return buffer.str();
}

std::string saveFile(const std::string &filepath, const std::string &content) {
    std::ofstream file_stream(filepath);
    if (!file_stream.is_open()) {
        throw std::runtime_error("Could not open file for writing: " + filepath);
    }
    file_stream << content;
    return filepath;
}