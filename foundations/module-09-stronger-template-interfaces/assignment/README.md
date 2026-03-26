# Assignment

Implement `group_by` in `group_by.h` so it groups a range of values by a caller-provided key selector.

The point of this assignment is not the loop itself. The point is to make the generic contract visible in the template interface.

## Contract To Implement

Your function should make these expectations clear:

- the input range can be read through `const Range&`
- the selector accepts each input value from that const range
- the selector result can be used as the key in an ordered `std::map`
- input values are stored in result buckets, so the range value type must be copy-constructible
- values that produce the same key are collected into the same bucket
- each bucket preserves original input order
- the selector is invoked once per input value

## Implementation Steps

1. Open `tests/test_group_by.cpp` and translate each test into one sentence about the contract.
2. Open `group_by.h` and decide what the template needs to know about:
   - the range
   - the selector input
   - the selector result
   - the return type
3. Write or refine the template boundary first. In this module, the `requires` clause and the return type are part of the assignment, not decoration.
4. Only after the contract is clear, fill in the loop that places each value into the correct bucket.
5. Rebuild and run the module test target after every meaningful change to the header.

## Checkpoints

Checkpoint 1: can you explain what type the selector receives?

- If not, inspect the range as a `const` range before touching the body.

Checkpoint 2: can you explain why the selector result is valid as a map key?

- If not, your interface is probably still too vague.

Checkpoint 3: can you describe the return shape without reading the implementation?

- A caller should be able to predict that `group_by` returns a map from selected key to grouped values.

Checkpoint 4: can you point to the test that proves bucket order is preserved?

- If you cannot, reread the tests before changing the loop.

Checkpoint 5: can you point to the test that proves the selector is not called extra times?

- If not, inspect the test expectations again before "simplifying" the implementation.

## Final Verification

Run these commands from the repository root:

```bash
cmake --build build --target module_09_tests
ctest --test-dir build --output-on-failure -R module_09_group_by
```

Because `group_by.h` is included into the test target, rebuild before running `ctest` whenever you edit the header. Do not assume a previous test binary already contains your latest change.

Use the standard library and keep the interface focused. The goal is to make the template contract obvious without turning the assignment into a framework exercise or copying a fully worked solution.
