cmake_minimum_required(VERSION 3.16)

# Set the project name
project (chapter4)

# Add an executable
add_executable(${PROJECT_NAME} main.cpp
        triangular.h
        less_than.h
        matrix.h
        stack.h)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
