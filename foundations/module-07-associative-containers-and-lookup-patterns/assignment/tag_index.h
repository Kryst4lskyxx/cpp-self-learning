#ifndef FOUNDATIONS_MODULE_07_ASSOCIATIVE_CONTAINERS_AND_LOOKUP_PATTERNS_ASSIGNMENT_TAG_INDEX_H_
#define FOUNDATIONS_MODULE_07_ASSOCIATIVE_CONTAINERS_AND_LOOKUP_PATTERNS_ASSIGNMENT_TAG_INDEX_H_

#include <algorithm>
#include <initializer_list>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class TagIndex {
public:
    void add(std::string id, std::initializer_list<std::string> tags) {
        for (const auto& tag : tags) {
            index_[tag].insert(id);
        }
    }

    std::vector<std::string> lookup(std::string_view tag) const {
        const auto it = index_.find(std::string(tag));
        if (it == index_.end()) {
            return {};
        }

        std::vector<std::string> ids{it->second.begin(), it->second.end()};
        std::sort(ids.begin(), ids.end());
        return ids;
    }

private:
    std::unordered_map<std::string, std::unordered_set<std::string>> index_;
};

#endif  // FOUNDATIONS_MODULE_07_ASSOCIATIVE_CONTAINERS_AND_LOOKUP_PATTERNS_ASSIGNMENT_TAG_INDEX_H_
