# Lesson

Callable objects are how C++ keeps behavior flexible without forcing everything into a class hierarchy.

The caller can supply a lambda, function pointer, or function object, and the algorithm can treat that callable as the customization point. That is a good fit for simple filtering and ranking helpers because the core loop stays fixed while the policy changes.

This module uses two small patterns:

- a threshold filter, where the caller controls what counts as a match
- a ranker, where the caller controls how each value is scored before sorting

Keep the implementations small and explicit. The point is to make the customization point visible in the API, not to build a general-purpose framework.
