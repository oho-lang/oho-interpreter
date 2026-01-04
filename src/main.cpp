#include "interpreter.hpp"
#include "utils.hpp"

int main(int argc, char** argv) {
    auto interpreter = Interpreter();
    // auto source = readFile(argv[1]);
    auto source = readFile("/Users/fyvoid/src/oho-lang/example.oho");
    interpreter.load(source);
    interpreter.run();
    return 0;
}
