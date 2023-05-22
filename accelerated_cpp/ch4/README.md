### ch4

知识点：
- grade()函数的参数不是直接指向参数本身，而是复制原本参数。我们成为call by value。
- `double median(std::vector<double>)` 方法也是call by value， 因为如果是引用的话， 方法内部对vec进行排序， 那将会改变原本的参数值。
- `const vector<double>&` vector常量引用，可以直接访问而不需要复制。
- `std::istream& read_hw(std::istream&, std::vector<double>&)`中， 参数列表和返回参数都是同一个参数， 不会进行复制。
- 重载： 方法名相同， 参数列表（类型和个数）不同。