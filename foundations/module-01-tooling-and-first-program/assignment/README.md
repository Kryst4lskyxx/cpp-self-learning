# Assignment

Your task is to make the assignment executable satisfy the contract checked by `tests/test_hello_cli.cpp`.

## Checkpoints

1. Read the test first and note the exact output string it expects.
2. Change only `assignment/main.cpp`.
3. Keep the program direct: one executable, one line of output, no interactive prompts.
4. Build the assignment target and run the full test suite with `ctest --test-dir build`.

The contract is strict:

- the output must match exactly
- the newline is part of the expected result
- no extra stdout should appear before or after the greeting

## Final Verification

When the test passes, rerun `ctest --test-dir build` once more before you consider the assignment complete.
