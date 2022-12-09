#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

template<typename T>
struct BinaryTreeNode
{
    T item;
    BinaryTreeNode<T> *parent;
    BinaryTreeNode<T>* lchild;
    BinaryTreeNode<T>* rchild;
};

#endif  /* BINARY_TREE_NODE_H */