#include "src/bt_tree.h"

#include <cassert>
#include <iostream>

int main() {
    BinaryTree<int> tree;
    for (const int value : {5, 3, 7, 3, 6, 8}) {
        tree.insert(value);
    }

    assert(tree.contains(6));
    assert(!tree.contains(4));
    assert(tree.count(3) == 2);

    BinaryTree<int> copy = tree;
    tree.clear();
    assert(tree.empty());
    assert(copy.contains(8));

    for (const auto& [value, count] : copy.inorder()) {
        std::cout << value << " (count=" << count << ")\n";
    }
}
