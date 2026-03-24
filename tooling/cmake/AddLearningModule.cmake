# Shared helper for registering a learning module and its tests.

function(add_learning_module module_name)
    set(module_source_dir "${CMAKE_CURRENT_SOURCE_DIR}/${module_name}")

    if(NOT IS_DIRECTORY "${module_source_dir}")
        message(FATAL_ERROR "Module directory not found: ${module_source_dir}")
    endif()

    add_subdirectory("${module_source_dir}" "${module_name}")

    if(BUILD_TESTING AND EXISTS "${module_source_dir}/tests/CMakeLists.txt")
        add_subdirectory("${module_source_dir}/tests" "${module_name}/tests")
    endif()
endfunction()
