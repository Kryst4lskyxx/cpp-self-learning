# Drill

Implement `Traceable` in `traceable.h`.

The helper should make move semantics visible in a test:

- construct it from a string payload
- copy or move it without breaking the type
- record how many copy and move operations happened to the current object

Keep it header-only and focused. The point is to observe value categories, not to build a general-purpose wrapper around `std::string`.

