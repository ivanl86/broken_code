#ifndef BST_NODE_H
#define BST_NODE_H

template<typename T>
struct BSTNode
{
    T item;
    BSTNode<T>* parent;
    BSTNode<T>* lchild;
    BSTNode<T>* rchild;

    BSTNode(T item)
        : BSTNode(item, nullptr, nullptr, nullptr) {}

    BSTNode(T item, BSTNode<T> parent)
        : BSTNode(item, parent, nullptr, nullptr) {}

    BSTNode(T item, BSTNode<T> parent, BSTNode<T> lchild, BSTNode<T> rchild)
        : item{item}, parent{parent}, lchild{lchild}, rchild{rchild} {}
};

#endif  /* BST_NODE_H */