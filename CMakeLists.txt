cmake_minimum_required(VERSION 3.21)
project(50_CPP)

set(CMAKE_CXX_STANDARD 14)

include_directories(50-basic/mixer)
include_directories(50-basic/mixer/value_pass)

add_executable(50_CPP
        50-basic/mixer/value_pass/workflow.cpp
        50-basic/mixer/value_pass/workflow.h)
