# Expert

The useful habit here is to make the customization point obvious in the API.

If a caller should decide what counts as a match or how values should be ranked, accept that decision as a callable instead of hard-coding it into the algorithm body. That keeps the loop small, makes tests easier to read, and leaves the behavior open for reuse.
