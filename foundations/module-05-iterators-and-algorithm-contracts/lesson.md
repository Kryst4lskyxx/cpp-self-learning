# Lesson

This module is about the shape of iterator-based algorithms.

What to notice:

- a range is usually represented by two iterators, and the end iterator is one past the last element
- `std::distance(first, last)` measures the size of that half-open range
- algorithms such as `std::binary_search` assume their input is already sorted

The useful mental model is that algorithm contracts are part of the API, even when they are not written into the function signature.

For the assignment, that means a tiny helper can stay focused on one question:

```cpp
template <typename Range>
bool is_sorted_for_binary_search(const Range& values);
```

Keep it small. The goal is to recognize the contract, not to build a wrapper around every search algorithm.
