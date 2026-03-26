# Assignment

This module is a contract exercise, not a broken starter. The checked-in repo already contains a passing `assignment/main.cpp`, so use the test as the source of truth for the behavior and the module-specific build/test loop.

## Checkpoints

1. Read `foundations/module-01-tooling-and-first-program/tests/test_hello_cli.cpp` and note the exact output string it expects.
2. Build the assignment target with `cmake --build build --target module_01_assignment`.
3. Run only the Module 01 test with `ctest --test-dir build -R module_01_hello_cli`.
4. If you are practicing the edit in your own branch or scratch checkout, change only `assignment/main.cpp`.
5. Rebuild the target and rerun the same module test after any change.

The contract is strict:

- the output must match exactly
- the newline is part of the expected result
- no extra stdout should appear before or after the greeting

## Final Verification

When the module test passes, rerun `cmake --build build --target module_01_assignment` and `ctest --test-dir build -R module_01_hello_cli` once more before you consider the assignment complete.
