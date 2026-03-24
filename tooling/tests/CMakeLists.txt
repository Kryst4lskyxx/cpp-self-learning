# Keep TEST_CASE translation units in executable or object targets so their
# registration code is linked in; static archives can drop them entirely.
add_library(learning_test_support assertions.cpp)
target_include_directories(learning_test_support PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(learning_test_main test_main.cpp)
target_link_libraries(learning_test_main PUBLIC learning_test_support)
