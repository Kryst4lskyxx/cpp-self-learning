# cpp-self-learning

This is an AI-native C++ self-learning project generated with Codex.

This repository contains a working first learning slice:
- four `foundations/` modules
- one synthesis project in `projects/`
- one optional expert module in `tracks/expert/`

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
- `projects/project-01-mini-search-engine`
- `tracks/expert/expert-01-move-semantics-and-value-categories`
