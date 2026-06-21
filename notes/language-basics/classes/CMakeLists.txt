cmake_minimum_required(VERSION 3.16)
project(class_examples LANGUAGES CXX)

add_executable(sales_item Sales_item.cpp)
add_executable(sales_data Sales_data.cpp)
target_compile_features(sales_item PRIVATE cxx_std_17)
target_compile_features(sales_data PRIVATE cxx_std_17)
