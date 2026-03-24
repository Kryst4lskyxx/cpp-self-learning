# Assignment

Implement `text_stats.cpp` so `analyze_text` returns the number of lines, words, and bytes in a piece of text.

Semantics for this module:

- `bytes` is `text.size()`
- `words` follow `operator>>` tokenization on whitespace
- `lines` are the non-delimiter results from `std::getline`

That means:

- empty input produces zero lines, zero words, and zero bytes
- repeated whitespace does not create extra words
- a trailing newline does not create an extra line
- blank lines between delimiters do count as lines

The test input for this module is expected to produce:

- lines: `2`
- words: `4`
- bytes: `24`

Use the standard library directly. The goal is to practice `std::string`, stream parsing, and a small amount of container use, not to build a full text library.
