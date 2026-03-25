#ifndef FOUNDATIONS_MODULE_09_STRONGER_TEMPLATE_INTERFACES_DRILLS_VALUE_SELECTOR_H_
#define FOUNDATIONS_MODULE_09_STRONGER_TEMPLATE_INTERFACES_DRILLS_VALUE_SELECTOR_H_

#include <functional>
#include <iterator>
#include <type_traits>
#include <utility>
#include <vector>

namespace detail {

template <typename Range, typename Selector>
struct value_selector_traits {
    using value_type = std::remove_cvref_t<decltype(*std::begin(std::declval<const Range&>()))>;
    using selected_type = std::remove_cvref_t<std::invoke_result_t<Selector, const value_type&>>;
};

}  // namespace detail

template <typename Range, typename Selector>
auto select_values(const Range& values, Selector selector)
    -> std::vector<typename detail::value_selector_traits<Range, Selector>::selected_type> {
    using selected_type = typename detail::value_selector_traits<Range, Selector>::selected_type;

    std::vector<selected_type> selected;
    for (const auto& value : values) {
        selected.push_back(std::invoke(selector, value));
    }

    return selected;
}

#endif  // FOUNDATIONS_MODULE_09_STRONGER_TEMPLATE_INTERFACES_DRILLS_VALUE_SELECTOR_H_
