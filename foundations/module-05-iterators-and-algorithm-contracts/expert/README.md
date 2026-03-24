# Expert

The important shift here is from "can I call the algorithm?" to "does my input satisfy the contract?"

Iterator ranges are half-open by convention, so `first` points to the first element and `last` points one past the end. That convention makes empty ranges easy to represent and makes size calculations consistent.

Binary-search-style algorithms depend on sorted input. Checking that precondition explicitly keeps the failure mode local and easy to reason about.
