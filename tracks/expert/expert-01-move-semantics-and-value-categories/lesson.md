# Lesson

Move semantics is mostly about value categories and ownership transfer.

- An **lvalue** names an object with identity. If you can point to the thing and say "that one," it is usually an lvalue.
- An **rvalue** is an expression you are allowed to treat as temporary or about to be consumed.
- A **copy** duplicates state.
- A **move** transfers state so the source can be left valid but unspecified.

The critical warning is that `std::move` does not move anything on its own. It is a cast that says, "treat this expression as eligible for moving." The actual move happens only if the target type provides a move constructor or move assignment operator and chooses to use that permission.

That means this:

```cpp
Traceable value{"cpp"};
auto moved = std::move(value);
```

does not magically copy data into `moved` by itself. It simply gives the move constructor a chance to run.

The practical habit is simple:

- use `std::move` when you are done with a named object and want to hand its resources off
- do not use `std::move` just because it looks "faster"
- prefer readability first; the compiler will only move when the types support it

