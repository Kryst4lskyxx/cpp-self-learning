#include "assertions.h"

#include "ranker.h"

#include <vector>

TEST_CASE("ranker returns an empty result for empty input") {
    const std::vector<int> values{};

    const auto ranked = rank_values(values, [](int value) { return value * 10; });

    CHECK(ranked.empty());
}

TEST_CASE("ranker applies a caller-provided scoring function") {
    const std::vector<int> values{1, 3, 2};
    const auto ranked = rank_values(values, [](int value) { return value * 10; });

    CHECK(ranked.size() == 3);
    CHECK(ranked[0].value == 3);
    CHECK(ranked[1].value == 2);
    CHECK(ranked[2].value == 1);
    CHECK(ranked[0].score == 30);
    CHECK(ranked[1].score == 20);
    CHECK(ranked[2].score == 10);
}

TEST_CASE("ranker orders the full result from highest score to lowest") {
    const std::vector<int> values{4, 1, 3, 2};
    const auto ranked = rank_values(values, [](int value) { return value * value; });

    CHECK(ranked.size() == 4);
    CHECK(ranked[0].value == 4);
    CHECK(ranked[1].value == 3);
    CHECK(ranked[2].value == 2);
    CHECK(ranked[3].value == 1);
    CHECK(ranked[0].score == 16);
    CHECK(ranked[1].score == 9);
    CHECK(ranked[2].score == 4);
    CHECK(ranked[3].score == 1);
}

TEST_CASE("ranker preserves input order for tied scores") {
    const std::vector<int> values{2, 1, 3};
    const auto ranked = rank_values(values, [](int) { return 10; });

    CHECK(ranked.size() == 3);
    CHECK(ranked[0].value == 2);
    CHECK(ranked[1].value == 1);
    CHECK(ranked[2].value == 3);
}
