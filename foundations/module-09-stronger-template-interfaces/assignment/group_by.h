#ifndef FOUNDATIONS_MODULE_09_STRONGER_TEMPLATE_INTERFACES_ASSIGNMENT_GROUP_BY_H_
#define FOUNDATIONS_MODULE_09_STRONGER_TEMPLATE_INTERFACES_ASSIGNMENT_GROUP_BY_H_

#include <concepts>
#include <functional>
#include <map>
#include <ranges>
#include <type_traits>
#include <utility>
#include <vector>

namespace detail {

template <typename Range, typename KeySelector>
struct group_by_traits {
    using value_type = std::ranges::range_value_t<const Range>;
    using key_type = std::remove_cvref_t<
        std::invoke_result_t<KeySelector, std::ranges::range_reference_t<const Range>>>;
};

}  // namespace detail

template <typename Range, typename KeySelector>
requires std::ranges::input_range<const Range> &&
         std::copy_constructible<std::ranges::range_value_t<const Range>> &&
         std::invocable<KeySelector, std::ranges::range_reference_t<const Range>> &&
         std::totally_ordered<std::remove_cvref_t<
             std::invoke_result_t<KeySelector, std::ranges::range_reference_t<const Range>>>>
auto group_by(const Range& values, KeySelector key_selector)
    -> std::map<typename detail::group_by_traits<Range, KeySelector>::key_type,
                std::vector<typename detail::group_by_traits<Range, KeySelector>::value_type>> {
    using Traits = detail::group_by_traits<Range, KeySelector>;
    using key_type = typename Traits::key_type;
    using value_type = typename Traits::value_type;

    std::map<key_type, std::vector<value_type>> grouped;
    for (const auto& value : values) {
        grouped[std::invoke(key_selector, value)].push_back(value);
    }

    return grouped;
}

#endif  // FOUNDATIONS_MODULE_09_STRONGER_TEMPLATE_INTERFACES_ASSIGNMENT_GROUP_BY_H_
