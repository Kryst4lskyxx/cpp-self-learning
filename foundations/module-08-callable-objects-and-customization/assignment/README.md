# Assignment

Implement `rank_values` in `ranker.h` so it scores a range of values with a caller-provided callable, then returns the values ordered from highest score to lowest.

The test expects the helper to accept a lambda and to expose the original value in the ranked result. Keep the API small and predictable:

- the caller supplies the scoring function
- the helper computes a score for each value
- the result is sorted so the highest score appears first
- equal scores keep the same order as the input range

Use a template and the standard library. The goal is to practice injecting behavior with a callable, not to build a full ranking engine.
