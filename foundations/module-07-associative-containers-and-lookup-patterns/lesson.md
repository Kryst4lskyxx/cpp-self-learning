# Lesson

Associative containers are about tradeoffs, not just APIs.

`std::map` and `std::set` keep keys ordered, which makes iteration and deterministic output easy to reason about. `std::unordered_map` and `std::unordered_set` optimize for lookup speed, but they do not promise any iteration order.

The practical question is usually: what does the caller need from the lookup?

- if the caller needs stable sorted output, make that part of the contract
- if the caller only needs membership checks or fast access by key, prefer the unordered form
- if you need both fast lookup and sorted results, keep lookup and presentation separate

This module's assignment makes that boundary explicit: the index can store tags efficiently, but lookup still has to return document ids in sorted order so the result is predictable.

## Code Examples

```cpp
std::map<std::string, int> ordered_counts;
std::unordered_map<std::string, int> fast_counts;
```

Both containers answer the same key question, but they make different promises about order.

```cpp
index["cpp"].push_back("doc-2");
index["cpp"].push_back("doc-1");
std::ranges::sort(index["cpp"]);
```

That split is the core pattern the assignment uses.

## Common Mistakes

- Expecting an unordered container to return results in insertion order.
- Letting internal storage order leak into the public contract.
- Sorting only once at insertion time and then forgetting that later updates can change the final result.
- Debugging the container choice before checking whether the lookup result itself satisfies the contract.
