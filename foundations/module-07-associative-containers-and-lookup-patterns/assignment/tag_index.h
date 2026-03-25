#ifndef FOUNDATIONS_MODULE_07_ASSOCIATIVE_CONTAINERS_AND_LOOKUP_PATTERNS_ASSIGNMENT_TAG_INDEX_H_
#define FOUNDATIONS_MODULE_07_ASSOCIATIVE_CONTAINERS_AND_LOOKUP_PATTERNS_ASSIGNMENT_TAG_INDEX_H_

#include <initializer_list>
#include <set>
#include <string>
#include <string_view>
#include <unordered_map>
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

        return {it->second.begin(), it->second.end()};
    }

private:
    std::unordered_map<std::string, std::set<std::string>> index_;
};

#endif  // FOUNDATIONS_MODULE_07_ASSOCIATIVE_CONTAINERS_AND_LOOKUP_PATTERNS_ASSIGNMENT_TAG_INDEX_H_
