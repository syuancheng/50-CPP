# Chapter 9：定义类

`class` 与 `struct` 的语言能力相同，默认访问权限不同：`class` 默认 `private`，`struct` 默认 `public`。

## 类的不变量

构造函数完成后，对象应处于可用状态。内置类型成员若未显式初始化，默认初始化可能得到不确定值；本章的成绩字段因此初始化为 `0`。

成员初始化发生在进入构造函数体之前，顺序由成员声明顺序决定，不由初始化列表书写顺序决定。

## `const` 成员函数

不会修改对象可观察状态的成员函数应标记为 `const`。`const` 对象只能调用 `const` 成员函数，这也是接口承诺的一部分。

```bash
cmake -S notes/books/accelerated-cpp/chapter-09 -B build/chapter-09
cmake --build build/chapter-09
```
