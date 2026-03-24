# C++ Self-Learning Repo V1 Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Build the first working version of a CS106L-based, project-heavy C++ self-learning repository with shared build/test infrastructure, 3-5 complete core modules, one synthesis project, and one expert extension.

**Architecture:** The repo will be organized around a stable learner-facing structure: `foundations/` for the core path, `projects/` for synthesis work, `tracks/expert/` for advanced extensions, `tooling/` for shared infrastructure, and `docs/` for navigation and authoring rules. Implementation should establish shared `CMake` and test conventions first, then add a small number of fully realized teaching units that prove the content model end to end.

**Tech Stack:** C++, CMake, clang++, CTest, Markdown, shell scripts

---

## Planned File Structure

### Root

- Create: `CMakeLists.txt`
- Create: `README.md`
- Create: `.clang-format`
- Create: `.editorconfig`
- Create: `cmake/Warnings.cmake`
- Create: `cmake/Testing.cmake`

### Docs

- Create: `docs/learning-path.md`
- Create: `docs/contributing.md`
- Create: `docs/content-contract.md`
- Create: `docs/tooling.md`

### Shared tooling

- Create: `tooling/README.md`
- Create: `tooling/scripts/configure.sh`
- Create: `tooling/scripts/build.sh`
- Create: `tooling/scripts/test.sh`
- Create: `tooling/cmake/AddLearningModule.cmake`
- Create: `tooling/tests/CMakeLists.txt`
- Create: `tooling/tests/assertions.h`
- Create: `tooling/tests/assertions.cpp`
- Create: `tooling/tests/test_main.cpp`

### Foundations modules

- Create: `foundations/README.md`
- Create: `foundations/module-01-tooling-and-first-program/README.md`
- Create: `foundations/module-01-tooling-and-first-program/lesson.md`
- Create: `foundations/module-01-tooling-and-first-program/CMakeLists.txt`
- Create: `foundations/module-01-tooling-and-first-program/drills/README.md`
- Create: `foundations/module-01-tooling-and-first-program/drills/hello_cli.cpp`
- Create: `foundations/module-01-tooling-and-first-program/assignment/README.md`
- Create: `foundations/module-01-tooling-and-first-program/assignment/main.cpp`
- Create: `foundations/module-01-tooling-and-first-program/tests/CMakeLists.txt`
- Create: `foundations/module-01-tooling-and-first-program/tests/test_hello_cli.cpp`
- Create: `foundations/module-01-tooling-and-first-program/expert/README.md`

- Create: `foundations/module-02-strings-streams-and-collections/README.md`
- Create: `foundations/module-02-strings-streams-and-collections/lesson.md`
- Create: `foundations/module-02-strings-streams-and-collections/CMakeLists.txt`
- Create: `foundations/module-02-strings-streams-and-collections/drills/README.md`
- Create: `foundations/module-02-strings-streams-and-collections/drills/word_count.cpp`
- Create: `foundations/module-02-strings-streams-and-collections/assignment/README.md`
- Create: `foundations/module-02-strings-streams-and-collections/assignment/text_stats.cpp`
- Create: `foundations/module-02-strings-streams-and-collections/tests/CMakeLists.txt`
- Create: `foundations/module-02-strings-streams-and-collections/tests/test_text_stats.cpp`
- Create: `foundations/module-02-strings-streams-and-collections/expert/README.md`

- Create: `foundations/module-03-classes-and-const-correctness/README.md`
- Create: `foundations/module-03-classes-and-const-correctness/lesson.md`
- Create: `foundations/module-03-classes-and-const-correctness/CMakeLists.txt`
- Create: `foundations/module-03-classes-and-const-correctness/drills/README.md`
- Create: `foundations/module-03-classes-and-const-correctness/drills/counter.h`
- Create: `foundations/module-03-classes-and-const-correctness/drills/counter.cpp`
- Create: `foundations/module-03-classes-and-const-correctness/assignment/README.md`
- Create: `foundations/module-03-classes-and-const-correctness/assignment/library.h`
- Create: `foundations/module-03-classes-and-const-correctness/assignment/library.cpp`
- Create: `foundations/module-03-classes-and-const-correctness/tests/CMakeLists.txt`
- Create: `foundations/module-03-classes-and-const-correctness/tests/test_library.cpp`
- Create: `foundations/module-03-classes-and-const-correctness/expert/README.md`

- Create: `foundations/module-04-templates-and-stl/README.md`
- Create: `foundations/module-04-templates-and-stl/lesson.md`
- Create: `foundations/module-04-templates-and-stl/CMakeLists.txt`
- Create: `foundations/module-04-templates-and-stl/drills/README.md`
- Create: `foundations/module-04-templates-and-stl/drills/range_utils.h`
- Create: `foundations/module-04-templates-and-stl/assignment/README.md`
- Create: `foundations/module-04-templates-and-stl/assignment/query_engine.h`
- Create: `foundations/module-04-templates-and-stl/assignment/query_engine.cpp`
- Create: `foundations/module-04-templates-and-stl/tests/CMakeLists.txt`
- Create: `foundations/module-04-templates-and-stl/tests/test_query_engine.cpp`
- Create: `foundations/module-04-templates-and-stl/expert/README.md`

### Synthesis project

- Create: `projects/README.md`
- Create: `projects/project-01-mini-search-engine/README.md`
- Create: `projects/project-01-mini-search-engine/CMakeLists.txt`
- Create: `projects/project-01-mini-search-engine/src/main.cpp`
- Create: `projects/project-01-mini-search-engine/src/index.h`
- Create: `projects/project-01-mini-search-engine/src/index.cpp`
- Create: `projects/project-01-mini-search-engine/data/sample_corpus.txt`
- Create: `projects/project-01-mini-search-engine/tests/CMakeLists.txt`
- Create: `projects/project-01-mini-search-engine/tests/test_index.cpp`

### Expert extension

- Create: `tracks/expert/README.md`
- Create: `tracks/expert/expert-01-move-semantics-and-value-categories/README.md`
- Create: `tracks/expert/expert-01-move-semantics-and-value-categories/lesson.md`
- Create: `tracks/expert/expert-01-move-semantics-and-value-categories/CMakeLists.txt`
- Create: `tracks/expert/expert-01-move-semantics-and-value-categories/drills/README.md`
- Create: `tracks/expert/expert-01-move-semantics-and-value-categories/drills/traceable.h`
- Create: `tracks/expert/expert-01-move-semantics-and-value-categories/tests/CMakeLists.txt`
- Create: `tracks/expert/expert-01-move-semantics-and-value-categories/tests/test_traceable.cpp`

## Task 1: Establish Root Build and Repo Conventions

**Files:**
- Create: `CMakeLists.txt`
- Create: `.clang-format`
- Create: `.editorconfig`
- Create: `cmake/Warnings.cmake`
- Create: `cmake/Testing.cmake`
- Modify: `README.md`
- Test: `CMakeLists.txt`

- [ ] **Step 1: Write the failing integration check**

Define the expected root build interface in `README.md` and `CMakeLists.txt` comments before implementation:

```cmake
# Expected commands after this task:
# cmake -S . -B build
# cmake --build build
# ctest --test-dir build
```

- [ ] **Step 2: Run configure to verify the root build is missing**

Run: `cmake -S . -B build`
Expected: FAIL because the repository does not yet expose a valid project configuration for the planned module layout.

- [ ] **Step 3: Write the minimal root build implementation**

Implement:

```cmake
cmake_minimum_required(VERSION 3.20)
project(cpp_self_learning LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/Warnings.cmake)
include(cmake/Testing.cmake)

enable_testing()
```

Add `.clang-format` and `.editorconfig` with simple repo-wide defaults compatible with `clang-format`.

- [ ] **Step 4: Run configure to verify the root project works**

Run: `cmake -S . -B build`
Expected: PASS and generate build files successfully.

- [ ] **Step 5: Commit**

```bash
git add CMakeLists.txt README.md .clang-format .editorconfig cmake/Warnings.cmake cmake/Testing.cmake
git commit -m "build: establish root CMake and repo conventions"
```

## Task 2: Add Shared Tooling and Test Helpers

**Files:**
- Create: `tooling/README.md`
- Create: `tooling/scripts/configure.sh`
- Create: `tooling/scripts/build.sh`
- Create: `tooling/scripts/test.sh`
- Create: `tooling/cmake/AddLearningModule.cmake`
- Create: `tooling/tests/CMakeLists.txt`
- Create: `tooling/tests/assertions.h`
- Create: `tooling/tests/assertions.cpp`
- Create: `tooling/tests/test_main.cpp`
- Modify: `CMakeLists.txt`
- Test: `tooling/tests/CMakeLists.txt`

- [ ] **Step 1: Write the failing shared-helper test target**

Add a reference in the root build for a helper library target that does not yet exist:

```cmake
add_subdirectory(tooling/tests)
```

- [ ] **Step 2: Run configure to verify the missing tooling target fails**

Run: `cmake -S . -B build`
Expected: FAIL because `tooling/tests/CMakeLists.txt` is not present yet.

- [ ] **Step 3: Implement minimal shared tooling**

Create:

```cmake
# tooling/tests/CMakeLists.txt
add_library(learning_test_support assertions.cpp)
target_include_directories(learning_test_support PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(learning_test_main test_main.cpp)
target_link_libraries(learning_test_main PUBLIC learning_test_support)
```

Create `AddLearningModule.cmake` with a helper function that registers a module subdirectory and associated tests.

- [ ] **Step 4: Run configure and build to verify shared tooling works**

Run: `cmake -S . -B build`
Expected: PASS

Run: `cmake --build build`
Expected: PASS

- [ ] **Step 5: Commit**

```bash
git add tooling CMakeLists.txt
git commit -m "build: add shared tooling and test support"
```

## Task 3: Write Learner and Authoring Docs

**Files:**
- Create: `docs/learning-path.md`
- Create: `docs/contributing.md`
- Create: `docs/content-contract.md`
- Create: `docs/tooling.md`
- Modify: `README.md`
- Test: `README.md`

- [ ] **Step 1: Write the failing doc checklist**

Create a checklist in `README.md` for docs that must exist:

```md
- [ ] Learning path
- [ ] Tooling guide
- [ ] Content contract
- [ ] Contributor guide
```

- [ ] **Step 2: Verify the referenced docs are missing**

Run: `rg --files docs`
Expected: output does not yet include all four planned docs.

- [ ] **Step 3: Write the initial docs**

Document:
- learner entry path through `foundations/`, `projects/`, and `tracks/expert/`
- setup/build/test commands
- module content contract
- contribution expectations for future modules

- [ ] **Step 4: Verify doc presence and links**

Run: `rg -n "learning-path|tooling|content-contract|contributing" README.md docs`
Expected: PASS with valid references in the root docs.

- [ ] **Step 5: Commit**

```bash
git add README.md docs
git commit -m "docs: add learning path and authoring guides"
```

## Task 4: Create Foundations Index and Module Registration

**Files:**
- Create: `foundations/README.md`
- Modify: `CMakeLists.txt`
- Test: `foundations/README.md`

- [ ] **Step 1: Write the failing root registration**

Add a root expectation that the foundations path exists:

```cmake
add_subdirectory(foundations)
```

- [ ] **Step 2: Run configure to verify the missing foundations directory fails**

Run: `cmake -S . -B build`
Expected: FAIL because `foundations/CMakeLists.txt` is missing.

- [ ] **Step 3: Implement foundations index**

Create a simple `foundations/CMakeLists.txt` that adds the first planned module directories as they are created. Add `foundations/README.md` explaining the ordered learner path.

- [ ] **Step 4: Run configure to verify foundations registration works**

Run: `cmake -S . -B build`
Expected: PASS once the `foundations` build entry exists, even before all modules are filled in.

- [ ] **Step 5: Commit**

```bash
git add foundations CMakeLists.txt
git commit -m "feat: add foundations index and registration"
```

## Task 5: Implement Module 01 Skeleton and Tests

**Files:**
- Create: `foundations/module-01-tooling-and-first-program/README.md`
- Create: `foundations/module-01-tooling-and-first-program/lesson.md`
- Create: `foundations/module-01-tooling-and-first-program/CMakeLists.txt`
- Create: `foundations/module-01-tooling-and-first-program/drills/README.md`
- Create: `foundations/module-01-tooling-and-first-program/drills/hello_cli.cpp`
- Create: `foundations/module-01-tooling-and-first-program/assignment/README.md`
- Create: `foundations/module-01-tooling-and-first-program/assignment/main.cpp`
- Create: `foundations/module-01-tooling-and-first-program/tests/CMakeLists.txt`
- Create: `foundations/module-01-tooling-and-first-program/tests/test_hello_cli.cpp`
- Create: `foundations/module-01-tooling-and-first-program/expert/README.md`
- Modify: `foundations/CMakeLists.txt`
- Test: `foundations/module-01-tooling-and-first-program/tests/test_hello_cli.cpp`

- [ ] **Step 1: Write the failing test**

```cpp
TEST_CASE("hello cli prints a greeting") {
    CHECK(run_program("./module_01_assignment") == "hello modern cpp\n");
}
```

- [ ] **Step 2: Run test to verify it fails**

Run: `ctest --test-dir build -R module_01 -V`
Expected: FAIL because the target and module files do not exist yet.

- [ ] **Step 3: Write the minimal implementation**

Create the module layout, add a small greeting drill, and implement `assignment/main.cpp`:

```cpp
int main() {
    std::cout << "hello modern cpp\n";
}
```

- [ ] **Step 4: Run build and tests**

Run: `cmake --build build`
Expected: PASS

Run: `ctest --test-dir build -R module_01 -V`
Expected: PASS

- [ ] **Step 5: Commit**

```bash
git add foundations/module-01-tooling-and-first-program foundations/CMakeLists.txt
git commit -m "feat: add module 01 tooling and first program"
```

## Task 6: Implement Module 02 Strings, Streams, and Collections

**Files:**
- Create: `foundations/module-02-strings-streams-and-collections/README.md`
- Create: `foundations/module-02-strings-streams-and-collections/lesson.md`
- Create: `foundations/module-02-strings-streams-and-collections/CMakeLists.txt`
- Create: `foundations/module-02-strings-streams-and-collections/drills/README.md`
- Create: `foundations/module-02-strings-streams-and-collections/drills/word_count.cpp`
- Create: `foundations/module-02-strings-streams-and-collections/assignment/README.md`
- Create: `foundations/module-02-strings-streams-and-collections/assignment/text_stats.cpp`
- Create: `foundations/module-02-strings-streams-and-collections/tests/CMakeLists.txt`
- Create: `foundations/module-02-strings-streams-and-collections/tests/test_text_stats.cpp`
- Create: `foundations/module-02-strings-streams-and-collections/expert/README.md`
- Modify: `foundations/CMakeLists.txt`
- Test: `foundations/module-02-strings-streams-and-collections/tests/test_text_stats.cpp`

- [ ] **Step 1: Write the failing test**

```cpp
TEST_CASE("text stats counts lines, words, and bytes") {
    const auto stats = analyze_text("hello cpp\nfrom stanford\n");
    CHECK(stats.lines == 2);
    CHECK(stats.words == 4);
    CHECK(stats.bytes == 24);
}
```

- [ ] **Step 2: Run test to verify it fails**

Run: `ctest --test-dir build -R module_02 -V`
Expected: FAIL because `analyze_text` is not implemented.

- [ ] **Step 3: Write the minimal implementation**

Implement `text_stats.cpp` with a small `TextStats` struct and parsing logic using `std::string`, streams, and standard containers.

- [ ] **Step 4: Run build and tests**

Run: `cmake --build build`
Expected: PASS

Run: `ctest --test-dir build -R module_02 -V`
Expected: PASS

- [ ] **Step 5: Commit**

```bash
git add foundations/module-02-strings-streams-and-collections foundations/CMakeLists.txt
git commit -m "feat: add module 02 strings streams and collections"
```

## Task 7: Implement Module 03 Classes and Const Correctness

**Files:**
- Create: `foundations/module-03-classes-and-const-correctness/README.md`
- Create: `foundations/module-03-classes-and-const-correctness/lesson.md`
- Create: `foundations/module-03-classes-and-const-correctness/CMakeLists.txt`
- Create: `foundations/module-03-classes-and-const-correctness/drills/README.md`
- Create: `foundations/module-03-classes-and-const-correctness/drills/counter.h`
- Create: `foundations/module-03-classes-and-const-correctness/drills/counter.cpp`
- Create: `foundations/module-03-classes-and-const-correctness/assignment/README.md`
- Create: `foundations/module-03-classes-and-const-correctness/assignment/library.h`
- Create: `foundations/module-03-classes-and-const-correctness/assignment/library.cpp`
- Create: `foundations/module-03-classes-and-const-correctness/tests/CMakeLists.txt`
- Create: `foundations/module-03-classes-and-const-correctness/tests/test_library.cpp`
- Create: `foundations/module-03-classes-and-const-correctness/expert/README.md`
- Modify: `foundations/CMakeLists.txt`
- Test: `foundations/module-03-classes-and-const-correctness/tests/test_library.cpp`

- [ ] **Step 1: Write the failing test**

```cpp
TEST_CASE("library search is const and does not mutate catalog") {
    const Library library = make_sample_library();
    const auto result = library.find_by_title("Effective Modern C++");
    CHECK(result.has_value());
    CHECK(library.size() == 3);
}
```

- [ ] **Step 2: Run test to verify it fails**

Run: `ctest --test-dir build -R module_03 -V`
Expected: FAIL because `Library` and the test target do not exist yet.

- [ ] **Step 3: Write the minimal implementation**

Implement a small `Library` class with:
- a private collection of books
- const-correct accessors
- a read-only search function

- [ ] **Step 4: Run build and tests**

Run: `cmake --build build`
Expected: PASS

Run: `ctest --test-dir build -R module_03 -V`
Expected: PASS

- [ ] **Step 5: Commit**

```bash
git add foundations/module-03-classes-and-const-correctness foundations/CMakeLists.txt
git commit -m "feat: add module 03 classes and const correctness"
```

## Task 8: Implement Module 04 Templates and STL

**Files:**
- Create: `foundations/module-04-templates-and-stl/README.md`
- Create: `foundations/module-04-templates-and-stl/lesson.md`
- Create: `foundations/module-04-templates-and-stl/CMakeLists.txt`
- Create: `foundations/module-04-templates-and-stl/drills/README.md`
- Create: `foundations/module-04-templates-and-stl/drills/range_utils.h`
- Create: `foundations/module-04-templates-and-stl/assignment/README.md`
- Create: `foundations/module-04-templates-and-stl/assignment/query_engine.h`
- Create: `foundations/module-04-templates-and-stl/assignment/query_engine.cpp`
- Create: `foundations/module-04-templates-and-stl/tests/CMakeLists.txt`
- Create: `foundations/module-04-templates-and-stl/tests/test_query_engine.cpp`
- Create: `foundations/module-04-templates-and-stl/expert/README.md`
- Modify: `foundations/CMakeLists.txt`
- Test: `foundations/module-04-templates-and-stl/tests/test_query_engine.cpp`

- [ ] **Step 1: Write the failing test**

```cpp
TEST_CASE("query engine filters values using generic predicates") {
    const std::vector<int> values{1, 2, 3, 4, 5};
    const auto evens = filter_values(values, [](int value) { return value % 2 == 0; });
    CHECK(evens == std::vector<int>{2, 4});
}
```

- [ ] **Step 2: Run test to verify it fails**

Run: `ctest --test-dir build -R module_04 -V`
Expected: FAIL because the template utilities are not implemented.

- [ ] **Step 3: Write the minimal implementation**

Implement generic filtering and querying utilities that use templates, iterators, and standard algorithms without unnecessary abstraction.

- [ ] **Step 4: Run build and tests**

Run: `cmake --build build`
Expected: PASS

Run: `ctest --test-dir build -R module_04 -V`
Expected: PASS

- [ ] **Step 5: Commit**

```bash
git add foundations/module-04-templates-and-stl foundations/CMakeLists.txt
git commit -m "feat: add module 04 templates and stl"
```

## Task 9: Add Synthesis Project 01 Mini Search Engine

**Files:**
- Create: `projects/README.md`
- Create: `projects/project-01-mini-search-engine/README.md`
- Create: `projects/project-01-mini-search-engine/CMakeLists.txt`
- Create: `projects/project-01-mini-search-engine/src/main.cpp`
- Create: `projects/project-01-mini-search-engine/src/index.h`
- Create: `projects/project-01-mini-search-engine/src/index.cpp`
- Create: `projects/project-01-mini-search-engine/data/sample_corpus.txt`
- Create: `projects/project-01-mini-search-engine/tests/CMakeLists.txt`
- Create: `projects/project-01-mini-search-engine/tests/test_index.cpp`
- Modify: `CMakeLists.txt`
- Test: `projects/project-01-mini-search-engine/tests/test_index.cpp`

- [ ] **Step 1: Write the failing test**

```cpp
TEST_CASE("search index returns ranked matches for query tokens") {
    SearchIndex index;
    index.add_document("doc1", "modern cpp move semantics");
    index.add_document("doc2", "cpp streams and strings");

    const auto results = index.search("cpp move");
    CHECK(results.front().document_id == "doc1");
}
```

- [ ] **Step 2: Run test to verify it fails**

Run: `ctest --test-dir build -R project_01 -V`
Expected: FAIL because the project code and registration do not exist.

- [ ] **Step 3: Write the minimal implementation**

Implement:
- a simple inverted-index style search structure
- one small CLI entry point
- sample corpus data
- project README with build, run, and extension ideas

- [ ] **Step 4: Run build and tests**

Run: `cmake --build build`
Expected: PASS

Run: `ctest --test-dir build -R project_01 -V`
Expected: PASS

- [ ] **Step 5: Commit**

```bash
git add projects CMakeLists.txt
git commit -m "feat: add project 01 mini search engine"
```

## Task 10: Add Expert Extension 01 Move Semantics and Value Categories

**Files:**
- Create: `tracks/expert/README.md`
- Create: `tracks/expert/expert-01-move-semantics-and-value-categories/README.md`
- Create: `tracks/expert/expert-01-move-semantics-and-value-categories/lesson.md`
- Create: `tracks/expert/expert-01-move-semantics-and-value-categories/CMakeLists.txt`
- Create: `tracks/expert/expert-01-move-semantics-and-value-categories/drills/README.md`
- Create: `tracks/expert/expert-01-move-semantics-and-value-categories/drills/traceable.h`
- Create: `tracks/expert/expert-01-move-semantics-and-value-categories/tests/CMakeLists.txt`
- Create: `tracks/expert/expert-01-move-semantics-and-value-categories/tests/test_traceable.cpp`
- Modify: `CMakeLists.txt`
- Test: `tracks/expert/expert-01-move-semantics-and-value-categories/tests/test_traceable.cpp`

- [ ] **Step 1: Write the failing test**

```cpp
TEST_CASE("traceable records copy and move operations") {
    Traceable value{"cpp"};
    auto moved = std::move(value);
    CHECK(moved.move_count() == 1);
}
```

- [ ] **Step 2: Run test to verify it fails**

Run: `ctest --test-dir build -R expert_01 -V`
Expected: FAIL because the expert extension target does not exist yet.

- [ ] **Step 3: Write the minimal implementation**

Create a focused `Traceable` helper type and documentation explaining:
- lvalues vs rvalues
- copy vs move operations
- why `std::move` does not itself move

- [ ] **Step 4: Run build and tests**

Run: `cmake --build build`
Expected: PASS

Run: `ctest --test-dir build -R expert_01 -V`
Expected: PASS

- [ ] **Step 5: Commit**

```bash
git add tracks CMakeLists.txt
git commit -m "feat: add expert module on move semantics"
```

## Task 11: Final Integration and Repo Verification

**Files:**
- Modify: `README.md`
- Modify: `docs/learning-path.md`
- Test: `CMakeLists.txt`

- [ ] **Step 1: Write the final verification checklist**

Add a release checklist section covering:
- configure from clean checkout
- build all targets
- run all tests
- verify root docs link to all shipped modules

- [ ] **Step 2: Run the full repo verification**

Run: `cmake -S . -B build`
Expected: PASS

Run: `cmake --build build`
Expected: PASS

Run: `ctest --test-dir build --output-on-failure`
Expected: PASS

- [ ] **Step 3: Verify learner navigation**

Run: `rg -n "module-01|module-02|module-03|module-04|project-01|expert-01" README.md docs foundations projects tracks`
Expected: PASS with references from root navigation into all shipped content.

- [ ] **Step 4: Tidy and align docs**

Make any small doc corrections found during the verification pass. Do not broaden scope or add new content areas during this step.

- [ ] **Step 5: Commit**

```bash
git add README.md docs foundations projects tracks CMakeLists.txt tooling
git commit -m "chore: verify and finalize v1 learning repo slice"
```

## Execution Notes

- Prefer TDD exactly as written: add or define the test first, confirm failure, implement minimally, then rerun.
- Do not create placeholder modules beyond the four planned foundation modules, one project, and one expert extension in this plan.
- Keep lessons concise; the repo is project-heavy by design.
- Favor small reusable helpers in `tooling/` rather than per-module bespoke scripts.
- Use frequent commits so each task remains independently reviewable and reversible.
