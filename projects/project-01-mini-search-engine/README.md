# Project 01: Mini Search Engine

A compact inverted-index search engine built as a small library, a command-line interface, and a test suite.

Documents and queries are tokenized the same way: punctuation splits tokens, and letters are matched case-insensitively. Repeated query terms do not increase score.

Results are ranked by the number of matched query tokens in each document, then by document id to keep ties deterministic.

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Run

The CLI expects a corpus file where each line contains a document id, a tab, and the document text:

```bash
./build/projects/project-01-mini-search-engine/mini_search_engine \
  projects/project-01-mini-search-engine/data/sample_corpus.txt \
  "cpp move"
```

## Extend It

- Add phrase queries or field weights.
- Persist the index to disk.
- Add stemming or stop-word filtering.
