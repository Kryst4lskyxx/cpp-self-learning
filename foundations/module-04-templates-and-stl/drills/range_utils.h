#ifndef FOUNDATIONS_MODULE_04_TEMPLATES_AND_STL_DRILLS_RANGE_UTILS_H_
#define FOUNDATIONS_MODULE_04_TEMPLATES_AND_STL_DRILLS_RANGE_UTILS_H_

#include <algorithm>
#include <iterator>
#include <vector>

template <typename InputIt, typename Predicate>
auto collect_if(InputIt first, InputIt last, Predicate predicate)
    -> std::vector<typename std::iterator_traits<InputIt>::value_type> {
    using Value = typename std::iterator_traits<InputIt>::value_type;

    std::vector<Value> collected;
    std::copy_if(first, last, std::back_inserter(collected), predicate);
    return collected;
}

#endif  // FOUNDATIONS_MODULE_04_TEMPLATES_AND_STL_DRILLS_RANGE_UTILS_H_
