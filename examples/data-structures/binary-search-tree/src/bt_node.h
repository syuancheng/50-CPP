#ifndef SYUAN_BT_NODE_H
#define SYUAN_BT_NODE_H

#include <cstddef>
#include <memory>

template <typename T>
class BinaryTree;

template <typename T>
class BTnode {
    friend class BinaryTree<T>;

public:
    explicit BTnode(const T& value) : value_(value) {}

    void insert_value(const T& value) {
        if (value == value_) {
            ++count_;
        } else if (value < value_) {
            insert_child(left_, value);
        } else {
            insert_child(right_, value);
        }
    }

private:
    static void insert_child(std::unique_ptr<BTnode>& child, const T& value) {
        if (child) {
            child->insert_value(value);
        } else {
            child = std::make_unique<BTnode>(value);
        }
    }

    T value_;
    std::size_t count_ = 1;
    std::unique_ptr<BTnode> left_;
    std::unique_ptr<BTnode> right_;
};

#endif
