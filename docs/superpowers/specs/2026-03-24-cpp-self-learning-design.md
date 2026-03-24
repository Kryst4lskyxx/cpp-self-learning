# C++ Self-Learning Repo Design

## Summary

Build a self-learning C++ repository for intermediate developers who already know another programming language and want to learn modern C++ deeply. The curriculum should use Stanford CS106L and the `cs106l-assignments` repository as the primary spine, while extending that structure into a project-heavy learning system that can scale from practical foundations to expert-level topics.

The repository is a hybrid of concise lessons, drills, assignments, and larger projects, but it should bias strongly toward doing. Reading material exists to unblock hands-on work, not to become a long-form textbook. The end state is a staged curriculum that begins with modern C++ foundations and can grow into advanced language internals, performance, concurrency, and library-level depth.

## Goals

- Teach modern C++ to experienced programmers new to the language.
- Use CS106L as the canonical ordering for early and mid-stage topics.
- Make hands-on work the primary learning vehicle.
- Provide built-in validation for every module where practical.
- Support a high ceiling that eventually reaches expert-level depth.
- Keep the repository structure predictable so learners can focus on C++ instead of navigation.

## Non-Goals

- Teaching general programming or CS fundamentals from scratch.
- Reproducing the full Stanford course site inside the repository.
- Building all beginner-to-expert content in the first implementation pass.
- Supporting every possible toolchain equally in v1.
- Turning the repo into a reference encyclopedia before the curriculum exists.

## Audience

The primary audience is intermediate developers who already know at least one other language and want to become strong in modern C++. They may understand programming concepts well but need help with C++-specific models such as ownership, value vs reference semantics, RAII, templates, STL idioms, build tooling, and performance-sensitive design.

This audience choice changes the tone of the material:

- explain what is unique or surprising about C++
- skip generic programming lectures
- move quickly into real code, debugging, and design trade-offs
- frame lessons in terms of differences from other languages

## Product Direction

The recommended structure is a layered curriculum repository:

- `foundations/` for the CS106L-aligned core path
- `projects/` for synthesis work that combines multiple topics
- `tracks/expert/` for optional advanced and low-level material
- `tooling/` for shared build, test, and helper infrastructure
- `docs/` for navigation, contributor rules, and authoring guidance

This is preferred over a plain course mirror because the goal is broader than reproducing CS106L. The repo should preserve CS106L's teaching order where it is strong, then attach bridge material for self-learners and optional depth for advanced study.

## Learning Model

The repo should be project-heavy and use a repeatable per-module learning flow:

1. `why-it-matters`
   A short explanation of why the topic matters for real C++ work, written for experienced developers.
2. `core-concepts`
   Concise notes covering only the material required to start solving problems.
3. `drills`
   Small exercises focused on one concept or failure mode at a time.
4. `assignment`
   The main hands-on task, usually adapted from CS106L or built around the same objective.
5. `extensions`
   Optional harder work that deepens understanding or broadens applicability.

The learner should spend most of their time writing, debugging, and refining code. Notes exist to support that activity, not replace it.

## Staged Progression

The curriculum should be organized into three stages.

### Stage 1: Foundations

Focus areas:

- syntax and compilation model
- standard library fundamentals
- strings, streams, and containers
- functions, references, and const correctness
- classes and object semantics
- introductory templates and generic code

Outcome:

Learners can read, build, debug, and write idiomatic small-to-medium modern C++ programs.

### Stage 2: Practical Engineering

Focus areas:

- RAII and resource management
- smart pointers and ownership models
- iterators and algorithms
- error handling patterns
- testing and debugging workflows
- modular project structure and build systems

Outcome:

Learners can implement and maintain multi-file C++ programs using idiomatic resource and API design.

### Stage 3: Expert Depth

Focus areas:

- move semantics internals
- advanced templates and metaprogramming
- constraints and type traits
- allocators and memory resources
- concurrency primitives and trade-offs
- performance measurement and optimization
- low-level behavior and implementation details

Outcome:

Learners can reason about advanced language behavior, performance, and library design with near-expert depth.

## Module Contract

Every module should use a consistent layout so the repo is predictable:

- `README.md`
  Entry point, prerequisites, expected outcomes, and navigation.
- `lesson.md`
  Short concept notes for the topic.
- `drills/`
  Focused, smaller exercises.
- `assignment/`
  Main task statement and starter code.
- `tests/`
  Validation for drills and assignment code.
- `solutions/`
  Clearly separated reference implementations or instructor versions.
- `expert/`
  Optional advanced extensions tied to the same theme.

This contract reduces cognitive overhead, makes authoring consistent, and enables shared tooling.

## Content Strategy

The curriculum should derive core modules from CS106L, then augment them in two ways.

### Bridge Additions

These make CS106L easier to use as a self-study resource:

- local development setup
- build and test workflow
- debugging instructions
- terminology clarifications
- common learner mistakes
- explicit prerequisite mapping between modules

### Depth Additions

These raise the ceiling beyond the original course:

- stronger STL and generic programming coverage
- deeper ownership and move semantics analysis
- constraints, metaprogramming, and type traits
- allocator-aware design and memory resources
- concurrency and performance-focused extensions

Expert material should branch from earlier modules rather than fork the curriculum into a disconnected second repo.

## Tooling Strategy

The default path should target macOS/Linux command-line development.

### Default Stack

- `clang++` as the documented default compiler
- `CMake` as the primary build system
- CLI-first commands for configuring, building, and testing

This gives the repo one clear workflow and avoids early complexity from trying to optimize for every environment at once.

### Validation Model

The testing strategy should support different exercise shapes:

- compile-only checks for API shape or syntax-focused tasks
- unit-style tests for deterministic logic
- run-based checks for CLI assignments where output matters

All modules should expose clear commands to build and validate the learner's work.

## Repository Rules

To keep the repo maintainable, all content should follow shared authoring conventions:

- every module declares prerequisites
- every module declares learning outcomes
- every assignment states which files learners are expected to edit
- every test target has a single clear command to run
- every expert extension states its dependencies
- concept notes remain concise and code-oriented

The repo should prefer consistent patterns over clever one-off structures.

## V1 Scope

The first implementation should prove the learning system end to end, not attempt to fill the entire roadmap.

### Include in V1

- root repository structure
- learner-facing navigation and contribution docs
- shared `CMake` skeleton
- shared testing utilities and conventions
- three to five complete core modules based on early CS106L topics
- one larger synthesis project
- one or two expert extensions that demonstrate the high-ceiling model

### Defer from V1

- full beginner-to-expert curriculum coverage
- broad platform-specific setup guides
- many empty placeholder modules
- advanced topic coverage before the core path is proven

## Testing and Verification Expectations

The repository itself should be testable as content is added:

- build all modules from the root
- run tests per module
- support running a single module in isolation
- verify starter code and tests remain in sync

As the repo grows, CI can enforce that module contracts, builds, and tests remain valid.

## Risks

### Risk: Scope Explosion

The stated ambition spans practical C++ learning through expert-level depth. Without discipline, the project can become a large unfinished scaffold.

Mitigation:

- implement only a small number of full modules in v1
- maintain a strict distinction between roadmap and shipped content
- require each new module to satisfy the full module contract

### Risk: Weak Self-Study Experience

CS106L is strong, but course materials often assume instructor context.

Mitigation:

- add bridge material for setup, debugging, and common misconceptions
- make every module self-navigable with explicit prerequisites and commands
- prefer self-checking assignments over ambiguous exercises

### Risk: Expert Track Drift

Advanced content can feel disconnected if it grows separately from the core path.

Mitigation:

- hang expert extensions off existing modules where possible
- reuse shared tooling and patterns
- state dependency links clearly

## Success Criteria

The design is successful if:

- a learner can start at the root and understand the path through the repo
- each module has a predictable structure and clear commands
- the first few modules provide enough momentum for self-study without external hand-holding
- assignments and tests reinforce real C++ habits instead of toy syntax drills
- the repo has a credible path from foundations to expert depth without forcing all of that scope into v1

## Implementation Guidance

Implementation should begin with infrastructure and a small number of finished teaching units, not with broad scaffolding. The initial plan should focus on:

- root structure and conventions
- shared build/test foundation
- first core modules
- first synthesis project
- first expert extension slice

Further planning should translate this design into discrete implementation steps and sequencing.
