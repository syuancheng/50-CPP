#include <cassert>
#include <memory>
#include <string>
#include <utility>
#include <vector>

class Resource {
public:
    explicit Resource(std::string name) : name_(std::move(name)) {}
    const std::string& name() const noexcept { return name_; }

private:
    std::string name_;
};

int main() {
    int automatic = 42;             // 作用域结束时自动销毁
    static int persistent = 7;      // 程序结束时销毁
    auto dynamic = std::make_unique<Resource>("owned");
    std::vector<int> values{1, 2, 3};

    assert(automatic == 42);
    assert(persistent == 7);
    assert(dynamic->name() == "owned");
    assert(values.size() == 3);
}
