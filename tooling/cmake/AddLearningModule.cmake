# Shared helper for registering a learning module and its tests.

function(add_learning_module module_name)
    add_subdirectory(${module_name})

    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${module_name}/tests/CMakeLists.txt")
        add_subdirectory(${module_name}/tests)
    endif()
endfunction()
