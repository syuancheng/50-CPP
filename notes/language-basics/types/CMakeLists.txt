cmake_minimum_required(VERSION 3.16)
project(datatype_examples LANGUAGES CXX)

foreach(number RANGE 1 5)
    add_executable(datatype_${number} test${number}.cpp)
    target_compile_features(datatype_${number} PRIVATE cxx_std_17)
endforeach()
