# CMake 基础

最小项目：

```cmake
cmake_minimum_required(VERSION 3.16)
project(hello LANGUAGES CXX)

add_executable(hello main.cpp)
target_compile_features(hello PRIVATE cxx_std_17)
```

库应通过 target 暴露使用要求：

```cmake
add_library(greeting STATIC src/greeting.cpp)
target_include_directories(greeting PUBLIC include)
target_link_libraries(app PRIVATE greeting)
```

- `PRIVATE`：只影响当前 target；
- `INTERFACE`：只传播给使用者；
- `PUBLIC`：同时影响当前 target 和使用者。

构建时将生成物放在源码树之外：

```bash
cmake -S examples/build-system/cmake/basic/01-hello-cmake -B build/cmake-a
cmake --build build/cmake-a --parallel
./build/cmake-a/hello_cmake
```

不要依赖全局 `include_directories` 或全局编译选项；target 级配置更容易组合和复用。
