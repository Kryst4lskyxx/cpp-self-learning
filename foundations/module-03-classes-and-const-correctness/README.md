# Module 03: Classes and Const Correctness

## What You'll Build

You will build a small `Library` class that stores books, reports its size, and supports const-correct title lookup.

## Before You Start

- Make sure `clang++`, CMake, and `ctest` are available.
- If this is a fresh checkout, run `cmake -S . -B build` once from the repository root before using the module loop below.
- Open `foundations/module-03-classes-and-const-correctness/lesson.md`, `foundations/module-03-classes-and-const-correctness/assignment/README.md`, `foundations/module-03-classes-and-const-correctness/assignment/library.h`, `foundations/module-03-classes-and-const-correctness/assignment/library.cpp`, and `foundations/module-03-classes-and-const-correctness/tests/test_library.cpp`.
- Inspect `foundations/module-03-classes-and-const-correctness/tests/test_library.cpp` first so you can see the required API shape and return type.
- Use `cmake --build build --target module_03_tests` and `ctest --test-dir build -R module_03_library` for the module-specific loop.
- Read the lesson with special attention to what `const` changes for member functions and returned references.

This module introduces the first real object boundary in the curriculum. The main job is not storing data; it is expressing a small API that makes mutation and read-only access obvious.
