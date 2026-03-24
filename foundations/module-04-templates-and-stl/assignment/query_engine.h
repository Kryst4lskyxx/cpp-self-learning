#ifndef FOUNDATIONS_MODULE_04_TEMPLATES_AND_STL_ASSIGNMENT_QUERY_ENGINE_H_
#define FOUNDATIONS_MODULE_04_TEMPLATES_AND_STL_ASSIGNMENT_QUERY_ENGINE_H_

#include <algorithm>
#include <iterator>
#include <type_traits>
#include <vector>

template <typename Range, typename Predicate>
auto filter_values(const Range& values, Predicate predicate)
    -> std::vector<std::remove_cvref_t<decltype(*std::begin(values))>> {
    using Value = std::remove_cvref_t<decltype(*std::begin(values))>;

    std::vector<Value> filtered;
    std::copy_if(std::begin(values), std::end(values), std::back_inserter(filtered), predicate);
    return filtered;
}

#endif  // FOUNDATIONS_MODULE_04_TEMPLATES_AND_STL_ASSIGNMENT_QUERY_ENGINE_H_
