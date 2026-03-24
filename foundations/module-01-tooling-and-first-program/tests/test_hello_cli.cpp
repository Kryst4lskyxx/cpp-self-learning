#include "assertions.h"

#include <array>
#include <cstdio>
#include <stdexcept>
#include <string>
#include <sys/wait.h>

namespace {

std::string run_program(const std::string& command) {
    std::array<char, 256> buffer{};
    std::string output;

    FILE* pipe = popen(command.c_str(), "r");
    if (pipe == nullptr) {
        throw std::runtime_error("failed to start program");
    }

    while (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe) != nullptr) {
        output += buffer.data();
    }

    const int status = pclose(pipe);
    if (status == -1 || !WIFEXITED(status) || WEXITSTATUS(status) != 0) {
        throw std::runtime_error("program exited with an error");
    }

    return output;
}

} // namespace

TEST_CASE("hello cli prints a greeting") {
    CHECK(run_program(MODULE_01_ASSIGNMENT_EXE) == "hello modern cpp\n");
}
