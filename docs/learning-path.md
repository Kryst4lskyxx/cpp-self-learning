# Learning Path

This repository is organized for experienced programmers who already know another language and want a practical path into modern C++.

## Intended Curriculum

1. `foundations/`
   Start here for core language mechanics, standard library basics, and small exercises.
2. `projects/`
   Move here once the foundations feel familiar. These modules combine multiple topics into one larger buildable task.
3. `tracks/expert/`
   Use this for optional advanced material after the core path is comfortable.

## How To Use It

- Read the module `README.md` first.
- Skim the lesson, then work the drills before starting the assignment.
- Build and test from the command line with the commands in [tooling.md](tooling.md).
- Treat expert sections as extensions, not prerequisites, unless a module says otherwise.

## Current Scope

The curriculum layout above is now populated through the first generic-programming arc. The current repository includes:

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

The path is still incomplete relative to the long-term roadmap, but the full V2 foundations arc is now live instead of planned.

The generic-programming sequence now ships as part of the foundations path:

- [x] module-05-iterators-and-algorithm-contracts
- [x] module-06-algorithmic-data-transformation
- [x] module-07-associative-containers-and-lookup-patterns
- [x] module-08-callable-objects-and-customization
- [x] module-09-stronger-template-interfaces

## What Each Stage Should Cover

- `foundations/`: syntax, compilation, strings, streams, containers, references, const correctness, classes, templates, and STL basics.
- `projects/`: multi-topic synthesis and bigger exercises that force real design decisions.
- `tracks/expert/`: move semantics, advanced templates, constraints, allocators, concurrency, and performance-oriented material.
