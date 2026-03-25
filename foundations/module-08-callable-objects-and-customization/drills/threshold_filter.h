#ifndef FOUNDATIONS_MODULE_08_CALLABLE_OBJECTS_AND_CUSTOMIZATION_DRILLS_THRESHOLD_FILTER_H_
#define FOUNDATIONS_MODULE_08_CALLABLE_OBJECTS_AND_CUSTOMIZATION_DRILLS_THRESHOLD_FILTER_H_

#include <algorithm>
#include <functional>
#include <iterator>
#include <type_traits>
#include <utility>
#include <vector>

template <typename Range, typename Threshold, typename Compare = std::greater<>>
auto threshold_filter(const Range& values, const Threshold& threshold, Compare compare = Compare{})
    -> std::vector<std::remove_cvref_t<decltype(*std::begin(values))>> {
    using Value = std::remove_cvref_t<decltype(*std::begin(values))>;

    std::vector<Value> filtered;
    std::copy_if(std::begin(values), std::end(values), std::back_inserter(filtered),
                 [&](const Value& value) { return std::invoke(compare, value, threshold); });
    return filtered;
}

#endif  // FOUNDATIONS_MODULE_08_CALLABLE_OBJECTS_AND_CUSTOMIZATION_DRILLS_THRESHOLD_FILTER_H_
