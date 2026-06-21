cmake_minimum_required(VERSION 3.16)
project(polymorphism_examples LANGUAGES CXX)

function(add_polymorphism_example target source)
    add_executable(${target} "${source}")
    target_compile_features(${target} PRIVATE cxx_std_17)
endfunction()

add_polymorphism_example(abstract_class "抽象类.cpp")
add_polymorphism_example(virtual_destructor "虚析构函数.cpp")
add_polymorphism_example(virtual_function "虚函数例子.cpp")
add_polymorphism_example(virtual_properties "虚函数特性.cpp")
add_polymorphism_example(inherited_virtual "从基类继承的成员将访问到派生类版本.cpp")
add_polymorphism_example(payroll "编程实例.cpp")
