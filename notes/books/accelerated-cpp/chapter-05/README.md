# Chapter 5：容器操作

本章将成绩程序拆成多个源文件，并练习 `vector` 的遍历、分组和删除。

关键规则：

- 删除元素会移动其后的元素，相关迭代器可能失效；
- 在循环中调用 `erase` 时，应使用它返回的下一个有效迭代器；
- 查找、分区和复制优先考虑 `<algorithm>`；
- 头文件声明接口，`.cpp` 提供非模板定义。

```bash
cmake -S notes/books/accelerated-cpp/chapter-05 -B build/chapter-05
cmake --build build/chapter-05
```
