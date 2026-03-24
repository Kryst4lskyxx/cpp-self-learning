# Assignment

Implement `is_sorted_for_binary_search` in `contract_checks.h`.

The tests expect the helper to return `true` for a sorted `std::vector<int>` and `false`
for an unsorted one.

This assignment narrows the binary-search precondition to the default ordering used by
`std::is_sorted` on the range. Keep the helper small and direct, and use the standard
library to express that contract instead of reimplementing a search algorithm.
