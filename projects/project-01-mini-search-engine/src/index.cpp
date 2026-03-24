#include "index.h"

#include <algorithm>
#include <cctype>
#include <unordered_map>
#include <unordered_set>

namespace {

std::string normalize_token(const std::string& token) {
    std::string normalized;
    normalized.reserve(token.size());

    for (unsigned char ch : token) {
        normalized.push_back(static_cast<char>(std::tolower(ch)));
    }

    return normalized;
}

} // namespace

void SearchIndex::add_document(std::string document_id, std::string text) {
    documents_.push_back({std::move(document_id), tokenize(text)});
}

std::vector<SearchResult> SearchIndex::search(const std::string& query) const {
    const std::vector<std::string> query_terms = tokenize(query);
    std::unordered_set<std::string> unique_query_terms(query_terms.begin(), query_terms.end());

    std::vector<SearchResult> results;
    results.reserve(documents_.size());

    for (const auto& document : documents_) {
        std::unordered_map<std::string, int> term_counts;
        for (const auto& term : document.terms) {
            ++term_counts[term];
        }

        int score = 0;
        for (const auto& term : unique_query_terms) {
            const auto term_count = term_counts.find(term);
            if (term_count != term_counts.end()) {
                score += term_count->second;
            }
        }

        if (score > 0) {
            results.push_back({document.id, score});
        }
    }

    std::sort(results.begin(), results.end(), [](const SearchResult& left, const SearchResult& right) {
        if (left.score != right.score) {
            return left.score > right.score;
        }

        return left.document_id < right.document_id;
    });

    return results;
}

std::vector<std::string> SearchIndex::tokenize(const std::string& text) {
    std::vector<std::string> tokens;
    std::string current;

    for (unsigned char ch : text) {
        if (std::isalnum(ch)) {
            current.push_back(static_cast<char>(ch));
            continue;
        }

        if (!current.empty()) {
            tokens.push_back(normalize_token(current));
            current.clear();
        }
    }

    if (!current.empty()) {
        tokens.push_back(normalize_token(current));
    }

    return tokens;
}
