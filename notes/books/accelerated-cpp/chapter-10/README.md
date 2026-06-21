# Chapter 10：对象生命周期与内存管理

## 三种存储期

- 自动存储期：普通局部对象在进入作用域时构造，离开作用域时销毁。
- 静态存储期：命名空间作用域对象和局部 `static` 对象持续到程序结束。
- 动态存储期：对象由分配操作创建，生命周期必须由所有者管理。

存储位置不是核心问题，生命周期与所有权才是。返回局部对象的指针会产生悬空指针：

```cpp
const int* invalid_pointer() {
    int value = 42;
    return &value; // value 在函数返回时销毁
}
```

## RAII 优先

直接 `new` 得到的对象必须在每一条控制路径上恰好 `delete` 一次。异常、提前返回和复制都会让这条规则难以维持，因此业务代码优先使用：

- `std::vector<T>` 代替动态数组；
- `std::string` 代替拥有字符数组；
- `std::unique_ptr<T>` 表达独占所有权；
- `std::shared_ptr<T>` 只用于确实共享的生命周期。

```cpp
auto value = std::make_unique<int>(42);
std::vector<int> values(10);
```

它们的析构函数自动释放资源，使正常返回和异常路径遵循同一规则。`main.cpp` 给出了可运行示例。

```bash
cmake -S notes/books/accelerated-cpp/chapter-10 -B build/chapter-10
cmake --build build/chapter-10
./build/chapter-10/ch10
```
