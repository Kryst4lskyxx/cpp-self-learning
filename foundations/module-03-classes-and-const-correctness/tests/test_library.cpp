#include "assertions.h"

#include "library.h"

namespace {

Library make_sample_library() {
    Library library;
    library.add_book({"Effective Modern C++", "Scott Meyers", 2014});
    library.add_book({"C++ Primer", "Stanley B. Lippman", 2012});
    library.add_book({"A Tour of C++", "Bjarne Stroustrup", 2018});
    return library;
}

}  // namespace

TEST_CASE("library search is const and does not mutate catalog") {
    const Library library = make_sample_library();
    const auto result = library.find_by_title("Effective Modern C++");
    CHECK(result.has_value());
    CHECK(library.size() == 3);
}
