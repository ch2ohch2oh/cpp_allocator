cmake_minimum_required(VERSION 3.5.0)
project(allocator VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20) 

add_executable(mono_buf mono_buf.cpp)
add_executable(mono_buf2 mono_buf2.cpp)
add_executable(pool_resource pool_resource.cpp)
add_executable(alloc_aware alloc_aware.cpp)
