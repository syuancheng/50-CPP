# 核心示例

这些程序只演示一个主要概念，并用 `assert` 验证关键行为。

| 示例 | 主题 |
| --- | --- |
| `ownership.cpp` | RAII、独占所有权、非拥有观察 |
| `value_semantics.cpp` | Rule of Zero、复制与移动 |
| `algorithms.cpp` | 容器、lambda、标准算法 |
| `error_handling.cpp` | 可恢复错误与异常安全 |
| `concurrency.cpp` | mutex、条件变量、线程生命周期 |

从仓库根目录统一构建和测试：

```bash
cmake -S . -B build
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```
