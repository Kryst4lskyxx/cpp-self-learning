# Lesson

Generic code gets easier to use when the interface makes its assumptions visible.

This module is about two habits:

- accept the specific callable the algorithm needs, instead of hiding behavior behind a vague helper
- make the selector input and ordered key result explicit at the template boundary
- derive the return type from the selector result so the caller can see what comes back

That usually means the template signature should spell out the range element type, the selector input, and the selected key type. If the key is meant for an ordered map, the signature should say so directly. The compiler can then check the contract for you instead of letting ambiguous code compile until runtime surprises show up.

For the assignment, the helper groups values by a caller-provided selector:

```cpp
template <typename Range, typename KeySelector>
requires /* range is readable as const, selector accepts each element, key is ordered */
auto group_by(const Range& values, KeySelector key_selector);
```

Keep the interface narrow. The point is not to build a universal data framework, but to make one generic operation precise enough that its behavior is obvious from the signature and the tests.
