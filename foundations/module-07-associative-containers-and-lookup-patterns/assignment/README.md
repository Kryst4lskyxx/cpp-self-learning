# Assignment

Implement `TagIndex` in `tag_index.h` so it stores document ids under each tag and returns matching ids in sorted order.

The tests define the contract: lookup results must be stable and deterministic even when documents are added in a different order.

## Implementation Steps

1. Read the tests first and restate the lookup contract in your own words before touching the header.
2. Decide how to store the tag data so lookup stays efficient, then shape the public result so callers always get sorted ids.
3. Keep duplicate document ids out of the returned result and make insertion order irrelevant to lookup output.

## Hands-On Checkpoints

- Start with the missing-tag case so you know lookup returns an empty result when nothing matches.
- Confirm that adding the same document twice does not duplicate its id in the lookup result.
- Check insertion-order independence next by adding the same tag from different documents in different orders.
- Verify that the returned ids stay sorted even when the underlying storage is optimized for lookup rather than output order.

## Final Verification

After any change to `tag_index.h`, rebuild the test binary with `cmake --build build --target module_07_tests`, then run `ctest --test-dir build -R module_07_tag_index`. Do not rely on `ctest` alone for a header-only change.
