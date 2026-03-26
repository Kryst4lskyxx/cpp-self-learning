# Lesson

This module is about making object boundaries explicit: what data the class owns, which operations mutate it, and which operations are safe to call through a `const` object.

A member function marked `const` changes the type of the hidden `this` pointer. Inside that function, the object is treated as read-only. That is why a search function can be `const`, while a function that appends a new book cannot.

Private data is the second part of the design. The caller should not manage the catalog directly. Instead, the class exposes a small public interface such as:

- add a book
- ask for the number of stored books
- search for a book by title without mutating the collection

The test in this module also cares about the result type. Returning a read-only reference-like value lets the caller inspect a found book without copying the entire object or mutating the stored data.

## Code Examples

```cpp
Library library;
library.add_book({"Effective Modern C++", "Scott Meyers", 2014});
```

This operation mutates the catalog, so it is a normal non-`const` member function.

```cpp
const Library library = make_sample_library();
const auto result = library.find_by_title("Effective Modern C++");

if (result) {
    const Book& book = result->get();
    // inspect book.title, book.author, book.year
}
```

Here the search runs through a `const Library`, so the API must promise not to modify the owned collection.

## Common Mistakes

- Marking the return type `const` but forgetting to mark the member function itself `const`. If the test says the function cannot be called on a `const Library`, inspect the function declaration first.
- Returning a mutable reference or pointer from a read-only search API. The test is guarding the idea that lookup should not let the caller mutate stored books through the result.
- Returning a reference-like result that does not clearly represent "not found." If lookup can fail, use a result type that makes absence explicit.
- Mutating the collection during search. If `size()` changes after calling `find_by_title`, set a breakpoint or log inside the search path and verify that the code only reads from `books_`.
