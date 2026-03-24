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
    const auto document_index = documents_.size();
    documents_.push_back({std::move(document_id)});

    std::unordered_map<std::string, int> term_counts;
    for (const auto& term : tokenize(text)) {
        ++term_counts[term];
    }

    for (const auto& [term, frequency] : term_counts) {
        postings_[term].push_back({document_index, frequency});
    }
}

std::vector<SearchResult> SearchIndex::search(const std::string& query) const {
    const std::vector<std::string> query_terms = tokenize(query);
    std::unordered_set<std::string> unique_query_terms(query_terms.begin(), query_terms.end());

    std::vector<int> scores(documents_.size(), 0);

    for (const auto& term : unique_query_terms) {
        const auto postings = postings_.find(term);
        if (postings == postings_.end()) {
            continue;
        }

        for (const auto& posting : postings->second) {
            scores[posting.document_index] += posting.term_frequency;
        }
    }

    std::vector<SearchResult> results;
    results.reserve(documents_.size());

    for (std::size_t index = 0; index < documents_.size(); ++index) {
        if (scores[index] > 0) {
            results.push_back({documents_[index].id, scores[index]});
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
