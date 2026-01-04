#pragma once

#include <string>
#include "instruction.hpp"

std::string readFile(const std::string &filepath);
std::string saveFile(const std::string &filepath, const std::string &content);

std::size_t getUTF8ByteCount(int32_t value);