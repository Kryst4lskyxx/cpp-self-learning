# Assignment

Implement `is_sorted_for_binary_search` in `assignment/contract_checks.h`.

The tests show one sorted example and one unsorted example, but your job is to infer the general range contract and express it with the smallest direct standard-library check.

## Implementation Steps

1. Read the tests as contract evidence: identify the range property that makes binary search valid, then state that property in your own words.
2. Make the helper answer one question only: does the full iterator range satisfy the binary-search sortedness precondition?
3. Use the standard library to express that check directly instead of rebuilding a search routine or mirroring the fixtures.

## Test-Driven Checkpoints

- Read the tests first and let them drive a red-green loop: identify the contract, write the smallest check that satisfies it, then confirm the result.
- Keep the first pass as small as possible: make the contract cases go green with one direct standard-library expression.
- Re-run the tests after each edit to confirm the generic range contract you derived.

## Final Verification

After any edit to the header, rebuild the test binary with `cmake --build build --target module_05_tests`, then run `ctest --test-dir build -R module_05_contract_checks`. Do not rely on `ctest` alone for a header-only change.
