# Module 07: Associative Containers and Lookup Patterns

## What You'll Build

You will build a tag index that keeps lookup fast internally while returning stable, sorted document ids to the caller.

## Before You Start

- Make sure `clang++`, CMake, and `ctest` are available on your machine.
- If this is a fresh checkout, run `cmake -S . -B build` once from the repository root before using the module loop below.
- Open `foundations/module-07-associative-containers-and-lookup-patterns/lesson.md`, `foundations/module-07-associative-containers-and-lookup-patterns/assignment/README.md`, and `foundations/module-07-associative-containers-and-lookup-patterns/tests/test_tag_index.cpp` before you begin.
- Inspect `foundations/module-07-associative-containers-and-lookup-patterns/tests/test_tag_index.cpp` first so you can see the lookup contract the tests encode.
- Use `cmake --build build --target module_07_tests` and `ctest --test-dir build -R module_07_tag_index` for the module-specific build/test loop.
- If associative lookup feels rusty, try the drill first and then come back here.

If you want a quick recap after the assignment, reread the lesson and compare it with the lookup behavior in the tests. The important part is the contract, not the container name.
