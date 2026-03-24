#pragma once

#include <string>
#include <vector>

struct SearchResult {
    std::string document_id;
    int score = 0;
};

class SearchIndex {
public:
    void add_document(std::string document_id, std::string text);
    [[nodiscard]] std::vector<SearchResult> search(const std::string& query) const;

private:
    static std::vector<std::string> tokenize(const std::string& text);

    struct Document {
        std::string id;
        std::vector<std::string> terms;
    };

    std::vector<Document> documents_;
};
