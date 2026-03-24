#include "assertions.h"

#include "contract_checks.h"

#include <vector>

TEST_CASE("algorithm contract helper accepts sorted lookup input") {
    const std::vector<int> values{1, 2, 2, 4, 8};
    CHECK(is_sorted_for_binary_search(values) == true);
}

TEST_CASE("algorithm contract helper rejects unsorted lookup assumptions") {
    const std::vector<int> values{3, 1, 2};
    CHECK(is_sorted_for_binary_search(values) == false);
}
