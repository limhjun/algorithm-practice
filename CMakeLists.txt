cmake_minimum_required(VERSION 3.20)

set(CMAKE_C_COMPILER "/opt/homebrew/Cellar/llvm/21.1.8/bin/clang")
set(CMAKE_CXX_COMPILER "/opt/homebrew/Cellar/llvm/21.1.8/bin/clang++")

project(algorithm_practice LANGUAGES CXX)

link_directories(/opt/homebrew/Cellar/llvm/21.1.8/lib/c++)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(algorithm_practice main.cpp)

set(SOLUTION_DIRS baekjoon programmers)

function(make_solution_target_name output_var source)
    file(RELATIVE_PATH rel_path "${CMAKE_SOURCE_DIR}" "${source}")
    string(REGEX REPLACE "\\.cpp$" "" target_name "${rel_path}")
    string(REPLACE "/" "_" target_name "${target_name}")
    set(${output_var} "${target_name}" PARENT_SCOPE)
endfunction()

function(add_solution_target source)
    make_solution_target_name(target_name "${source}")

    add_executable("${target_name}" "${source}")
    add_custom_target(
        "run_${target_name}"
        COMMAND "$<TARGET_FILE:${target_name}>"
        DEPENDS "${target_name}"
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        USES_TERMINAL
        COMMENT "Running ${target_name}"
    )
endfunction()

function(add_solution_targets_from_dir dir)
    if(NOT EXISTS "${CMAKE_SOURCE_DIR}/${dir}")
        return()
    endif()

    file(GLOB_RECURSE dir_sources CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/${dir}/*.cpp")
    foreach(source IN LISTS dir_sources)
        add_solution_target("${source}")
    endforeach()
endfunction()

foreach(dir IN LISTS SOLUTION_DIRS)
    add_solution_targets_from_dir("${dir}")
endforeach()
