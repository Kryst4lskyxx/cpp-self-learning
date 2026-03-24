# Lesson

This module is about getting one C++ program from source to a runnable binary.

What to notice:

- `assignment/main.cpp` becomes the `module_01_assignment` target
- CMake turns that target into the `module_01_assignment` executable
- the test launches that executable and checks its output
- the drill is a quick local experiment in `drills/hello_cli.cpp`

Example:

```bash
cmake --build build --target module_01_assignment
./build/foundations/module-01-tooling-and-first-program/module_01_assignment
```

Keep the first pass small. One source file, one binary, one expected line of output.
