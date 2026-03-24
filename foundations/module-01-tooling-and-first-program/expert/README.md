# Expert Note

This module is intentionally small.

The important pattern is the wiring:

- module index registers a subdirectory
- module CMake builds the exercise executable
- tests run the built binary instead of duplicating its logic

Keep that pattern intact as the curriculum grows.
