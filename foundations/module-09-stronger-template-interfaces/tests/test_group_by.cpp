#include "assertions.h"

#include "group_by.h"

#include <string>
#include <vector>

TEST_CASE("group_by returns an empty map for empty input") {
    const std::vector<int> values{};

    const auto grouped = group_by(values, [](int value) { return value; });

    CHECK(grouped.empty());
}

TEST_CASE("group_by groups values by a caller-provided key selector") {
    const std::vector<std::string> values{"cpp", "c", "stl"};
    const auto grouped = group_by(values, [](const std::string& value) { return value.size(); });
    CHECK((grouped.at(3) == std::vector<std::string>{"cpp", "stl"}));
}

TEST_CASE("group_by preserves the input order within each bucket") {
    const std::vector<std::string> values{"beta", "a", "gamma", "bb", "ccc"};

    const auto grouped = group_by(values, [](const std::string& value) { return value.size() % 2; });

    CHECK((grouped.at(0) == std::vector<std::string>{"beta", "bb"}));
    CHECK((grouped.at(1) == std::vector<std::string>{"a", "gamma", "ccc"}));
}
