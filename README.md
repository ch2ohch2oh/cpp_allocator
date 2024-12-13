

- [CppCon 2015: Andrei Alexandrescu “std::allocator...”][1] talks about 
the histroy of allocator and how to build allocators via composition.
- [CppCon 2017: Bob Steagall “How to Write a Custom Allocator”][2] covers 
the interface/implementation of allocators in cpp03. Be ready for tons of types
and traits 😱
- [CppCon 2017: Pablo Halpern “Allocators: The Good Parts”][3] talks about 
the allocator interface and how to write a custom allocator.

Jason Turner has a short video series on allocators:
- [C++ Weekly - Ep 222 - 3.5x Faster Standard Containers With PMR!][4] shows
pmr containers are faster due to fewer memory allocation calls.
- [C++ Weekly - Ep 235 - PMR: Amazing, Fast, But, Not Quite Magic][5] explains
the inner workings of `monotonic_buffer_resource`.
- [C++ Weekly - Ep 236 - Creating Allocator-Aware Types][6] gives an example
of user defined allocator aware type. You want to make sure the allocator 
is "forwarded" for all the subcomponents of the objects.
- [C++ Weekly - Ep 245 - PMR: Mistakes Were Made (By Me)][7] shows that 
initializer list "does not" work with allocator well. Objects using different 
allocators must be copied rather than moved.

[1]: https://www.youtube.com/watch?v=LIb3L4vKZ7U
[2]: https://www.youtube.com/watch?v=kSWfushlvB8
[3]: https://www.youtube.com/watch?v=v3dz-AKOVL8
[4]: https://www.youtube.com/watch?v=q6A7cKFXjY0
[5]: https://www.youtube.com/watch?v=vXJ1dwJ9QkI
[6]: https://www.youtube.com/watch?v=2LAsqp7UrNs
[7]: https://www.youtube.com/watch?v=6BLlIj2QoT8
