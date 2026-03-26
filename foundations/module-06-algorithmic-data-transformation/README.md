# Module 06: Algorithmic Data Transformation

## What You'll Build

You will build a small word-normalization pipeline that turns mixed input into lowercase, sorted, deduplicated output with standard algorithms.

## Before You Start

- Make sure `clang++`, CMake, and `ctest` are available on your machine.
- If this is a fresh checkout, run `cmake -S . -B build` once from the repository root before using the module loop below.
- Open `foundations/module-06-algorithmic-data-transformation/lesson.md`, `foundations/module-06-algorithmic-data-transformation/assignment/README.md`, and `foundations/module-06-algorithmic-data-transformation/tests/test_pipeline.cpp` before you begin.
- Inspect `foundations/module-06-algorithmic-data-transformation/tests/test_pipeline.cpp` first so you can see the pipeline contract the tests encode.
- Use `cmake --build build --target module_06_tests` and `ctest --test-dir build -R module_06_pipeline` for the module-specific build/test loop.
- If algorithm order feels rusty, try the drill first and then come back here.

If you want a quick recap after the assignment, return to the lesson and compare the pipeline with the tests. The contract is the same; only the input examples change.
