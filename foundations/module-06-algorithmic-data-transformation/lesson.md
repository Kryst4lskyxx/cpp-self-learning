# Lesson

This module is about reading a transformation pipeline as a sequence of small, explicit steps:

- normalize the input into a consistent form
- order the data so equal items become adjacent
- remove adjacent duplicates after sorting

The key C++ idea is that the algorithm names communicate intent better than a custom loop when the work is a standard sequence of transformations.

For the assignment, the helper should accept a list of words and return a normalized, sorted, deduplicated list:

```cpp
std::vector<std::string> normalize_and_unique(const std::vector<std::string>& values);
```

Keep the pipeline narrow. This is a practice module for algorithm composition, not a general-purpose text-processing library.
