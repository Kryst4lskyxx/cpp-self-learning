# Foundations

This directory is the first build-visible step in the learner path.

Ordered curriculum shape:

1. `foundations/` - core C++ and build fundamentals
2. `projects/` - small applied exercises built from the foundations
3. `tracks/expert/` - narrower paths for deeper specialization

The generic-programming arc now extends the foundations path:

- `module-05-iterators-and-algorithm-contracts`
- `module-06-algorithmic-data-transformation`
- `module-07-associative-containers-and-lookup-patterns`
- `module-08-callable-objects-and-customization`
- `module-09-stronger-template-interfaces`

Current scope:

- The foundations index exists so the root build can register the directory.
- Modules 01-04 establish the original foundations slice.
- Modules 05-09 extend that slice through iterators, algorithm pipelines, associative containers, callables, and stronger template interfaces.
- The shipped modules now use a more guided tutorial format with setup steps, code examples, and assignment checkpoints.
- The index will grow by adding module directories here in order.
