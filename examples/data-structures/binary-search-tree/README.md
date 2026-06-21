# 二叉搜索树示例

这个目录演示模板、递归、值语义与 RAII。节点通过 `std::unique_ptr` 独占子节点，因此树销毁或 `clear()` 时会自动递归释放资源。

支持的操作：

- `insert`：插入值，重复值用计数保存；
- `contains` / `count`：查询值与重复次数；
- `inorder`：中序遍历，结果按键升序排列；
- 复制、移动、赋值与清空。

```bash
cmake -S examples/data-structures/binary-search-tree -B build/binary-tree
cmake --build build/binary-tree
./build/binary-tree/binary_tree_demo
```
