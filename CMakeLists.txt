# Expected commands after this task:
# cmake -S . -B build
# cmake --build build
# ctest --test-dir build

cmake_minimum_required(VERSION 3.20)
project(cpp_self_learning LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

list(PREPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/tooling/cmake")

include(cmake/Warnings.cmake)
include(cmake/Testing.cmake)
add_subdirectory(foundations)
add_subdirectory(projects/project-01-mini-search-engine)
if(BUILD_TESTING)
    add_subdirectory(tooling/tests)
    add_subdirectory(projects/project-01-mini-search-engine/tests)
endif()
