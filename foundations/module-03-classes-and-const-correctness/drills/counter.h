#ifndef FOUNDATIONS_MODULE_03_CLASSES_AND_CONST_CORRECTNESS_DRILLS_COUNTER_H_
#define FOUNDATIONS_MODULE_03_CLASSES_AND_CONST_CORRECTNESS_DRILLS_COUNTER_H_

#include <cstddef>

class Counter {
public:
    explicit Counter(std::size_t start = 0);

    void increment() noexcept;
    void reset(std::size_t start = 0) noexcept;

    std::size_t value() const noexcept;

private:
    std::size_t value_{};
};

#endif  // FOUNDATIONS_MODULE_03_CLASSES_AND_CONST_CORRECTNESS_DRILLS_COUNTER_H_
