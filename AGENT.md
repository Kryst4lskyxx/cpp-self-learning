# AGENT.md

## Purpose

This repository is a C++ self-learning curriculum, not a generic product codebase.
Agents working here should optimize for:

- clear learner-facing explanations
- small, testable curriculum increments
- reproducible build and test commands
- minimal, well-scoped changes that preserve the current learning path

Read these first before making structural or content changes:

- `README.md`
- `docs/learning-path.md`
- `docs/tooling.md`
- `docs/content-contract.md`
- `docs/contributing.md`

## Repo Map

- `foundations/`: core learning modules
- `projects/`: synthesis projects that combine prior skills
- `tracks/expert/`: optional advanced material beyond the main path
- `tooling/`: shared scripts, test helpers, and CMake support
- `cmake/`: shared CMake configuration
- `docs/`: learner-path, tooling, and authoring rules

Most work should stay local to one module or one project unless the task explicitly requires broader changes.

## Core Working Rules

- Prefer small, focused edits over broad curriculum rewrites.
- Do not add placeholder folders or incomplete scaffolding.
- Do not refactor unrelated modules while working on a specific lesson or exercise.
- Keep learner-facing text short, direct, and action-oriented.
- Preserve the existing directory naming and module layout conventions.
- Keep commands reproducible from the repository root unless the local README explicitly says otherwise.
- When adding or changing exercises, keep the validation path obvious and runnable.

## Canonical Build And Test Commands

Run from the repository root:

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build
```

Use the root build and test flow by default. Avoid ad hoc compiler commands unless the task explicitly requires them.

If you change a specific module, prefer verifying at least the relevant tests in addition to any broader verification the task warrants.

## Module Editing Rules

Learning modules are expected to follow the contract in `docs/content-contract.md`.

For module work:

- keep `README.md` as the module entry point
- keep `lesson.md` short and code-oriented
- put focused practice in `drills/`
- put the main exercise in `assignment/`
- keep `tests/` aligned with drills and assignment behavior
- treat `expert/` as optional depth, not required core content

Each module should make it easy for a learner to answer:

- what this module teaches
- what prerequisites are assumed
- which files they are expected to edit
- how they verify their work

## Code And Test Expectations

- Follow existing CMake patterns rather than inventing parallel build flows.
- Reuse shared tooling in `tooling/` when possible.
- Prefer simple, readable modern C++ over clever abstractions.
- Keep starter code and tests aligned with the learner’s current stage.
- Tests should reinforce the lesson goal, not introduce unrelated complexity.
- When changing public exercise interfaces, update the corresponding tests and README instructions together.

## Documentation Update Triggers

Update docs when your change affects any of these:

- learner progression or module ordering: `docs/learning-path.md`
- build, test, or setup workflow: `docs/tooling.md`
- required module shape or authoring rules: `docs/content-contract.md`
- contributor expectations or repo workflow: `docs/contributing.md`
- top-level shipped content summary: `README.md`

## Change Scope Guidance

Good agent changes in this repo usually look like:

- improving one module’s lesson, drills, assignment, or tests
- adding one well-scoped module or project with full validation
- tightening tooling or documentation to support the existing curriculum

Poor agent changes usually look like:

- restructuring multiple modules without a direct task requirement
- adding content without tests or a clear verification path
- expanding scope with speculative abstractions or future-proofing
- replacing concise teaching material with long conceptual essays

## Definition Of Done

Before considering work complete, confirm:

- the change is scoped to the requested learning outcome
- learner-facing instructions still match the code and tests
- relevant build and test commands have been run
- any impacted top-level or module docs were updated
- the repository remains in a usable state for the next learner or agent
