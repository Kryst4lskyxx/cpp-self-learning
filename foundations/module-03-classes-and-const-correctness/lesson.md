# Lesson

This module is about the difference between “can I call this on a const object?” and “does this function mutate state?” in C++.

What to notice:

- member functions marked `const` promise not to modify the observable object state
- a `const Library` can still search and report its size
- private data keeps the collection controlled, while public member functions define the API
- returning `const Book*` or `std::optional<std::reference_wrapper<const Book>>` keeps search read-only

Example:

```cpp
const Library library = make_sample_library();
const auto result = library.find_by_title("Effective Modern C++");

if (result) {
    // read-only access to the found book
}
```

The key mental model is simple: `const` applies to the object you are calling through, not just to the return type.
