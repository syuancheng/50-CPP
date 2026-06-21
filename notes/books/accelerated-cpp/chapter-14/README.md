# Chapter 14：RAII Handle 与模板

`Handle<T>` 把“拥有一个多态对象”的规则封装成值类型：

- 内部 `std::unique_ptr<T>` 表达独占所有权；
- 复制时调用虚 `clone()`，得到独立对象；
- 移动时直接转移所有权；
- 空 Handle 被解引用时抛出 `std::runtime_error`；
- 析构由 `unique_ptr` 自动完成。

## 为什么实现位于头文件

模板只有在使用点才知道具体的 `T`。编译器实例化 `Handle<Core>` 时必须看到成员函数完整定义，因此模板实现放在 `handle.h`。把实现只放进普通 `.cpp` 会导致使用点无法生成代码，最终出现链接阶段的 “undefined symbol”。

复制赋值采用 copy-and-swap：先复制参数，复制成功后再交换状态，从而自然处理自赋值并提供强异常保证。

```bash
cmake -S notes/books/accelerated-cpp/chapter-14 -B build/chapter-14
cmake --build build/chapter-14
```
