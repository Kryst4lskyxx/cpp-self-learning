# Assignment

Implement `rank_values` in `ranker.h` so it scores a range of values with a caller-provided callable, then returns the values ordered from highest score to lowest.

The tests define the contract: the helper must accept a callable, keep the original value attached to each score, and order the result from highest score to lowest.

## Implementation Steps

1. Read the tests first and describe the ranking contract in your own words before editing the header.
2. Make the helper score each value with the callable the caller supplies, then build the smallest ranked result that preserves the original value.
3. Sort the scored results by descending score while keeping equal scores in input order.

## Hands-On Checkpoints

- Start with the empty-input case so you can confirm the helper handles no values cleanly.
- Check that a simple scoring lambda produces the expected score/value pairs.
- Verify that higher scores come first regardless of the original input order.
- Confirm that tied scores keep the input order instead of jumping around.

## Final Verification

After any change to `ranker.h`, rebuild the test binary with `cmake --build build --target module_08_tests`, then run `ctest --test-dir build -R module_08_ranker`. Do not rely on `ctest` alone for a header-only change.
