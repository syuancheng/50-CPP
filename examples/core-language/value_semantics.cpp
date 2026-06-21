#include <cassert>
#include <string>
#include <utility>
#include <vector>

class Notebook {
public:
    void add(std::string note) { notes_.push_back(std::move(note)); }
    const std::string& at(std::size_t index) const { return notes_.at(index); }
    std::size_t size() const noexcept { return notes_.size(); }

private:
    // vector 和 string 已正确实现资源管理，Notebook 不需要自定义特殊成员。
    std::vector<std::string> notes_;
};

int main() {
    Notebook original;
    original.add("lifetime");

    Notebook copy = original;
    copy.add("RAII");
    assert(original.size() == 1);
    assert(copy.size() == 2);

    Notebook moved = std::move(copy);
    assert(moved.at(1) == "RAII");
}
