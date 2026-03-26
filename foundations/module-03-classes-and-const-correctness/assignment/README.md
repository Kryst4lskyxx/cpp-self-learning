# Assignment

Implement a small `Library` type with private book storage and a const-correct search API.

## Implementation Steps

1. Read `tests/test_library.cpp` and identify the public contract before writing code: `Library` owns books, exposes `add_book`, reports `size`, and supports title lookup on a `const Library`.
2. Define the smallest `Book` value type that satisfies the test data.
3. Keep the catalog private and choose one container that fits the tests. A `std::vector<Book>` is enough.
4. Implement `find_by_title` so it reads from the catalog without mutating it and reports absence explicitly.

## Hands-On Checkpoints

- Verify that `find_by_title` is declared `const` in the class interface, not only treated as read-only in the implementation.
- Check the inferred return type from the test. If the static assertion fails, compare your declaration with the exact type the test expects.
- After a successful search and a failed search, `size()` should still report the original catalog size.
- Keep the first implementation small. You only need title matching and read-only access to the found book.

## Final Verification

Run:

```bash
cmake --build build --target module_03_tests
ctest --test-dir build -R module_03_library
```

Remember that any change to `library.h` or `library.cpp` requires rebuilding the test target before running `ctest`.
