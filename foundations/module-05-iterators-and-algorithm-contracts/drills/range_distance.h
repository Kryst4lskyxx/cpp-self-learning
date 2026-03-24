#ifndef FOUNDATIONS_MODULE_05_ITERATORS_AND_ALGORITHM_CONTRACTS_DRILLS_RANGE_DISTANCE_H_
#define FOUNDATIONS_MODULE_05_ITERATORS_AND_ALGORITHM_CONTRACTS_DRILLS_RANGE_DISTANCE_H_

#include <iterator>

template <typename InputIt>
auto range_distance(InputIt first, InputIt last)
    -> typename std::iterator_traits<InputIt>::difference_type {
    return std::distance(first, last);
}

template <typename Range>
auto range_distance(const Range& values)
    -> typename std::iterator_traits<decltype(std::begin(values))>::difference_type {
    return range_distance(std::begin(values), std::end(values));
}

#endif  // FOUNDATIONS_MODULE_05_ITERATORS_AND_ALGORITHM_CONTRACTS_DRILLS_RANGE_DISTANCE_H_
