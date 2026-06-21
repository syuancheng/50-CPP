cmake_minimum_required(VERSION 3.16)

project(ch14 LANGUAGES CXX)

#Generate the static library from the library sources
add_library(ch14_library STATIC 
    src/student_info.cpp
    src/core.cpp
    src/grad.cpp
)

target_include_directories(ch14_library
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/src
)

add_executable(ch14
    main.cpp
)

# link the new hello_library target with the hello_binary target
target_link_libraries( ch14
    PRIVATE 
        ch14_library
)
target_compile_features(ch14_library PUBLIC cxx_std_17)
