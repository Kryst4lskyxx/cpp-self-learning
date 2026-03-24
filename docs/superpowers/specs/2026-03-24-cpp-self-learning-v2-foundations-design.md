# C++ Self-Learning Repo V2 Foundations Design

## Summary

The next iteration should extend the existing `foundations/` path rather than widening the repo with more projects or expert modules. V2 will add a second arc to the foundations curriculum focused on generic programming, STL algorithms, iterators, callable customization, and stronger practical template interfaces.

This iteration should stay close to the CS106L spine, but use the repo's added value to make this part of the learning path more explicit, more testable, and more self-study friendly than the course materials alone.

## Why This Iteration

V1 established the repo structure and proved the format:

- four foundations modules
- one synthesis project
- one expert module
- working build and test infrastructure
- learner-facing navigation and content contracts

The highest-value next step is not more scaffolding. It is more core curriculum. The current foundations path gets learners to templates and STL basics, but it does not yet carry them through the harder middle section where C++ starts to feel idiomatic rather than merely usable.

## Goals

- Extend the `foundations/` path with a focused generic-programming arc.
- Keep the repo centered on self-study through short lessons, drills, assignments, and tests.
- Stay close to the CS106L ordering and teaching style in this section.
- Improve learners' practical fluency with iterators, algorithms, containers, predicates, and template interfaces.
- Strengthen the continuity of the foundations path so it feels like one coherent curriculum rather than a starter slice followed by a gap.

## Non-Goals

- Adding another synthesis project in this iteration.
- Adding another expert-track module in this iteration.
- Broad CI, platform, or tooling expansion unrelated to the new foundations modules.
- Jumping into advanced metaprogramming, allocators, or constraints-heavy design before the practical generic-programming layer is established.
- Reorganizing the repo structure created in V1.

## Scope

V2 is a foundations-only expansion. It should add four to five new modules after the current first four foundations modules.

The result should be:

- a stronger continuous path inside `foundations/`
- no new top-level curriculum branches
- no new synthesis project
- no new expert-track module

This keeps the iteration disciplined and prevents scope from widening before the core path is deep enough.

## Proposed Module Arc

### Module 05: Iterators and Algorithm Contracts

Focus:

- iterator ranges as the core STL abstraction
- practical iterator categories
- algorithm preconditions and why they matter
- container-independent code

Outcome:

Learners understand why STL algorithms operate on iterator pairs instead of containers and can reason about the shape of inputs algorithms expect.

### Module 06: Algorithmic Data Transformation

Focus:

- `transform`
- `copy_if`
- `sort`
- `unique`
- `partition`
- replacing loops with algorithm pipelines where it improves clarity

Outcome:

Learners can express common data-processing tasks with standard algorithms and understand the trade-offs between hand-written loops and STL composition.

### Module 07: Associative Containers and Lookup Patterns

Focus:

- `map`
- `unordered_map`
- `set`
- ordering vs hashing
- lookup semantics
- API choices driven by query patterns

Outcome:

Learners can choose associative containers intentionally and design code around the kinds of lookups they need.

### Module 08: Callable Objects and Customization

Focus:

- predicates
- lambdas
- captures
- function objects
- algorithm customization through callable behavior

Outcome:

Learners can use algorithms with custom behavior instead of hard-coding logic into each loop or container operation.

### Module 09: Stronger Template Interfaces

Focus:

- template parameter shape
- type deduction in practical APIs
- communicating generic contracts clearly
- failure modes from weak generic assumptions
- light contract expression, with constraints only if the implementation remains practical and self-study friendly

Outcome:

Learners can design and read small generic interfaces that are more robust than ad hoc template code.

## Integration with the Current Repo

These new modules should live directly under `foundations/` and continue the existing naming and ordering scheme.

Each module should keep the same contract already established in V1:

- `README.md`
- `lesson.md`
- `drills/`
- `assignment/`
- `tests/`
- `expert/`

Each module should also keep the stronger patterns established during implementation of V1:

- a first-class assignment target or library target
- linked tests instead of ad hoc compilation patterns
- learner-facing docs that accurately describe tested behavior
- tests that pin down the public contract rather than only demonstrating a happy path

## Teaching Principles for This Arc

This part of the curriculum should teach generic programming as practical engineering, not as abstract language worship.

That means:

- start from useful data-processing or lookup problems
- use algorithms and iterators because they solve those problems cleanly
- explain templates as a way to express reusable code over varying types and ranges
- keep lessons focused on the C++ mental model that differs from other languages

For this audience, the most important bridges are:

- algorithms work on ranges, not on containers as magical special cases
- iterator and callable contracts matter
- STL power comes from composition
- generic code becomes fragile when its assumptions are implicit

## Testing Expectations

Compared with early V1 modules, these modules should hold a tighter testing line.

Each module should:

- test more than one happy path where the public contract would otherwise stay ambiguous
- pin down documented semantics with direct tests
- avoid documentation that promises broader behavior than the tests or implementation support

This is especially important in generic-programming modules, where API shape and contract clarity are part of the lesson.

## Documentation Updates Required

As the new modules are added, the repo docs should be updated so the current learning path reflects the longer foundations sequence.

At minimum, implementation planning should account for updates to:

- `README.md`
- `docs/learning-path.md`
- `foundations/README.md`

These updates should happen as the new modules become real, not as speculative placeholders.

## Success Criteria

This iteration is successful if:

- `foundations/` grows from a starter slice into a more continuous curriculum
- the new modules form a coherent second arc centered on practical generic programming
- learners can move from the current templates/STL basics into a deeper algorithm/container/template section without a conceptual gap
- tests and docs are tighter than the early V1 baseline
- the repo remains disciplined in scope instead of widening into more projects or expert material too early

## Implementation Guidance

Implementation planning should sequence these modules in order and preserve continuity with the existing first four foundations modules.

The next implementation plan should focus on:

- adding the new foundations modules one by one
- keeping build/test patterns consistent
- strengthening contract tests where generic behavior would otherwise stay ambiguous
- updating repo navigation as the path becomes real

No implementation should begin until this new iteration is translated into a concrete plan.
