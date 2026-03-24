#pragma once

namespace cpp_self_learning::testing {

bool register_test_case(const char* name, void (*function)());
void record_check(bool condition, const char* expression, const char* file, int line);
int run_all_test_cases();

} // namespace cpp_self_learning::testing

#define CPP_SELF_LEARNING_CONCAT_INNER(left, right) left##right
#define CPP_SELF_LEARNING_CONCAT(left, right) CPP_SELF_LEARNING_CONCAT_INNER(left, right)

#define TEST_CASE(name_literal) \
    static void CPP_SELF_LEARNING_CONCAT(test_case_function_, __LINE__)(); \
    namespace { \
    const bool CPP_SELF_LEARNING_CONCAT(test_case_registration_, __LINE__) = \
        ::cpp_self_learning::testing::register_test_case((name_literal), &CPP_SELF_LEARNING_CONCAT(test_case_function_, __LINE__)); \
    } \
    static void CPP_SELF_LEARNING_CONCAT(test_case_function_, __LINE__)()

#define CHECK(expression) \
    ::cpp_self_learning::testing::record_check((expression), #expression, __FILE__, __LINE__)
