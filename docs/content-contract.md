# Content Contract

Every learning module should follow the same shape so the repo stays predictable.

## Required Layout

- `README.md`: entry point, prerequisites, outcomes, and navigation.
- `lesson.md`: short concept notes.
- `drills/`: focused practice exercises.
- `assignment/`: the main hands-on task and starter code.
- `tests/`: validation for the drills and assignment.
- `expert/`: optional advanced extensions for the same topic.
- `solutions/`: reference implementations or instructor-only material when needed.

## Required Metadata

Every module should state:

- who it is for
- what prerequisites are expected
- what the learner should be able to do after finishing
- which files the learner is expected to edit
- how to run the relevant build or test command

## Authoring Rules

- Keep lessons short and code-oriented.
- Put real work in drills and assignments, not in long prose.
- Add tests for every deterministic exercise where practical.
- Keep module boundaries clear so one topic stays in one place.
- Do not add a module without a clear validation path.

## Expert Extensions

- Treat `expert/` as optional depth tied to the same topic.
- State dependencies on the core module before assigning expert work.
- Keep expert material clearly separated from the base assignment.
