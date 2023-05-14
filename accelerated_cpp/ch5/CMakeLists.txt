cmake_minimum_required(VERSION 3.5)

project(ch5)

#Generate the static library from the library sources
add_library(ch5_library STATIC 
    include/grade.cpp
    include/median.cpp
    include/student_info.cpp
    include/str_proc.cpp
)

target_include_directories(ch5_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

add_executable(ch5_binary 
    test1.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries( ch5_binary
    PRIVATE 
        ch5_library
)
