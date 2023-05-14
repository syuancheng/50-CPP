#ifndef SYUAN_BT_TREE_H
#define SYUAN_BT_TREE_H

#include "bt_node.h"

template <typename elemType>
class BinaryTree
{
public:
    BinaryTree(/* args */);
    BinaryTree(const BinaryTree&);
    ~BinaryTree();
    BinaryTree& operator=(const BinaryTree&);

    void insert(const elemType &elem);


    bool empty() {return _root == 0;}
    void clear();
private:
    BTnode<elemType> *_root;

    void copy(BTnode<elemType>* tar, BTnode<elemType>* src);
};

#endif // SYUAN_BT_TREE_H

template <typename elemType>
inline void BinaryTree<elemType>::insert(const elemType &elem)
{
    if (!_root)
    {
        _root = new BTnode<elemType>(elem);
    } else {
        _root
    }
    
}

template <typename elemType>
inline void BinaryTree<elemType>::copy(BTnode<elemType> *tar, BTnode<elemType> *src)
{
}
