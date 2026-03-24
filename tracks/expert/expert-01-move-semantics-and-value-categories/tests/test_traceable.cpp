#include "assertions.h"

#include "traceable.h"

#include <utility>

TEST_CASE("traceable records copy and move operations") {
    Traceable value{"cpp"};
    auto moved = std::move(value);
    CHECK(moved.move_count() == 1);
}
