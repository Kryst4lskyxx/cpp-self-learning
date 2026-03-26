# Assignment

Implement `filter_values` in `query_engine.h` so it returns the values from a range-like input that satisfy a predicate.

## Implementation Steps

1. Read `tests/test_query_engine.cpp` and identify the generic contract: the helper must work for a normal vector and for a custom range that only exposes `begin()` and `end()`.
2. Derive the output element type from the iterator expression, not from a nested alias that may not exist.
3. Use a standard algorithm to express "copy matching elements in original order" directly.
4. Keep the helper small and header-based. This module is teaching template mechanics and STL composition, not a custom query framework.

## Hands-On Checkpoints

- Make sure the implementation stays in `query_engine.h`, where callers can see the template definition.
- Check the custom `IntBag` test case before assuming the range has `value_type`, `size()`, or random-access iterators.
- Verify that accepted values preserve their original order in the returned vector.
- If you use `std::copy_if`, confirm that the destination grows through `std::back_inserter` rather than manual indexing.

## Final Verification

After editing the header, rebuild before running the test:

```bash
cmake --build build --target module_04_tests
ctest --test-dir build -R module_04_query_engine
```

Do not rely on `ctest` alone after a header-only change. The test binary has to be rebuilt so the new template definition is compiled into it.
