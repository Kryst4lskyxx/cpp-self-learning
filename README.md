# cpp-self-learning

This is an AI-native C++ self-learning project generated with Codex.

This repository contains a working curriculum slice:
- nine `foundations/` modules
- one synthesis project in `projects/`
- one optional expert module in `tracks/expert/`

The V2 generic-programming arc now includes:
- `foundations/module-05-iterators-and-algorithm-contracts`
- `foundations/module-06-algorithmic-data-transformation`
- `foundations/module-07-associative-containers-and-lookup-patterns`
- `foundations/module-08-callable-objects-and-customization`
- `foundations/module-09-stronger-template-interfaces`

Current execution status:
- V1 is shipped with foundations Modules 01-04, Project 01, and Expert 01
- V2 foundations Modules 05-09 are implemented in-tree as the generic-programming arc
- learner-facing navigation and build registration now reflect the shipped foundations path

Start with [docs/learning-path.md](docs/learning-path.md) to see the current path through the repo, then use [docs/tooling.md](docs/tooling.md) for the build and test commands.

Build and test from the repository root:

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build
```

## Documentation Checklist

- [x] Learning path
- [x] Tooling guide
- [x] Content contract
- [x] Contributor guide

## Docs

- [Learning path](docs/learning-path.md)
- [Tooling guide](docs/tooling.md)
- [Content contract](docs/content-contract.md)
- [Contributor guide](docs/contributing.md)

## Current Content

- `foundations/module-01-tooling-and-first-program`
- `foundations/module-02-strings-streams-and-collections`
- `foundations/module-03-classes-and-const-correctness`
- `foundations/module-04-templates-and-stl`
- `foundations/module-05-iterators-and-algorithm-contracts`
- `foundations/module-06-algorithmic-data-transformation`
- `foundations/module-07-associative-containers-and-lookup-patterns`
- `foundations/module-08-callable-objects-and-customization`
- `foundations/module-09-stronger-template-interfaces`
- `projects/project-01-mini-search-engine`
- `tracks/expert/expert-01-move-semantics-and-value-categories`

## Current Focus

- extend the curriculum beyond the shipped V2 foundations arc
- add more projects and expert-track material in later iterations
