#include "assertions.h"

#include <cstddef>
#include <string>

struct TextStats {
    std::size_t lines{};
    std::size_t words{};
    std::size_t bytes{};
};

TextStats analyze_text(const std::string& text);

TEST_CASE("text stats counts lines, words, and bytes") {
    const auto stats = analyze_text("hello cpp\nfrom stanford\n");
    CHECK(stats.lines == 2);
    CHECK(stats.words == 4);
    CHECK(stats.bytes == 24);
}
