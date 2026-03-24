#include "assertions.h"

#include "pipeline.h"

#include <vector>

TEST_CASE("pipeline normalizes sorts and deduplicates words") {
    const std::vector<std::string> values{"Cpp", "algorithms", "cpp", "stl"};
    const auto result = normalize_and_unique(values);
    const std::vector<std::string> expected{"algorithms", "cpp", "stl"};
    CHECK(result == expected);
}
