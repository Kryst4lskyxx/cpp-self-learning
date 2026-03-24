#pragma once

#include <cstddef>
#include <unordered_map>
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
    };

    struct Posting {
        std::size_t document_index = 0;
        int term_frequency = 0;
    };

    std::vector<Document> documents_;
    std::unordered_map<std::string, std::vector<Posting>> postings_;
};
