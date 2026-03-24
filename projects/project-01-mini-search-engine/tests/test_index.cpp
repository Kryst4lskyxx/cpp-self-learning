#include "assertions.h"

#include "index.h"

TEST_CASE("search index returns ranked matches for query tokens") {
    SearchIndex index;
    index.add_document("doc1", "modern cpp move semantics");
    index.add_document("doc2", "cpp streams and strings");

    const auto results = index.search("cpp move");

    CHECK(!results.empty());
    CHECK(results.front().document_id == "doc1");
    CHECK(results.front().score == 2);
    CHECK(results.size() == 2);
}
