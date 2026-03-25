#ifndef FOUNDATIONS_MODULE_08_CALLABLE_OBJECTS_AND_CUSTOMIZATION_ASSIGNMENT_RANKER_H_
#define FOUNDATIONS_MODULE_08_CALLABLE_OBJECTS_AND_CUSTOMIZATION_ASSIGNMENT_RANKER_H_

#include <algorithm>
#include <functional>
#include <iterator>
#include <type_traits>
#include <utility>
#include <vector>

template <typename Value, typename Score>
struct RankedValue {
    Value value;
    Score score;
};

namespace detail {

template <typename Range, typename ScoringFunction>
struct ranker_traits {
    using value_type = std::remove_cvref_t<decltype(*std::begin(std::declval<const Range&>()))>;
    using score_type = std::remove_cvref_t<std::invoke_result_t<ScoringFunction, const value_type&>>;
    using ranked_type = RankedValue<value_type, score_type>;
};

}  // namespace detail

template <typename Range, typename ScoringFunction>
auto rank_values(const Range& values, ScoringFunction scoring_fn)
    -> std::vector<typename detail::ranker_traits<Range, ScoringFunction>::ranked_type> {
    using Traits = detail::ranker_traits<Range, ScoringFunction>;
    using Ranked = typename Traits::ranked_type;

    std::vector<Ranked> ranked;
    for (const auto& value : values) {
        ranked.push_back(Ranked{value, std::invoke(scoring_fn, value)});
    }

    std::stable_sort(ranked.begin(), ranked.end(), [](const Ranked& lhs, const Ranked& rhs) {
        return lhs.score > rhs.score;
    });

    return ranked;
}

#endif  // FOUNDATIONS_MODULE_08_CALLABLE_OBJECTS_AND_CUSTOMIZATION_ASSIGNMENT_RANKER_H_
