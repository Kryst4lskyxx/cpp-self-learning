# Lesson

Callable objects are how C++ keeps behavior flexible without forcing everything into a class hierarchy.

The caller can supply a lambda, function pointer, or function object, and the algorithm can treat that callable as the customization point. That is a good fit for simple filtering and ranking helpers because the core loop stays fixed while the policy changes.

This module uses two small patterns:

- a threshold filter, where the caller supplies a threshold and an optional comparator
- a ranker, where the caller controls how each value is scored before sorting

Keep the implementations small and explicit. The point is to make the customization point visible in the API, not to build a general-purpose framework.

## Code Examples

```cpp
auto ranked = rank_values(values, [](int value) { return value * 10; });
```

The callable decides how values are scored without changing the ranking helper itself.

```cpp
auto filtered = threshold_filter(values, 5, std::less<int>{});
```

The same pattern works for filtering: the callable carries the policy.

## Common Mistakes

- Treating the callable as an afterthought instead of the main customization point.
- Mixing up the callable's job with the algorithm's job.
- Forgetting to preserve the original value when you return a scored result.
- Ignoring tie behavior and then discovering that equal scores come back in an unstable order.
