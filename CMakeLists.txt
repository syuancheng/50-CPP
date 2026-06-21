cmake_minimum_required(VERSION 3.16)
project(cpp_notes LANGUAGES CXX)

option(CPP_NOTES_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)

include(CTest)

function(cpp_notes_target target)
    target_compile_features(${target} PRIVATE cxx_std_17)
    if(MSVC)
        target_compile_options(${target} PRIVATE /W4)
        if(CPP_NOTES_WARNINGS_AS_ERRORS)
            target_compile_options(${target} PRIVATE /WX)
        endif()
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
        if(CPP_NOTES_WARNINGS_AS_ERRORS)
            target_compile_options(${target} PRIVATE -Werror)
        endif()
    endif()
endfunction()

add_subdirectory(examples/core-language)
add_subdirectory(examples/data-structures/binary-search-tree)
