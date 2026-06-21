if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    cmake_minimum_required(VERSION 3.16)
    project(binary_tree_demo LANGUAGES CXX)
endif()

add_executable(binary_tree_demo main.cpp)
target_compile_features(binary_tree_demo PRIVATE cxx_std_17)

if(COMMAND cpp_notes_target)
    cpp_notes_target(binary_tree_demo)
endif()

if(BUILD_TESTING)
    add_test(NAME example_binary_tree COMMAND binary_tree_demo)
endif()
