cmake_minimum_required(VERSION 3.16)

project(ch9 LANGUAGES CXX)

#Generate the static library from the library sources
add_library(ch9_library STATIC 
    src/student_info.cpp
)

target_include_directories(ch9_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/src
)

add_executable(ch9
    main.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries( ch9
    PRIVATE 
        ch9_library
)
target_compile_features(ch9_library PUBLIC cxx_std_17)
