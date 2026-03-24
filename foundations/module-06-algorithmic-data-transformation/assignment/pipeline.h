#ifndef FOUNDATIONS_MODULE_06_ALGORITHMIC_DATA_TRANSFORMATION_ASSIGNMENT_PIPELINE_H_
#define FOUNDATIONS_MODULE_06_ALGORITHMIC_DATA_TRANSFORMATION_ASSIGNMENT_PIPELINE_H_

#include <algorithm>
#include "normalize_words.h"

#include <string>
#include <vector>

inline std::vector<std::string> normalize_and_unique(const std::vector<std::string>& values) {
    auto normalized = normalize_words(values);
    std::sort(normalized.begin(), normalized.end());
    normalized.erase(std::unique(normalized.begin(), normalized.end()), normalized.end());
    return normalized;
}

#endif  // FOUNDATIONS_MODULE_06_ALGORITHMIC_DATA_TRANSFORMATION_ASSIGNMENT_PIPELINE_H_
