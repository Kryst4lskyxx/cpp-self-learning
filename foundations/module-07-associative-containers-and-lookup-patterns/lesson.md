# Lesson

Associative containers are about tradeoffs, not just APIs.

`std::map` and `std::set` keep keys ordered, which makes iteration and deterministic output easy to reason about. `std::unordered_map` and `std::unordered_set` optimize for lookup speed, but they do not promise any iteration order.

The practical question is usually: what does the caller need from the lookup?

- if the caller needs stable sorted output, make that part of the contract
- if the caller only needs membership checks or fast access by key, prefer the unordered form
- if you need both fast lookup and sorted results, keep lookup and presentation separate

This module's assignment makes that boundary explicit: the index stores tags efficiently, but lookup returns document ids in sorted order so the result is predictable.
