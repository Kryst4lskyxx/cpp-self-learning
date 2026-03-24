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

TEST_CASE("search index returns no matches for missing tokens") {
    SearchIndex index;
    index.add_document("doc1", "modern cpp move semantics");

    CHECK(index.search("rust").empty());
}

TEST_CASE("search index uses deterministic ordering for tied scores") {
    SearchIndex index;
    index.add_document("docB", "alpha beta");
    index.add_document("docA", "alpha gamma");

    const auto results = index.search("alpha");

    CHECK(results.size() == 2);
    CHECK(results.front().document_id == "docA");
    CHECK(results.back().document_id == "docB");
}

TEST_CASE("search index normalizes query tokens the same way as documents") {
    SearchIndex index;
    index.add_document("doc1", "modern cpp move semantics");

    const auto results = index.search("CPP");

    CHECK(results.size() == 1);
    CHECK(results.front().document_id == "doc1");
    CHECK(results.front().score == 1);
}
