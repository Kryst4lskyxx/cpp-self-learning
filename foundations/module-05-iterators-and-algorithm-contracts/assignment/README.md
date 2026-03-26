# Assignment

Implement `is_sorted_for_binary_search` in `assignment/contract_checks.h`.

## Implementation Steps

1. Read the test cases first so you can see the contract in concrete form: a sorted vector should pass, and an unsorted vector should fail.
2. Make the helper answer one question only: does the full iterator range satisfy the binary-search sortedness precondition?
3. Use the standard library to express that check directly rather than re-creating search logic by hand.

## Test-Driven Checkpoints

- Start with the sorted input from the test and confirm the helper returns `true`.
- Add the unsorted input and confirm the helper returns `false`.
- Keep the implementation generic over range-like inputs with `begin()` and `end()`.

## Final Verification

After the helper is in place, run `ctest --test-dir build -R module_05_contract_checks` and make sure the Module 05 test target still passes cleanly.
