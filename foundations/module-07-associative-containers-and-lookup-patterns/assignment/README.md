# Assignment

Implement `TagIndex` in `tag_index.h` so it stores document ids under each tag and returns matching ids in sorted order.

The test expects lookup results to be stable and deterministic even when documents are added in a different order. That means the index can use fast associative lookup internally, but `lookup("cpp")` must always return ids sorted alphabetically.

Keep the implementation small. This exercise is about making the behavior contract explicit, not building a full search engine.
