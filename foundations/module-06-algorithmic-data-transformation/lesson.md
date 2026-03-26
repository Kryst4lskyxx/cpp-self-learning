# Lesson

This module is about reading a transformation pipeline as a sequence of small, explicit steps:

- normalize the input into a consistent form
- order the data so equal items become adjacent
- remove adjacent duplicates after sorting

The important C++ idea is the order of the steps. `std::transform` changes the representation, `std::sort` groups equal values together, and `std::unique` only removes neighbors. If you change the order, the result changes.

A small pipeline often looks like this:

```cpp
auto values = normalize_and_unique(words);
```

Under the hood, that usually means:

```cpp
// normalize first, then sort, then remove adjacent duplicates
```

That sequence is easier to reason about than a hand-written loop when the work is standard and the contract is simple.

For the assignment, the helper should accept a list of words and return a normalized, sorted, deduplicated list:

```cpp
std::vector<std::string> normalize_and_unique(const std::vector<std::string>& values);
```

Keep the pipeline narrow. This is a practice module for algorithm composition, not a general-purpose text-processing library.

## Code Examples

```cpp
std::vector<std::string> words{"Cpp", "cpp", "STL"};
```

The same word can appear in multiple forms before normalization.

```cpp
std::ranges::transform(values, values.begin(), to_lowercase);
std::ranges::sort(values);
values.erase(std::ranges::unique(values).begin(), values.end());
```

That is the contract the assignment is asking you to express.

## Common Mistakes

- Sorting before normalization and then wondering why mixed-case duplicates remain separate.
- Calling `std::unique` without sorting first and expecting all duplicates to disappear.
- Forgetting that `std::unique` only groups adjacent equal values and still needs an erase step.
- Debugging only the final output and skipping the step where the order actually goes wrong.
