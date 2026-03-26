# Module 09: Stronger Template Interfaces

This module is about making a generic interface say exactly what it needs and exactly what it returns.

## What You'll Build

You will implement a small `group_by` helper that:

- reads a range through a `const` interface
- accepts a caller-provided key selector
- returns a `std::map` keyed by the selector result
- keeps each bucket in input order

The code is small on purpose. The real exercise is learning how to express template requirements clearly enough that the contract is visible before you read the function body.

## Before You Start

Prerequisites:

- you are comfortable reading function templates and lambdas
- you can read basic C++20 constraints such as `requires`, `std::invocable`, and range concepts
- you have a working C++20 toolchain
- you have CMake available
- the repository has been configured once with `cmake -S . -B build`

Module-specific build/test commands:

```bash
cmake --build build --target module_09_tests
ctest --test-dir build --output-on-failure -R module_09_group_by
```

Open these files:

- `foundations/module-09-stronger-template-interfaces/lesson.md`
- `foundations/module-09-stronger-template-interfaces/assignment/README.md`
- `foundations/module-09-stronger-template-interfaces/assignment/group_by.h`
- `foundations/module-09-stronger-template-interfaces/tests/test_group_by.cpp`

Inspect this first:

- start with `tests/test_group_by.cpp`
- identify what the tests say about the selector input, the key type, the return shape, and ordering
- then read the lesson so the test expectations connect to the template-design idea

## Recommended Flow

1. Read the lesson for the interface-design goal.
2. Open the assignment README and translate the contract bullets into implementation constraints.
3. Read the test file from top to bottom before editing `group_by.h`.
4. Update the header, rebuild, and run the module test loop.
5. Repeat until the contract and tests line up.

## Build And Test Loop

Run these commands from the repository root:

```bash
cmake --build build --target module_09_tests
ctest --test-dir build --output-on-failure -R module_09_group_by
```

Use that loop every time you change `assignment/group_by.h`. Even though the assignment is header-only, rebuild `module_09_tests` before running `ctest` so the test binary picks up your latest edit.

## Orientation

If this module feels more strict than earlier ones, that is the point. The goal is not to make templates more complicated. The goal is to make generic behavior easier to understand, easier to call correctly, and easier to diagnose when the contract is violated.
