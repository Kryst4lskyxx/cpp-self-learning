#include "assertions.h"

#include <exception>
#include <iostream>
#include <string_view>
#include <vector>

namespace cpp_self_learning::testing {

namespace {

struct RegisteredTestCase {
    std::string_view name;
    void (*function)();
};

std::vector<RegisteredTestCase>& test_cases() {
    static std::vector<RegisteredTestCase> cases;
    return cases;
}

int& failure_count() {
    static int count = 0;
    return count;
}

} // namespace

bool register_test_case(const char* name, void (*function)()) {
    test_cases().push_back({name, function});
    return true;
}

void record_check(bool condition, const char* expression, const char* file, int line) {
    if (condition) {
        return;
    }

    ++failure_count();
    std::cerr << file << ":" << line << ": CHECK(" << expression << ") failed\n";
}

int run_all_test_cases() {
    if (test_cases().empty()) {
        std::cerr << "No test cases registered\n";
        return 1;
    }

    for (const auto& test_case : test_cases()) {
        std::cout << "[ RUN      ] " << test_case.name << '\n';
        try {
            test_case.function();
        } catch (const std::exception& exception) {
            ++failure_count();
            std::cerr << "[  EXCEPT   ] " << test_case.name << ": " << exception.what() << '\n';
        } catch (...) {
            ++failure_count();
            std::cerr << "[  EXCEPT   ] " << test_case.name << ": unknown exception\n";
        }
    }

    return failure_count() == 0 ? 0 : 1;
}

} // namespace cpp_self_learning::testing
