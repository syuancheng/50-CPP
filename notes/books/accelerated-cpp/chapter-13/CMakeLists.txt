cmake_minimum_required(VERSION 3.16)

project(ch13 LANGUAGES CXX)

#Generate the static library from the library sources
add_library(ch13_library STATIC 
    src/student_info.cpp
    src/core.cpp
    src/grad.cpp
)

target_include_directories(ch13_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/src
)

add_executable(ch13
    main.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries( ch13
    PRIVATE 
        ch13_library
)
target_compile_features(ch13_library PUBLIC cxx_std_17)
