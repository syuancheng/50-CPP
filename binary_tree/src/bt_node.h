#ifndef SYUAN_BT_NODE_H
#define SYUAN_BT_NODE_H


template <typename valType>
class BTnode
{
public:
    //friend class BinaryTree<valType>;
    BTnode(/* args */);
    BTnode(const valType &val);
    ~BTnode();

    void insert_value(const valType &val);

private:
    valType _val;
    int _cnt;
    BTnode *_lchild;
    BTnode *_rchild;
};

template <typename valType>
inline BTnode<valType>::BTnode(const valType &val):_val(val)
{
    _cnt = 1;
    _lchild = _rchild = 0;
}

template <typename valType>
inline void BTnode<valType>::insert_value(const valType &val)
{
    if (val == _val)
    {
        _cnt++;
        return;
    }
    if (val < _val)
    {
        if (!_lchild)
        {
            _lchild = new BTnode(val);
        } else {
            _lchild->insert_value(val);
        }
        
    } else {
        if (!_rchild)
        {
            _rchild = new BTnode(val);
        } else {
            _rchild->insert_value(val);
        }
    }
    
}

#endif // SYUAN_BT_NODE_H