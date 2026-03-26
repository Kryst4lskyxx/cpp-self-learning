# C++ Self-Learning Repo V3 Tutorial Docs Design

## Summary

The next iteration should improve the learning experience of the shipped `foundations/` path rather than widening the repo with more curriculum surface area. V3 will refine the existing module docs in place so the foundations sequence reads more like a guided self-study tutorial with step-by-step checkpoints, focused code examples, and practical debugging hints.

This iteration should preserve the current code, tests, and repo structure. The main change is editorial: the docs should better support hands-on learning for experienced programmers who are new to modern C++.

## Why This Iteration

The repo now has a real curriculum slice:

- nine foundations modules
- one synthesis project
- one expert module
- a working build and test path
- learner-facing docs that accurately reflect shipped content

At this point, the highest-value improvement is not adding more modules immediately. It is making the current modules easier to learn from. The foundations arc is now long enough that sparse or uneven module docs will create more learner friction than missing future topics.

## Goals

- Refine the shipped foundations modules in place so they are more tutorial-like.
- Add step-by-step exercise structure without turning the repo into an answer key.
- Add focused code examples where they clarify a concept or next step.
- Add practical debugging hints and common-mistake guidance.
- Keep the repo’s current module contract and overall structure intact.
- Make the foundations sequence feel consistent from Module 01 through Module 09.

## Non-Goals

- Adding new foundations modules in this iteration.
- Adding another synthesis project in this iteration.
- Adding another expert-track module in this iteration.
- Rewriting the code or tests of shipped modules unless a documentation fix requires a tiny contract clarification.
- Introducing separate tutorial books or standalone walkthrough folders outside the current module structure.

## Scope

V3 is a documentation-focused refinement pass over the shipped `foundations/` modules.

The primary targets are:

- each module `README.md`
- each module `lesson.md`
- each module `assignment/README.md`

Secondary targets, only where needed:

- selected `drills/README.md` files
- top-level learner navigation docs if the tutorial workflow needs clearer framing

The implementation should prefer in-place improvement over new documentation branches. Learners should still move through the repo using the same files and directories they use today.

Secondary edits should follow strict triggers:

- edit a `drills/README.md` only if the current drill text is too terse to explain the drill goal, expected input/output shape, or likely debugging path
- edit top-level learner navigation docs only if the first-pass modules expose a concrete navigation mismatch, such as the root docs not explaining the refined tutorial workflow clearly enough

If no such gap appears during the first pass, these secondary edits should be deferred.

## File Mapping

The tutorial structure should map onto the existing module contract consistently.

Default distribution:

- `README.md`
  - `What You'll Build`
  - `Before You Start`
  - a short `Wrap-Up` pointer if the module needs one
- `lesson.md`
  - core concept explanation
  - `Code Examples`
  - `Common Mistakes`
- `assignment/README.md`
  - contract-focused implementation steps
  - step-by-step checkpoints tied directly to the test-driven exercise
  - final verification reminder

Additional rule:

- `assignment/README.md` must remain contract-focused. It should not become a worked solution or absorb most of the conceptual teaching. Tutorial scaffolding should live primarily in `README.md` and `lesson.md`, unless a module truly needs a small assignment-level checkpoint to keep the learner moving.

This file distribution should be the default for all rewritten modules. Deviations should be rare and justified by the module shape.

## Tutorial Structure

Each foundations module should move toward a consistent teaching flow.

### 1. What You'll Build

A short explanation of what the learner is implementing and why the exercise matters in practical C++.

### 2. Before You Start

A quick setup section that states:

- prerequisites
- which files to open
- which test command to run
- what the learner should inspect first

### 3. Step-by-Step Exercise

A sequence of checkpoints that guides the learner without giving away the full solution. Typical steps:

- inspect the tests
- identify the contract
- implement the smallest useful piece
- rerun tests
- extend to the next behavior
- verify the final contract

### 4. Code Examples

Small, focused examples that explain a concept or pattern. These should clarify a mental model, not dump the final answer.

### 5. Common Mistakes

A short list of likely errors and how to debug them. These should be concrete and tied to the actual module contract.

### 6. Wrap-Up

A short summary of what the learner should understand after finishing the module.

## Guidance Level

This iteration should target medium guidance, not minimal notes and not lab-manual-level handholding.

That means:

- more explicit checkpoints than the current docs
- code snippets where they reduce confusion
- direct debugging advice when a mistake is likely
- no full worked solutions

The learner should still do real problem solving, but the next action should be much clearer than it is in the current terse modules.

Guardrails for examples and walkthrough depth:

- code examples should stay short, usually a few lines to one small block
- examples should explain a concept or API shape, not reproduce the final assignment implementation
- assignment-adjacent snippets may illustrate one step, but they should not chain into a near-complete answer
- examples should prefer toy or isolated fragments unless a real file-level snippet is necessary to remove ambiguity

## Rollout Strategy

This should be implemented in phases rather than as one flat rewrite of all nine modules.

### Phase 1: Set the Pattern

Apply the new tutorial structure to representative modules:

- `module-01-tooling-and-first-program`
- `module-05-iterators-and-algorithm-contracts`
- `module-09-stronger-template-interfaces`

These three modules cover the beginning, middle, and current high end of the foundations path.

### Phase 2: Propagate Consistently

Rewrite the remaining foundations modules using the same structure and tone.

### Phase 3: Navigation Polish

Update repo-level docs so the learning path clearly explains the more guided workflow and points learners at the refined foundations sequence.

Approval of this spec means a full V3 doc-refinement iteration is intended, but implementation planning should still sequence the work phase by phase. Phase 1 establishes the template first; Phase 2 and Phase 3 complete the rest of the shipped foundations path and navigation polish.

## Teaching Principles

The doc rewrite should preserve the repo’s current audience: experienced programmers learning modern C++.

That means the writing should:

- explain what is distinct about the C++ mental model
- keep the pace practical rather than academic
- prefer short, purposeful code examples over long explanations
- tell learners where to look when they are stuck
- keep terminology precise without sounding textbook-heavy

The docs should help learners act, not just understand in the abstract.

## Consistency Requirements

The rewrite should keep module docs aligned with tested behavior.

That means:

- do not describe behavior that the tests do not enforce
- do not imply broader APIs than the code actually exposes
- keep code examples consistent with the real file layout and function names
- make the step-by-step guidance match the actual implementation path a learner will take

If a documentation improvement exposes a real mismatch between docs and tests, that should be surfaced as implementation planning follow-up rather than silently ignored.

## Success Criteria

This iteration is successful if:

- the foundations path reads like a guided self-study sequence instead of a sparse scaffold
- learners can see the next concrete action at each module step
- the docs include useful code examples without collapsing into solution dumps
- the teaching style is consistent across the rewritten modules
- the repo structure remains stable and recognizable

## Implementation Guidance

The next implementation plan should:

- start with the representative first-pass modules
- define a reusable doc template for module rewrites
- keep edits focused on learner-facing files
- include a consistency pass so root docs reflect the refined tutorial workflow

No implementation should begin until this design is translated into a concrete plan.
