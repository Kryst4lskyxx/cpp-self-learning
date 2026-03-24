# Lesson

This module is about turning text into simple measurements.

The key bridge for experienced programmers is that C++ usually gives you two ways to work:

- string operations on the text itself
- stream extraction for parsing it incrementally

For this module, `std::getline` splits text into lines, `std::istringstream` parses words from each line, and a container such as `std::vector` can hold the intermediate lines when that makes the logic easier to follow.

Example shape:

```cpp
std::istringstream input(text);
std::string line;

while (std::getline(input, line)) {
    // analyze one line at a time
}
```

Keep the first pass small. Count what the assignment asks for, and do not over-generalize the parser.
