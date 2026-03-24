# Assignment

Implement `filter_values` in `query_engine.h` so it returns the values from a container that satisfy a predicate.

The test expects generic behavior:

- the input can be a `std::vector<int>`
- the predicate is passed in as a lambda
- the returned vector contains only the matching elements, in their original order

Use templates and standard algorithms. The goal is to practice the C++ way of expressing generic behavior, not to build a large query system.

`std::back_inserter` is the bridge from the algorithm to the destination vector: it turns the container into an output iterator that appends each accepted element with `push_back`.
