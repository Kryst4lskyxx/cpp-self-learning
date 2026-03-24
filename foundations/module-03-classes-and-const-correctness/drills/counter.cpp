#include "counter.h"

#include <iostream>

Counter::Counter(std::size_t start) : value_{start} {}

void Counter::increment() noexcept {
    ++value_;
}

void Counter::reset(std::size_t start) noexcept {
    value_ = start;
}

std::size_t Counter::value() const noexcept {
    return value_;
}

int main() {
    Counter counter{2};
    counter.increment();
    std::cout << counter.value() << '\n';
    return 0;
}
