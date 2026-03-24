# Expert

Templates in C++ are compile-time code generation, not runtime polymorphism.

Once you internalize that, the STL becomes easier to read: algorithms like `std::copy_if` describe *what* to do, while iterators describe *where* to do it. The useful habit is to push the loop into the standard library and keep your own code focused on the predicate or transformation.
