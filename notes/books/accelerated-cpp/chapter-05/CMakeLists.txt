cmake_minimum_required(VERSION 3.16)

project(ch5 LANGUAGES CXX)

include(CTest)

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

add_executable(ch5_str_proc_test str_proc_test.cpp)

# link the new hello_library target with the hello_binary target
target_link_libraries( ch5_binary
    PRIVATE 
        ch5_library
)
target_link_libraries(ch5_str_proc_test PRIVATE ch5_library)
target_compile_features(ch5_library PUBLIC cxx_std_17)

if(BUILD_TESTING)
    add_test(NAME split_words COMMAND ch5_str_proc_test)
endif()
