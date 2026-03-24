#include "assertions.h"

#include "query_engine.h"

#include <vector>

TEST_CASE("query engine filters values using generic predicates") {
    const std::vector<int> values{1, 2, 3, 4, 5};
    const auto evens = filter_values(values, [](int value) { return value % 2 == 0; });
    const std::vector<int> expected{2, 4};

    CHECK(evens == expected);
}
