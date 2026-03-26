# Assignment

Implement `text_stats.cpp` so `analyze_text` returns the number of lines, words, and bytes in a piece of text.

## Implementation Steps

1. Read `tests/test_text_stats.cpp` and restate the contract in plain language: one input string produces one `TextStats` result with `lines`, `words`, and `bytes`.
2. Set `bytes` from the original string first. That part should not depend on any parsing loop.
3. Use stream-based parsing for the other two counts so the behavior matches the standard library instead of a custom rule set.
4. Keep the implementation focused on the shipped contract. You do not need a reusable text-analysis framework.

## Hands-On Checkpoints

- Confirm that empty input would produce zero lines, zero words, and zero bytes.
- Check your line-counting logic against a blank line in the middle of the input. Blank lines still count.
- Check your word-counting logic against repeated spaces or tabs. Whitespace should separate words without producing empty tokens.
- Make sure a trailing newline does not add a phantom extra line.

## Final Verification

Run:

```bash
cmake --build build --target module_02_tests
ctest --test-dir build -R module_02_text_stats
```

Use the standard library directly. The goal is to practice `std::string`, stream parsing, and a small amount of container use without drifting beyond the test contract.
