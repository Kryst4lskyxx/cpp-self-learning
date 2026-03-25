#include "assertions.h"

#include "ranker.h"

#include <vector>

TEST_CASE("ranker applies a caller-provided scoring function") {
    const std::vector<int> values{1, 3, 2};
    const auto ranked = rank_values(values, [](int value) { return value * 10; });
    CHECK(ranked.front().value == 3);
}
