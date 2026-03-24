#include "assertions.h"

#include "../assignment/text_stats.cpp"

TEST_CASE("text stats counts lines, words, and bytes") {
    const auto stats = analyze_text("hello cpp\nfrom stanford\n");
    CHECK(stats.lines == 2);
    CHECK(stats.words == 4);
    CHECK(stats.bytes == 24);
}
