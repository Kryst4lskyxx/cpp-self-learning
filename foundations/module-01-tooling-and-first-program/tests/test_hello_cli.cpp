#include "assertions.h"

#include <cstddef>
#include <array>
#include <cstdio>
#include <stdexcept>
#include <string>
#include <sys/wait.h>
#include <unistd.h>

namespace {

std::string run_program(const std::string& command) {
    std::string output;
    std::array<char, 256> read_buffer{};
    int pipefd[2];

    if (pipe(pipefd) != 0) {
        throw std::runtime_error("failed to create pipe");
    }

    const pid_t pid = fork();
    if (pid == -1) {
        close(pipefd[0]);
        close(pipefd[1]);
        throw std::runtime_error("failed to fork");
    }

    if (pid == 0) {
        close(pipefd[0]);
        if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
            _exit(127);
        }
        close(pipefd[1]);
        execl(command.c_str(), command.c_str(), static_cast<char*>(nullptr));
        _exit(127);
    }

    close(pipefd[1]);

    ssize_t bytes_read = 0;
    while ((bytes_read = read(pipefd[0], read_buffer.data(), read_buffer.size())) > 0) {
        output.append(read_buffer.data(), static_cast<std::size_t>(bytes_read));
    }
    if (bytes_read == -1) {
        close(pipefd[0]);
        throw std::runtime_error("failed to read program output");
    }
    close(pipefd[0]);

    int status = 0;
    if (waitpid(pid, &status, 0) == -1 || !WIFEXITED(status) || WEXITSTATUS(status) != 0) {
        throw std::runtime_error("program exited with an error");
    }

    return output;
}

} // namespace

TEST_CASE("hello cli prints a greeting") {
    CHECK(run_program(MODULE_01_ASSIGNMENT_EXE) == "hello modern cpp\n");
}
