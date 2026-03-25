#include "assertions.h"

#include "tag_index.h"

#include <vector>

TEST_CASE("tag index returns stable sorted ids for a tag lookup") {
    TagIndex index;
    index.add("doc2", {"cpp", "stl"});
    index.add("doc1", {"cpp"});
    const std::vector<std::string> expected{"doc1", "doc2"};
    CHECK(index.lookup("cpp") == expected);
}

TEST_CASE("tag index returns an empty result for a missing tag") {
    TagIndex index;
    index.add("doc1", {"cpp"});

    CHECK(index.lookup("stl").empty());
}

TEST_CASE("tag index does not duplicate ids when the same document is added twice") {
    TagIndex index;
    index.add("doc1", {"cpp"});
    index.add("doc1", {"cpp", "stl"});

    const std::vector<std::string> expected{"doc1"};
    CHECK(index.lookup("cpp") == expected);
    CHECK(index.lookup("stl") == expected);
}

TEST_CASE("tag index sorts lookup output independently of insertion order") {
    TagIndex index;
    index.add("doc3", {"cpp"});
    index.add("doc1", {"cpp"});
    index.add("doc2", {"cpp"});

    const std::vector<std::string> expected{"doc1", "doc2", "doc3"};
    CHECK(index.lookup("cpp") == expected);
}
