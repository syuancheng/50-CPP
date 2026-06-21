#ifndef SYUAN_BT_TREE_H
#define SYUAN_BT_TREE_H

#include "bt_node.h"

#include <cstddef>
#include <memory>
#include <utility>
#include <vector>

template <typename T>
class BinaryTree {
public:
    BinaryTree() = default;

    BinaryTree(const BinaryTree& other) : root_(clone(other.root_)) {}
    BinaryTree(BinaryTree&&) noexcept = default;

    BinaryTree& operator=(BinaryTree other) noexcept {
        swap(other);
        return *this;
    }

    void insert(const T& value) {
        if (root_) {
            root_->insert_value(value);
        } else {
            root_ = std::make_unique<BTnode<T>>(value);
        }
    }

    bool contains(const T& value) const noexcept {
        const BTnode<T>* current = root_.get();
        while (current) {
            if (value == current->value_) {
                return true;
            }
            current = value < current->value_
                          ? current->left_.get()
                          : current->right_.get();
        }
        return false;
    }

    std::size_t count(const T& value) const noexcept {
        const BTnode<T>* current = root_.get();
        while (current) {
            if (value == current->value_) {
                return current->count_;
            }
            current = value < current->value_
                          ? current->left_.get()
                          : current->right_.get();
        }
        return 0;
    }

    std::vector<std::pair<T, std::size_t>> inorder() const {
        std::vector<std::pair<T, std::size_t>> result;
        append_inorder(root_.get(), result);
        return result;
    }

    bool empty() const noexcept { return !root_; }
    void clear() noexcept { root_.reset(); }
    void swap(BinaryTree& other) noexcept { root_.swap(other.root_); }

private:
    static std::unique_ptr<BTnode<T>> clone(
        const std::unique_ptr<BTnode<T>>& source) {
        if (!source) {
            return nullptr;
        }

        auto result = std::make_unique<BTnode<T>>(source->value_);
        result->count_ = source->count_;
        result->left_ = clone(source->left_);
        result->right_ = clone(source->right_);
        return result;
    }

    static void append_inorder(
        const BTnode<T>* node,
        std::vector<std::pair<T, std::size_t>>& output) {
        if (!node) {
            return;
        }
        append_inorder(node->left_.get(), output);
        output.emplace_back(node->value_, node->count_);
        append_inorder(node->right_.get(), output);
    }

    std::unique_ptr<BTnode<T>> root_;
};

#endif
