#include "assertions.h"

#include "library.h"

#include <type_traits>

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

    static_assert(std::is_same_v<decltype(result), const std::optional<std::reference_wrapper<const Book>>>);

    CHECK(result.has_value());
    CHECK(library.size() == 3);
    CHECK(result->get().title == "Effective Modern C++");
    CHECK(result->get().author == "Scott Meyers");
    CHECK(result->get().year == 2014);
}

TEST_CASE("library search returns empty when a title is missing") {
    const Library library = make_sample_library();
    const auto result = library.find_by_title("The C++ Programming Language");

    CHECK(!result.has_value());
    CHECK(library.size() == 3);
}
