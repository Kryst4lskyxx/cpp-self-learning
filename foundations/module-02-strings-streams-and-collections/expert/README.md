# Expert Note

The useful mental model here is that strings are the data, streams are the parser, and containers are the scratch space when one pass is not enough.

For this module, prefer the standard library over custom tokenization helpers. A few lines with `std::getline`, `std::istringstream`, and `std::vector` should be enough to keep the logic readable.
