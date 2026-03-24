# Expert Note

The important C++ idea here is not inheritance or abstraction. It is object state and const-correctness:

- a `const` member function can be called through a const object
- if a function only reads state, mark it `const`
- use private data to keep invariants inside the class
- prefer returning read-only access when callers should not own or mutate the data

If the interface makes mutation impossible, the implementation gets simpler and the tests become more precise.
