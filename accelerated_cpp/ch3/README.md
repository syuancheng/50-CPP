### ch3

typedef type name; 把name定义为type的替代名
eg:
```c++
typedef vector<int> list;
```
vector<T>::size_type 一种类型，确保了能够保存可能存在的最大向量中的所有元素。
v.begin() v的第一个元素
v.end() v的最后一个元素之后的位置。
vector<T> v; 创建了一个空的向量，可以保存T类型的数据。
