# Module 05: Iterators and Algorithm Contracts

## What You'll Build

You will write a tiny helper that checks whether a range is ready for binary search by inspecting the range contract instead of performing a search.

## Before You Start

- Make sure `clang++`, CMake, and `ctest` are available on your machine.
- Open `foundations/module-05-iterators-and-algorithm-contracts/lesson.md`, `foundations/module-05-iterators-and-algorithm-contracts/assignment/README.md`, and `foundations/module-05-iterators-and-algorithm-contracts/tests/test_contract_checks.cpp` before you begin.
- Inspect `foundations/module-05-iterators-and-algorithm-contracts/tests/test_contract_checks.cpp` first so you can see the contract the tests encode.
- Use `cmake --build build --target module_05_tests` and `ctest --test-dir build -R module_05_contract_checks` for the module-specific build/test loop.
- Read the lesson to refresh the `[first, last)` range shape.
- Review the assignment tests to see the binary-search precondition they enforce.
- If the range boundary model feels rusty, try the drill first and then come back here.

If you want a quick recap after the assignment, return to the lesson and the drill together: they cover the same iterator-range idea from two angles.
