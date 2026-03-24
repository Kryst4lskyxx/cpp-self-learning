# Assignment

Implement a small `Library` type with private book storage and a const-correct search API.

The test expects:

- `Library::find_by_title(...)` to be callable on a `const Library`
- the search to leave the catalog size unchanged
- the result to report whether a matching book was found

Keep the design small. A `Book` value type and a `std::vector<Book>` are enough.

Remember: a `const` member function means the hidden `this` parameter points to const, so search can inspect but not mutate the `Library`. If you return a reference-like result, its lifetime is tied to the `Library` that owns the book.
