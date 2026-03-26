# Module 04: Templates and STL

## What You'll Build

You will implement `filter_values`, a small template that filters a range-like input into a `std::vector` using a caller-provided predicate.

## Before You Start

- Make sure `clang++`, CMake, and `ctest` are available.
- If this is a fresh checkout, run `cmake -S . -B build` once from the repository root before using the module loop below.
- Open `foundations/module-04-templates-and-stl/lesson.md`, `foundations/module-04-templates-and-stl/assignment/README.md`, `foundations/module-04-templates-and-stl/assignment/query_engine.h`, and `foundations/module-04-templates-and-stl/tests/test_query_engine.cpp`.
- Inspect `foundations/module-04-templates-and-stl/tests/test_query_engine.cpp` first so you can see both the normal container case and the custom range case.
- Use `cmake --build build --target module_04_tests` and `ctest --test-dir build -R module_04_query_engine` for the module-specific loop.
- Read the lesson with two questions in mind: why must template definitions live in headers, and how do `std::copy_if` plus `std::back_inserter` remove the need for a manual loop?

This module is the first generic-programming step in the track. The goal is not a full query system; it is one compact example of how templates, iterators, and algorithms fit together.
