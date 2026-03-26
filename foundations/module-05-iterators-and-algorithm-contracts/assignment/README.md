# Assignment

Implement `is_sorted_for_binary_search` in `assignment/contract_checks.h`.

The tests show one sorted example and one unsorted example, but your job is to infer the general range contract and express it with the smallest direct standard-library check.

## Implementation Steps

1. Read the tests as contract evidence: identify the range property that makes binary search valid, then state that property in your own words.
2. Make the helper answer one question only: does the full iterator range satisfy the binary-search sortedness precondition?
3. Use the standard library to express that check directly instead of rebuilding a search routine or mirroring the fixtures.

## Test-Driven Checkpoints

- Start from the contract, not the test data: a range that stays in ascending order should pass, and a range that breaks that order should fail.
- Verify the helper against the provided examples after you have a direct check in place.
- Keep the implementation generic over range-like inputs with `begin()` and `end()`.

## Final Verification

After any edit to the header, rebuild the test binary with `cmake --build build --target module_05_tests`, then run `ctest --test-dir build -R module_05_contract_checks`. Do not rely on `ctest` alone for a header-only change.
