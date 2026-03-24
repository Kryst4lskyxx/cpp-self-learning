# Tooling

The default workflow is CLI-first on macOS or Linux, using `clang++` and CMake.

## Setup

- Install a recent C++ toolchain with `clang++`, `cmake`, and `ctest`.
- Run all commands from the repository root unless a module says otherwise.

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Test

```bash
ctest --test-dir build
```

## Notes

- Prefer the root build over ad hoc compiler invocations.
- Use the shared helpers in `tooling/` when a module needs reusable test or build support.
- Keep commands short and reproducible so learners can copy them directly into a terminal.
