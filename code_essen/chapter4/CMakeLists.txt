cmake_minimum_required(VERSION 3.21.1)

# Set the project name
project (chapter4)

# Add an executable
add_executable(${PROJECT_NAME} main.cpp
        triangular.h
        less_than.h)