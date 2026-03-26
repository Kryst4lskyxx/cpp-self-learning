# Lesson

This module is about two habits that keep iterator-based code correct:

- treat iterator pairs as half-open ranges, `[first, last)`
- check an algorithm's contract before you rely on it

The half-open shape is the reason `last` is not part of the range. If a vector has three elements, the valid pair is the iterator to the first element and the iterator one past the third element. That lets algorithms stop cleanly without special cases for the final element.

`std::distance(first, last)` measures that span. `std::is_sorted(first, last)` checks the ordering contract directly.

For binary search, the contract is simple: the input must already be sorted in ascending order. In this module, "sorted" means the default ordering that `std::is_sorted` checks.

## Code Examples

```cpp
std::vector<int> values{10, 20, 30};
auto n = std::distance(values.begin(), values.end());  // 3
```

The end iterator is one past `30`, so the range has three elements and not four.

```cpp
std::vector<int> ok{1, 2, 2, 4};
std::vector<int> bad{2, 1, 3};

std::is_sorted(ok.begin(), ok.end());   // true
std::is_sorted(bad.begin(), bad.end()); // false
```

## Common Mistakes

- Treating `last` as if it points at the final element instead of one past it.
- Checking sortedness by running a search algorithm and hoping the result proves the precondition.
- Mixing up "sorted" with "contains no duplicates." Duplicates are fine as long as the range stays in ascending order.
- Forgetting that the contract is about the whole iterator range, not just a few sampled elements.
