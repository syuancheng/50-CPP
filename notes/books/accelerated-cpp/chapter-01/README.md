# Chapter 1：字符与字符串

## `char`

`char` 是表示字符编码单元的内置整数类型。字符字面量使用单引号，例如 `'A'`。

## `std::string`

```cpp
std::string empty;           // 空字符串
std::string copy = source;   // 独立副本
std::string repeated(5, '*');
```

`std::string` 管理自己的存储，复制后两个对象可以独立修改。字符串字面量不可修改；若需要观察它，使用 `const char*` 或 `std::string_view`。
