# Assignment

Implement `normalize_and_unique` in `pipeline.h` so it normalizes a list of words, sorts them, and removes duplicates.

The tests define the behavior: a word list should come back normalized, sorted, and deduplicated, with the transformation order preserved.

## Implementation Steps

1. Read the tests as the contract, then restate the transformation in your own words before editing the header.
2. Build the smallest direct pipeline that satisfies that contract: normalize the words, sort the result, and remove adjacent duplicates.
3. Keep the implementation focused on range transformation rather than on parsing or container design.

## Hands-On Checkpoints

- Start with the empty-input case so you know the helper behaves cleanly with no words.
- Confirm that already-normalized unique input stays in the same logical order after processing.
- Check a mixed-case input next so you can see normalization and deduplication working together.
- Use the provided examples to verify that the pipeline order, not just the final output, matches the contract.

## Final Verification

After any change to `pipeline.h`, rebuild the test binary with `cmake --build build --target module_06_tests`, then run `ctest --test-dir build -R module_06_pipeline`. Do not rely on `ctest` alone for a header-only change.
