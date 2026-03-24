#include "assertions.h"

#include "query_engine.h"

#include <iterator>
#include <vector>

TEST_CASE("query engine filters values using generic predicates") {
    const std::vector<int> values{1, 2, 3, 4, 5};
    const auto evens = filter_values(values, [](int value) { return value % 2 == 0; });
    const std::vector<int> expected{2, 4};

    CHECK(evens == expected);
}

namespace {

struct IntBag {
    int values[5]{1, 2, 3, 4, 5};

    const int* begin() const {
        return std::begin(values);
    }

    const int* end() const {
        return std::end(values);
    }
};

}  // namespace

TEST_CASE("query engine filters custom ranges without a value_type alias") {
    const IntBag values{};
    const auto odds = filter_values(values, [](int value) { return value % 2 != 0; });
    const std::vector<int> expected{1, 3, 5};

    CHECK(odds == expected);
}
