cmake_minimum_required(VERSION 3.16)
project(ch10 LANGUAGES CXX)

add_executable(ch10 main.cpp)
target_compile_features(ch10 PRIVATE cxx_std_17)
