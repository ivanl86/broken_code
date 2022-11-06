#ifndef BST_NODE_H
#define BST_NODE_H

template<typename T>
struct BSTNode
{
    T item;
    BSTNode<T>* parent;
    BSTNode<T>* lchild;
    BSTNode<T>* rchild;

    // BSTNode() {}

    BSTNode(const T& item)
        : BSTNode<T>(item, nullptr, nullptr, nullptr) {}

    BSTNode(const T& item, BSTNode<T>* parent)
        : BSTNode<T>(item, parent, nullptr, nullptr) {}

    BSTNode(const T& item, BSTNode<T>* parent, BSTNode<T>* lchild, BSTNode<T>* rchild)
        : item{item}, parent{parent}, lchild{lchild}, rchild{rchild} {}
};

#endif  /* BST_NODE_H */