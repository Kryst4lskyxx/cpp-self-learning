# Module 08: Callable Objects and Customization

## What You'll Build

You will build a small ranking helper that accepts a caller-provided callable, scores each value, and returns the results in descending score order.

## Before You Start

- Make sure `clang++`, CMake, and `ctest` are available on your machine.
- If this is a fresh checkout, run `cmake -S . -B build` once from the repository root before using the module loop below.
- Open `foundations/module-08-callable-objects-and-customization/lesson.md`, `foundations/module-08-callable-objects-and-customization/assignment/README.md`, and `foundations/module-08-callable-objects-and-customization/tests/test_ranker.cpp` before you begin.
- Inspect `foundations/module-08-callable-objects-and-customization/tests/test_ranker.cpp` first so you can see the scoring and ordering contract the tests encode.
- Use `cmake --build build --target module_08_tests` and `ctest --test-dir build -R module_08_ranker` for the module-specific build/test loop.
- If callable customization feels rusty, try the drill first and then come back here.

If you want a quick recap after the assignment, reread the lesson and compare it with the test cases. The callable is the customization point; the contract is still the guide.
