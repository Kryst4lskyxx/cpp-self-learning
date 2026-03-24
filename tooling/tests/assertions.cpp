#include "assertions.h"

#include <stdexcept>

void assert_true(bool condition) {
    if (!condition) {
        throw std::runtime_error("assert_true failed");
    }
}
