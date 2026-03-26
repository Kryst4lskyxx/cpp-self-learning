# Lesson

This module is about the shortest useful C++ loop: write one source file, build one executable, and let the module test confirm the executable's output.

## Concept

`assignment/main.cpp` is the source file CMake compiles into the `module_01_assignment` target. That target becomes a runnable program in the build tree, and the test suite launches that program instead of re-implementing the logic itself.

That test-led shape matters for beginners:

- the source file stays tiny
- the build step tells you whether the code compiles
- the test tells you whether the program behaves exactly as expected

## Code Examples

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

The module uses two separate commands for the two checks:

```bash
cmake --build build --target module_01_assignment
ctest --test-dir build -R module_01_hello_cli
```

## Common Mistakes

- Printing extra text, prompts, or blank lines that break the test contract.
- Editing the drill instead of `assignment/main.cpp`.
- Building successfully and assuming the module test will pass without running it.
- Using a shell command to print the right output instead of changing the program itself.
- Forgetting that exact output includes the newline character.
- If the test fails, compare the program output to the expected string character by character, including the newline.
- If the build fails, check the target name and rebuild the assignment target before rerunning the module test.
