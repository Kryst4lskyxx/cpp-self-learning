# Lesson

This module is about the two ideas that make C++ generic code practical:

- templates are compile-time recipes, so one function can work for many concrete types
- STL algorithms operate on iterators, which means the same loop pattern can work across containers

The key mental model is that a template does not "run for everything." It is instantiated for the specific types you pass in, and the compiler checks whether the operations you use are valid for those types.

`std::back_inserter` is worth knowing here because it adapts a container into an output iterator. That lets `std::copy_if` append matches without you writing a manual `push_back` loop.

For the assignment, that means a small filtering helper can stay generic while still using familiar tools like `std::copy_if` and `std::back_inserter`:

```cpp
template <typename Range, typename Predicate>
auto filter_values(const Range& values, Predicate predicate)
    -> std::vector<std::remove_cvref_t<decltype(*std::begin(values))>>;
```

Keep the implementation small. Use the standard library directly instead of inventing a mini query language.
