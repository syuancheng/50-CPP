# Chapter 3：`vector` 与迭代器

- `std::vector<T> values;` 创建可动态增长的连续容器。
- `values.size()` 返回无符号的 `size_type`。
- `begin()` 指向第一个元素；`end()` 指向末元素之后，不可解引用。
- 空容器满足 `begin() == end()`。
- `push_back` 可能重新分配存储，使已有指针、引用和迭代器失效。

现代代码可用 `auto`、范围 `for` 和标准算法，减少冗长的嵌套类型名。`using size_type = std::vector<T>::size_type;` 是 `typedef` 的更直观写法。
