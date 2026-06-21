cmake_minimum_required(VERSION 3.16)
project(third_party_include LANGUAGES CXX)

find_package(Boost REQUIRED COMPONENTS filesystem)

add_executable(third_party_include main.cpp)
target_compile_features(third_party_include PRIVATE cxx_std_17)
target_link_libraries(third_party_include PRIVATE Boost::filesystem)
