#ifndef FOUNDATIONS_MODULE_06_ALGORITHMIC_DATA_TRANSFORMATION_ASSIGNMENT_PIPELINE_H_
#define FOUNDATIONS_MODULE_06_ALGORITHMIC_DATA_TRANSFORMATION_ASSIGNMENT_PIPELINE_H_

#include <algorithm>
#include <cctype>
#include <iterator>

#include <string>
#include <vector>

inline std::vector<std::string> normalize_and_unique(const std::vector<std::string>& values) {
    std::vector<std::string> normalized;
    normalized.reserve(values.size());
    std::transform(values.begin(), values.end(), std::back_inserter(normalized), [](std::string word) {
        std::transform(word.begin(), word.end(), word.begin(), [](unsigned char ch) {
            return static_cast<char>(std::tolower(ch));
        });
        return word;
    });
    std::sort(normalized.begin(), normalized.end());
    normalized.erase(std::unique(normalized.begin(), normalized.end()), normalized.end());
    return normalized;
}

#endif  // FOUNDATIONS_MODULE_06_ALGORITHMIC_DATA_TRANSFORMATION_ASSIGNMENT_PIPELINE_H_
