# 50-CPP

一个以“能解释、能编译、能验证”为目标的 C++ 学习仓库。默认语言标准为 C++17；新增内容优先采用 RAII、值语义和标准库，而不是手工管理资源。

## 从哪里开始

1. 阅读[必会知识清单](docs/must-know.md)，建立语言的整体模型。
2. 按[学习路线](docs/learning-path.md)逐项练习。
3. 运行 [`examples/`](examples/README.md) 中的小型、可验证示例。
4. 再阅读教材章节笔记，并对照源码理解细节。

## 目录结构

```text
50-CPP/
├── docs/                 # 按知识体系组织的主线笔记
├── notes/
│   ├── language-basics/  # 按主题组织的语言实验
│   └── books/            # 按教材组织的章节练习
├── examples/
│   ├── core-language/    # 独立、可运行的现代 C++ 示例
│   ├── data-structures/  # 数据结构综合示例
│   └── build-system/     # CMake 与工程组织示例
├── assets/images/        # 文档图片
├── playground/           # 临时实验，不进入默认构建
└── scripts/              # 仓库验证脚本
```

教材章节统一使用 `chapter-NN`，主题目录统一使用小写 kebab-case。主线知识放在 `docs/`，可运行示例放在 `examples/`。

## 构建与验证

要求：支持 C++17 的编译器和 CMake 3.16 或更高版本。

```bash
cmake -S . -B build
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

验证所有不依赖第三方库的教材与主题示例：

```bash
bash scripts/verify.sh
```

严格检查建议：

```bash
cmake -S . -B build -DCPP_NOTES_WARNINGS_AS_ERRORS=ON
cmake --build build --parallel
```

第三方库示例（如 Prometheus、Boost）不进入默认构建，因为它们依赖本机额外安装的软件包。

## 记录原则

- 先写对象的生命周期、所有权和不变量，再写语法。
- 示例必须能独立编译；反例放在注释或文档中，不破坏默认构建。
- 优先使用 `std::vector`、`std::string`、智能指针和算法。
- 除非实现所有权类型，否则避免直接使用 `new` / `delete`。
- 将编译器警告视为待解释的问题，不把“恰好能运行”当作正确。
