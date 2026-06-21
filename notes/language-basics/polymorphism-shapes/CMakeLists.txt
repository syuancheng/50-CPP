cmake_minimum_required(VERSION 3.16)

project(polymorphism_shapes LANGUAGES CXX)

add_executable(shape demo.cpp)
target_compile_features(shape PRIVATE cxx_std_17)
