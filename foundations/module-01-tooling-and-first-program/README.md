# Module 01: Tooling and First Program

This module introduces the smallest complete C++ workflow in the repo:

## What You'll Build

You will learn how one tiny command-line program moves from source to a built executable and then through the module-specific test that runs it.

## Before You Start

- Make sure `clang++`, CMake, and `ctest` are available on your machine.
- Start from the repository root and create the build tree with `cmake -S . -B build`.
- Open `lesson.md`, `assignment/README.md`, and `tests/test_hello_cli.cpp` before you begin.
- Inspect `tests/test_hello_cli.cpp` first so you understand the Module 01 contract before changing anything.
- Use `cmake --build build --target module_01_assignment` and `ctest --test-dir build -R module_01_hello_cli` for the module-specific build/test loop.

The basic flow is:

1. Read the lesson to understand the source-to-binary path and the module-specific test target.
2. Build and run the drill to confirm the toolchain works.
3. Read `assignment/README.md`, then build `module_01_assignment` and run `ctest --test-dir build -R module_01_hello_cli` as the module-specific check.

## Wrap Up

When the module test passes, reread the lesson and compare the assignment source with the test that launches it.
