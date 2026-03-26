# C++ Self-Learning Repo V3 Tutorial Docs Plan

## Overview

This plan executes the approved V3 design for in-place tutorial-style refinement of the shipped `foundations/` path. The work is documentation-focused and should preserve the current code, tests, and repo structure.

The plan is phased:

1. establish the tutorial pattern on representative modules
2. propagate that pattern across the remaining foundations modules
3. update repo-level learner navigation only if the first pass exposes a concrete mismatch

## Guardrails

- Do not edit module code or tests unless a documentation change reveals a tiny contract mismatch that must be corrected to keep docs truthful.
- Keep `assignment/README.md` contract-focused; do not turn it into a worked solution.
- Keep code examples short and explanatory, not solution-like.
- Prefer edits to `README.md`, `lesson.md`, and `assignment/README.md`.
- Only edit `drills/README.md` when the current drill text is too terse to explain the drill goal, expected input/output shape, or likely debugging path.
- Only edit root navigation docs if the first-pass modules expose a real navigation mismatch.

## Tutorial Template

Each rewritten module should follow this default file mapping:

- `README.md`
  - `What You'll Build`
  - `Before You Start`
  - optional short `Wrap-Up` pointer
- `lesson.md`
  - concept explanation
  - code examples
  - common mistakes
- `assignment/README.md`
  - contract-focused implementation steps
  - step-by-step checkpoints tied to the tests
  - final verification reminder

## Task 1: Establish the Pattern on Module 01

**Files:**
- Modify: `foundations/module-01-tooling-and-first-program/README.md`
- Modify: `foundations/module-01-tooling-and-first-program/lesson.md`
- Modify: `foundations/module-01-tooling-and-first-program/assignment/README.md`
- Optional: `foundations/module-01-tooling-and-first-program/drills/README.md`

**Requirements:**
- Add a clearer beginner entry to the foundations flow using the approved tutorial structure.
- Make the test-first workflow explicit.
- Add small code examples that clarify the first-program/tooling concepts.
- Add likely mistakes/debugging tips without giving away the full implementation.

**Verification:**
- Review the docs for consistency with the actual file layout and test command.

## Task 2: Establish the Pattern on Module 05

**Files:**
- Modify: `foundations/module-05-iterators-and-algorithm-contracts/README.md`
- Modify: `foundations/module-05-iterators-and-algorithm-contracts/lesson.md`
- Modify: `foundations/module-05-iterators-and-algorithm-contracts/assignment/README.md`
- Optional: `foundations/module-05-iterators-and-algorithm-contracts/drills/README.md`

**Requirements:**
- Apply the same tutorial structure in the middle of the foundations path.
- Make iterator-range reasoning and contract inspection more step-by-step.
- Use short examples that clarify half-open ranges and sortedness contracts.
- Keep the assignment doc contract-focused rather than solution-like.

**Verification:**
- Review the docs for consistency with the module test and assignment contract.

## Task 3: Establish the Pattern on Module 09

**Files:**
- Modify: `foundations/module-09-stronger-template-interfaces/README.md`
- Modify: `foundations/module-09-stronger-template-interfaces/lesson.md`
- Modify: `foundations/module-09-stronger-template-interfaces/assignment/README.md`
- Optional: `foundations/module-09-stronger-template-interfaces/drills/README.md`

**Requirements:**
- Apply the tutorial structure to the most conceptually demanding shipped foundations module.
- Keep the docs precise about template requirements and test-driven contract discovery.
- Add short code examples and debugging guidance that help learners reason about constrained generic interfaces.
- Ensure the doc tone remains practical rather than advanced-language-theory-heavy.

**Verification:**
- Review the docs for consistency with the current `group_by` contract and test shape.

## Task 4: Propagate the Pattern Across Modules 02-04 and 06-08

**Files:**
- Modify:
  - `foundations/module-02-strings-streams-and-collections/README.md`
  - `foundations/module-02-strings-streams-and-collections/lesson.md`
  - `foundations/module-02-strings-streams-and-collections/assignment/README.md`
  - `foundations/module-03-classes-and-const-correctness/README.md`
  - `foundations/module-03-classes-and-const-correctness/lesson.md`
  - `foundations/module-03-classes-and-const-correctness/assignment/README.md`
  - `foundations/module-04-templates-and-stl/README.md`
  - `foundations/module-04-templates-and-stl/lesson.md`
  - `foundations/module-04-templates-and-stl/assignment/README.md`
  - `foundations/module-06-algorithmic-data-transformation/README.md`
  - `foundations/module-06-algorithmic-data-transformation/lesson.md`
  - `foundations/module-06-algorithmic-data-transformation/assignment/README.md`
  - `foundations/module-07-associative-containers-and-lookup-patterns/README.md`
  - `foundations/module-07-associative-containers-and-lookup-patterns/lesson.md`
  - `foundations/module-07-associative-containers-and-lookup-patterns/assignment/README.md`
  - `foundations/module-08-callable-objects-and-customization/README.md`
  - `foundations/module-08-callable-objects-and-customization/lesson.md`
  - `foundations/module-08-callable-objects-and-customization/assignment/README.md`
- Optional selected `drills/README.md` files only if they meet the trigger in the spec

**Requirements:**
- Propagate the approved tutorial structure and tone from the first-pass modules.
- Keep the level of guidance medium and consistent.
- Preserve contract-focused assignment docs.
- Add code examples and common-mistake guidance where they reduce likely confusion.

**Verification:**
- Review the docs module by module for structure consistency and contract accuracy.

## Task 5: Conditional Navigation Polish

**Files:**
- Modify only if needed:
  - `README.md`
  - `docs/learning-path.md`
  - `foundations/README.md`

**Trigger:**
- Do this task only if the rewritten first-pass modules expose a concrete learner-navigation mismatch.

**Requirements:**
- Clarify the guided workflow at the repo level without widening scope.
- Keep the docs truthful about shipped content and the tutorialized foundations path.

**Verification:**
- Run: `rg -n "module-01|module-05|module-09|foundations" README.md docs foundations`
- Confirm repo-level wording matches the refined tutorial workflow.

## Task 6: Final Consistency Pass

**Files:**
- Review all modified tutorial docs from Tasks 1-5

**Requirements:**
- Ensure consistent section ordering and voice.
- Ensure code examples stay short and non-solution-like.
- Ensure assignment docs remain contract-focused.
- Ensure no doc promises behavior broader than the tests or implementation support.

**Verification:**
- Review diffs for consistency and scope control.

## Suggested Execution Order

1. Module 01
2. Module 05
3. Module 09
4. Remaining modules
5. Conditional navigation polish
6. Final consistency pass

## Completion Criteria

The iteration is complete when:

- the representative modules establish a clear reusable tutorial pattern
- the remaining shipped foundations modules follow that same structure and tone
- learner-facing docs are more guided without becoming solution dumps
- any root doc edits are justified by an actual navigation gap
- the rewritten docs stay accurate to the shipped code and tests
