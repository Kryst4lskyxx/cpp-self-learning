#include "assertions.h"

#include "pipeline.h"

#include <vector>

TEST_CASE("pipeline handles empty input") {
    const std::vector<std::string> values{};
    const auto result = normalize_and_unique(values);
    CHECK(result.empty());
}

TEST_CASE("pipeline preserves already-normalized unique input") {
    const std::vector<std::string> values{"algorithms", "cpp", "stl"};
    const auto result = normalize_and_unique(values);
    const std::vector<std::string> expected{"algorithms", "cpp", "stl"};
    CHECK(result == expected);
}

TEST_CASE("pipeline normalizes sorts and deduplicates words") {
    const std::vector<std::string> values{"Cpp", "algorithms", "cpp", "stl"};
    const auto result = normalize_and_unique(values);
    const std::vector<std::string> expected{"algorithms", "cpp", "stl"};
    CHECK(result == expected);
}

TEST_CASE("pipeline collapses duplicates after normalization") {
    const std::vector<std::string> values{"cpp", "Cpp", "CPP", "stl"};
    const auto result = normalize_and_unique(values);
    const std::vector<std::string> expected{"cpp", "stl"};
    CHECK(result == expected);
}

TEST_CASE("pipeline normalizes before deduplication in awkward order") {
    const std::vector<std::string> values{"STL", "Cpp", "algorithms", "cpp"};
    const auto result = normalize_and_unique(values);
    const std::vector<std::string> expected{"algorithms", "cpp", "stl"};
    CHECK(result == expected);
}
