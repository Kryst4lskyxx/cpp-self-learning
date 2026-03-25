# Expert

The useful shift in this module is from "generic" to "explicitly generic."

Templates are strongest when they make their assumptions visible in the signature:

- what range element type is being inspected
- what the selector is allowed to accept
- what concrete type is produced from the selector result

That clarity helps both the compiler and the caller. It also keeps the API from drifting into a vague "anything that kind of works" shape, which is where template code tends to become hard to reason about.

