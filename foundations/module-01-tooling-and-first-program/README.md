# Module 01: Tooling and First Program

This module introduces the smallest complete C++ workflow in the repo:

## What You'll Build

You will build one tiny command-line program, compile it with CMake, and verify it with an automated test that runs the compiled executable.

## Before You Start

- Make sure `clang++`, CMake, and `ctest` are available on your machine.
- Start from the repository root and create the build tree with `cmake -S . -B build`.
- Read `lesson.md` first, then try the drill, then complete the assignment with a test-first loop.

The basic flow is:

1. Read the lesson to understand the source-to-binary path.
2. Build and run the drill to confirm the toolchain works.
3. Read `assignment/README.md`, make the smallest change in `assignment/main.cpp`, and rerun `ctest --test-dir build`.

## Wrap Up

When the test passes, reread the lesson and compare the assignment source with the test that launches it.
