#ifndef FOUNDATIONS_MODULE_05_ITERATORS_AND_ALGORITHM_CONTRACTS_ASSIGNMENT_CONTRACT_CHECKS_H_
#define FOUNDATIONS_MODULE_05_ITERATORS_AND_ALGORITHM_CONTRACTS_ASSIGNMENT_CONTRACT_CHECKS_H_

#include <algorithm>
#include <iterator>

template <typename Range>
bool is_sorted_for_binary_search(const Range& values) {
    return std::is_sorted(std::begin(values), std::end(values));
}

#endif  // FOUNDATIONS_MODULE_05_ITERATORS_AND_ALGORITHM_CONTRACTS_ASSIGNMENT_CONTRACT_CHECKS_H_
