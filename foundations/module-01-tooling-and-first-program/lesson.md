# Lesson

This module is about the shortest useful C++ loop: write one source file, build one executable, and let a test confirm the executable's output.

## Concept

`assignment/main.cpp` is the source file CMake compiles into the `module_01_assignment` target. That target becomes a runnable program in the build tree, and the test suite launches that program instead of re-implementing the logic itself.

That test-first shape matters for beginners:

- the source file stays tiny
- the build step tells you whether the code compiles
- the test tells you whether the program behaves exactly as expected

## Small Examples

The assignment follows the same pattern as a minimal C++ CLI:

```cpp
#include <iostream>

int main() {
    std::cout << "hello\n";
}
```

The build target is also simple and explicit:

```cmake
add_executable(module_01_assignment assignment/main.cpp)
```

When you build the target, CMake produces the executable that the test later runs:

```bash
cmake --build build --target module_01_assignment
ctest --test-dir build
```

## Common Mistakes

- Printing extra text, prompts, or blank lines that break the test contract.
- Editing the drill instead of `assignment/main.cpp`.
- Building successfully and assuming the test will pass without running `ctest`.
- Using a shell command to print the right output instead of changing the program itself.
- Forgetting that exact output includes the newline character.
