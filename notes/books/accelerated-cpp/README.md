# Accelerated C++ 练习

本目录按教材章节保留学习顺序。每章的 `README.md` 记录核心不变量，源码用于验证；没有代码的章节表示笔记尚未展开。

| 章节 | 主题 |
| --- | --- |
| chapter-00–03 | 程序结构、字符串、控制流、容器 |
| chapter-04–05 | 函数接口、学生成绩程序、容器操作 |
| chapter-07–08 | 关联容器与泛型函数 |
| chapter-09–10 | 类、对象生命周期与资源管理 |
| chapter-13–14 | 继承、多态、克隆与值语义包装器 |

带 `CMakeLists.txt` 的章节可独立构建：

```bash
cmake -S notes/books/accelerated-cpp/chapter-14 -B build/chapter-14
cmake --build build/chapter-14
```
