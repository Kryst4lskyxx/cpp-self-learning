# Assignment

Implement `group_by` in `group_by.h` so it groups a range of values by a caller-provided key selector.

The test expects the helper to accept a lambda and to return a map keyed by the selector result. Keep the contract explicit:

- the selector is called for each input value
- values that produce the same key are collected into the same bucket
- each bucket preserves the original input order

Use a template and the standard library. The point of the exercise is to make a generic interface precise enough that the caller can tell what the helper requires and what it returns.

