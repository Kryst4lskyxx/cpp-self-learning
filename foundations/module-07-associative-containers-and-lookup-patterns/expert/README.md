# Expert

The useful habit here is to separate lookup from ordering.

Use the associative container that makes the expensive part cheap, then impose ordering explicitly when the caller needs a stable result. That keeps the contract readable and avoids hiding ordering assumptions inside the container choice.
