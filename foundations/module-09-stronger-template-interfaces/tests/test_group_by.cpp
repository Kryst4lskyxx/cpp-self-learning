#include "assertions.h"

#include "group_by.h"

#include <map>
#include <string>
#include <type_traits>
#include <vector>

namespace {

struct move_only_string {
    move_only_string() = default;
    move_only_string(const move_only_string&) = delete;
    move_only_string& operator=(const move_only_string&) = delete;
    move_only_string(move_only_string&&) = default;
    move_only_string& operator=(move_only_string&&) = default;
};

template <typename Value>
concept can_group_by_values = requires(const std::vector<Value>& values) {
    group_by(values, [](const Value&) { return 0; });
};

static_assert(!can_group_by_values<move_only_string>);

}  // namespace

TEST_CASE("group_by returns an empty map for empty input") {
    const std::vector<int> values{};

    const auto grouped = group_by(values, [](int value) { return value; });

    CHECK(grouped.empty());
}

TEST_CASE("group_by groups values by a caller-provided key selector") {
    const std::vector<std::string> values{"cpp", "c", "stl"};
    const auto grouped = group_by(values, [](const std::string& value) { return value.size(); });
    using expected_grouped_type = std::map<decltype(values.size()), std::vector<std::string>>;
    static_assert(std::is_same_v<std::remove_cvref_t<decltype(grouped)>, expected_grouped_type>);

    CHECK(grouped.size() == 2);
    CHECK(grouped.contains(1));
    CHECK(grouped.contains(3));
    CHECK((grouped.at(1) == std::vector<std::string>{"c"}));
    CHECK((grouped.at(3) == std::vector<std::string>{"cpp", "stl"}));
}

TEST_CASE("group_by preserves the input order within each bucket") {
    const std::vector<std::string> values{"beta", "a", "gamma", "bb", "ccc"};

    const auto grouped = group_by(values, [](const std::string& value) { return value.size() % 2; });

    CHECK((grouped.at(0) == std::vector<std::string>{"beta", "bb"}));
    CHECK((grouped.at(1) == std::vector<std::string>{"a", "gamma", "ccc"}));
}

TEST_CASE("group_by calls the selector once per input value") {
    const std::vector<std::string> values{"aa", "b", "ccc", "dd"};
    int selector_calls = 0;

    const auto grouped = group_by(values, [&](const std::string& value) {
        ++selector_calls;
        return value.size() % 2;
    });

    CHECK(selector_calls == static_cast<int>(values.size()));
    CHECK(grouped.size() == 2);
    CHECK(grouped.contains(0));
    CHECK(grouped.contains(1));
}
