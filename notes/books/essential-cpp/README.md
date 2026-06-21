# Essential C++ 练习

当前内容集中在 chapter 4：函数对象、静态成员、迭代器、值语义和小型容器封装。

```bash
cmake -S notes/books/essential-cpp/chapter-04 -B build/essential-cpp-04
cmake --build build/essential-cpp-04
./build/essential-cpp-04/chapter4
```

头文件中的非模板函数使用 `inline`，避免被多个翻译单元包含时违反 ODR。
