# Lesson

This module is about turning one `std::string` into a few concrete measurements without building a big parser.

Two standard-library tools matter here:

- `std::getline` reads one line at a time from a stream and removes the delimiter from the returned string.
- `operator>>` on a stream reads one whitespace-delimited word at a time.

That split matters because the assignment counts three different things:

- bytes from the original string
- lines using `std::getline` semantics
- words using stream extraction semantics

`std::istringstream` is the bridge from raw text to stream-based parsing. It lets you use the same extraction rules on a string that you would use on file input.

## Code Examples

```cpp
std::istringstream input("alpha beta\n\ngamma");
std::string line;

while (std::getline(input, line)) {
    // line is "alpha beta", then "", then "gamma"
}
```

`std::getline` returns the text between delimiters. A blank line still produces an empty string, which is why blank lines count as lines in this module.

```cpp
std::istringstream words("alpha   beta\tgamma");
std::string word;

while (words >> word) {
    // word is "alpha", then "beta", then "gamma"
}
```

Stream extraction skips repeated whitespace automatically. That is why extra spaces do not create extra words.

## Common Mistakes

- Counting lines by counting `'\n'` characters. Debug this by testing an input with no trailing newline and one with a trailing newline. `std::getline` does not create an extra line just because the string ends with `'\n'`.
- Counting words by splitting only on spaces. The test contract uses normal stream extraction rules, so tabs and repeated spaces should also behave as whitespace.
- Forgetting that `bytes` is the original `text.size()`, not the sum of parsed words or lines.
- Overcomplicating the parser. If your implementation starts inventing custom tokenization rules, compare it against the test again and reduce it to the standard-library behavior the module is teaching.
