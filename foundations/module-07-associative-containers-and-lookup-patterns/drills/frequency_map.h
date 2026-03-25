#ifndef FOUNDATIONS_MODULE_07_ASSOCIATIVE_CONTAINERS_AND_LOOKUP_PATTERNS_DRILLS_FREQUENCY_MAP_H_
#define FOUNDATIONS_MODULE_07_ASSOCIATIVE_CONTAINERS_AND_LOOKUP_PATTERNS_DRILLS_FREQUENCY_MAP_H_

#include <cstddef>
#include <string>
#include <string_view>
#include <unordered_map>

class FrequencyMap {
public:
    void add(std::string_view word) {
        ++counts_[std::string(word)];
    }

    std::size_t count(std::string_view word) const {
        const auto it = counts_.find(std::string(word));
        return it == counts_.end() ? 0U : it->second;
    }

private:
    std::unordered_map<std::string, std::size_t> counts_;
};

#endif  // FOUNDATIONS_MODULE_07_ASSOCIATIVE_CONTAINERS_AND_LOOKUP_PATTERNS_DRILLS_FREQUENCY_MAP_H_
