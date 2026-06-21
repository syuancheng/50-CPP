# CMake 示例

示例按构建关系递进：

- `basic/01-hello-cmake`：单可执行文件；
- `basic/02-hello-headers`：源文件与公开头文件目录；
- `basic/03-static-library`：静态库；
- `basic/04-shared-library`：动态库与别名 target；
- `basic/05-build-type`：单配置生成器的构建类型；
- `basic/06-third-party-library`：查找 Boost（需要额外依赖）；
- `sub-projects/01-basic`：多个子目录和 target 依赖传播。

现代 CMake 的基本单位是 target。编译特性、头文件目录、宏和链接库都应附着在 target 上，并用 `PRIVATE`、`PUBLIC`、`INTERFACE` 表达传播关系。
