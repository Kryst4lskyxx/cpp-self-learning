# Expert 01: Move Semantics and Value Categories

This module is for learners who already understand classes, references, and basic object lifetime.

What you should be able to do after this module:

- distinguish lvalues from rvalues
- explain the difference between copy and move operations
- remember that `std::move` is a cast, not a move by itself
- use a tiny traceable helper to observe those operations in tests

Files to edit:

- `drills/traceable.h`

Validation:

- `cmake --build build`
- `ctest --test-dir build -R expert_01 -V`

