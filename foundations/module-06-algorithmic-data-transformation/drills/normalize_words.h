#ifndef FOUNDATIONS_MODULE_06_ALGORITHMIC_DATA_TRANSFORMATION_DRILLS_NORMALIZE_WORDS_H_
#define FOUNDATIONS_MODULE_06_ALGORITHMIC_DATA_TRANSFORMATION_DRILLS_NORMALIZE_WORDS_H_

#include <algorithm>
#include <cctype>
#include <iterator>
#include <string>
#include <vector>

inline std::string normalize_word(std::string word) {
    std::transform(word.begin(), word.end(), word.begin(), [](unsigned char ch) {
        return static_cast<char>(std::tolower(ch));
    });
    return word;
}

inline std::vector<std::string> normalize_words(const std::vector<std::string>& values) {
    std::vector<std::string> normalized;
    normalized.reserve(values.size());
    std::transform(values.begin(), values.end(), std::back_inserter(normalized), normalize_word);
    return normalized;
}

#endif  // FOUNDATIONS_MODULE_06_ALGORITHMIC_DATA_TRANSFORMATION_DRILLS_NORMALIZE_WORDS_H_
