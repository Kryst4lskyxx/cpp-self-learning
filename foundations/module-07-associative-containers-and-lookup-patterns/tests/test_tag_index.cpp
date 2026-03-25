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
