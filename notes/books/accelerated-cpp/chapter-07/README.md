# Chapter 7：关联容器

`std::map` / `std::set` 按键有序，典型操作是 `O(log n)`；`std::unordered_map` / `std::unordered_set` 基于哈希，平均查找是 `O(1)`，但不维护顺序。

选择容器先看不变量：是否需要顺序、键是否唯一、是否需要稳定迭代、最常见操作是什么。不要只凭“哈希更快”选择容器。

使用 `find` 做只读查询；`map[key]` 在键不存在时会插入默认值。
