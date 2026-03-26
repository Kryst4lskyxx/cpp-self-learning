# Module 02: Strings, Streams, and Collections

## What You'll Build

You will write `analyze_text`, a small helper that measures a string of text by counting lines, words, and bytes.

## Before You Start

- Make sure `clang++`, CMake, and `ctest` are available.
- Open `foundations/module-02-strings-streams-and-collections/lesson.md`, `foundations/module-02-strings-streams-and-collections/assignment/README.md`, `foundations/module-02-strings-streams-and-collections/assignment/text_stats.cpp`, and `foundations/module-02-strings-streams-and-collections/tests/test_text_stats.cpp`.
- Inspect `foundations/module-02-strings-streams-and-collections/tests/test_text_stats.cpp` first so you know the exact contract before editing the implementation.
- Use `cmake --build build --target module_02_tests` and `ctest --test-dir build -R module_02_text_stats` for the module-specific loop.
- Read the lesson with one question in mind: when should you use `std::getline`, and when should you use stream extraction with `>>`?

This module is the first text-processing exercise in the foundations track. Keep the implementation direct: read the input as text, parse it with standard library tools, and let the test drive the exact counting rules.
