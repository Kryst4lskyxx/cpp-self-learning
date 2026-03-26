# Lesson

Generic code gets easier to trust when the template boundary says what the algorithm actually depends on.

In this module, the important shift is from "this template works for lots of things" to "this template is explicit about the things it works for." That means the signature should tell the reader:

- what kind of range can be read
- what argument the selector must accept
- what kind of value the selector returns
- why that returned value is valid for the container you want to build

For `group_by`, the algorithm is simple: inspect each element, compute a key, and place the value into the matching bucket. The interface matters more than the loop. If the result is an ordered `std::map`, then the selector result has to behave like an ordered key. If the function reads from `const Range&`, then the range must be readable through a const view. If the selector is invoked on each element, its parameter type needs to match what the range yields.

This is where modern C++ helps. Concepts and `requires` clauses let you describe these assumptions at the function boundary instead of leaving them buried in implementation details or compiler errors from deep inside the standard library.

## Code Examples

Example: a vague template that hides its assumptions

```cpp
template <typename Range, typename Helper>
auto group_by(const Range& values, Helper helper);
```

This tells the reader almost nothing. What does `helper` receive? What does it return? Why would that return type work in the result?

Example: a more explicit shape

```cpp
template <typename Range, typename KeySelector>
requires /* Range is readable as const */
      && /* KeySelector accepts each element */
      && /* selector result can be used as an ordered key */
auto group_by(const Range& values, KeySelector key_selector);
```

This still leaves details for the implementation, but it makes the contract visible. A caller can reason about whether their range and selector belong here before reading the body.

Example: return type follows the selector result

```cpp
auto grouped = group_by(words, [](const std::string& word) {
    return word.size();
});
```

From the call site, you should be able to predict that the result is conceptually "a map from key to grouped values." The selected key type is not guessed by a hidden rule. It comes directly from the selector.

Example: bucket order is a separate part of the contract

```cpp
std::vector<std::string> values{"beta", "a", "gamma", "bb"};
auto grouped = group_by(values, [](const std::string& value) {
    return value.size() % 2;
});
```

Two values may land in the same bucket even when they are far apart in the input. The contract should still make it clear whether each bucket preserves original input order. That behavior belongs in tests because it is observable API behavior.

## Common Mistakes

### Using a callable constraint that is too vague

If the selector constraint says little more than "some callable exists," the function can accept inputs that do not match the intended contract. When that happens, errors often appear later in the body instead of at the signature.

Debugging move:

- compare the selector's parameter type with the type yielded by iterating the range as `const`
- if they do not match, tighten the constraint so the mismatch is rejected earlier

### Forgetting that the result container imposes requirements too

If the function returns `std::map<Key, ...>`, then `Key` is not arbitrary. The key type must satisfy the ordering expectations of that container.

Debugging move:

- start from the concrete return container
- ask what the container requires from its key type
- then make that requirement visible in the template interface

### Letting the body require more than the signature promises

A template can look precise and still hide an assumption in the implementation. For example, if the body stores copies of input values, then the function implicitly depends on those values being storable in the destination container.

Debugging move:

- inspect every operation in the body that constructs, copies, or stores values
- check whether those operations depend on properties that the signature never mentions
- if the interface is meant to teach explicit contracts, do not ignore that mismatch

### Reading tests only as pass/fail checks

In this module, the tests are also part of the tutorial. They describe the contract: return shape, grouping behavior, call frequency, and ordering.

Debugging move:

- before editing the header, rewrite each test in plain English
- use those notes as a checklist while you work

Keep the interface narrow. The assignment is not about building a reusable data-processing framework. It is about expressing one generic operation clearly enough that the caller, the compiler, and the tests all agree on what it requires.
