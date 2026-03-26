# Lesson

This module is about writing one algorithm that works for more than one concrete container shape.

Templates are compile-time recipes. `filter_values` is not "a function for every type at runtime." It becomes a concrete function only for the range and predicate types the caller actually uses.

The STL part of the story is iterator-based algorithms. `std::copy_if` does not care whether the source is a `std::vector<int>` or a custom type with `begin()` and `end()`. It only cares that it can iterate the range and test each value with the predicate.

Because template instantiation happens where the function is used, the definition has to be visible in the header. That is why the real implementation lives in `query_engine.h`.

`std::back_inserter` turns a container into an output iterator that appends with `push_back`. That lets the algorithm write results into the destination vector without manual index management.

## Code Examples

```cpp
std::vector<int> values{1, 2, 3, 4};
const auto evens = filter_values(values, [](int value) {
    return value % 2 == 0;
});
```

The same template can work for this standard container because `std::begin(values)` and `std::end(values)` are valid, and dereferencing the iterator gives the element type.

```cpp
template <typename Range, typename Predicate>
auto filter_values(const Range& values, Predicate predicate)
    -> std::vector<std::remove_cvref_t<decltype(*std::begin(values))>>;
```

That return type is derived from the range itself instead of assuming the range has a nested `value_type`.

```cpp
struct IntBag {
    int values[3]{1, 2, 3};

    const int* begin() const;
    const int* end() const;
};
```

This kind of custom range is why the test does not want a solution that depends on `Range::value_type`.

## Common Mistakes

- Putting the template implementation only in `.cpp`. If you get linker or "undefined reference" issues around `filter_values`, move back to the header and rebuild.
- Assuming every range has a `value_type` alias. The custom range test exists specifically to catch that assumption.
- Writing a manual loop when `std::copy_if` already expresses the contract directly. If your code is growing, compare it to the algorithm you actually need.
- Forgetting to rebuild after changing the header. Even though the implementation is header-based, the test binary still has to be recompiled before `ctest` reflects the change.
