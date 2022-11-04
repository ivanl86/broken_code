#include <cstdint>

#include "bst_node.h"

#ifndef BST_H
#define BST_H

// code goes here
template<typename T>
class BinarySearchTree
{
public:
    BinarySearchTree() : root{nullptr}, itemQty{0} {}

    void add(T item) {
        add(item, root, nullptr);
        ++itemQty;
    }

    bool remove(T item) {
        return remove(item, root);
    }

    BSTNode<T>* find(T item) {
        return find (item, root);
    }

    void clear() {
        itemQty = 0;
    }

    bool empty() {
        return itemQty == 0;
    }

    uint64_t size() {
        return itemQty;
    }

    BSTNode<T>* getRoot() {
        return root;
    }

    BSTNode<T>* getMax(BSTNode<T> root) {
        if (root.rchild == nullptr)
            return root;

        getMax(root.rchild);
    }

    BSTNode<T> getMin(BSTNode<T> root) {
        if (root.lchild == nullptr)
            return root;

        getMin(root.lchild);
    }

private:
    BSTNode<T> root;
    uint64_t itemQty;

    void add(T item, BSTNode<T> root, BSTNode<T> parent) {
        if (root = nullptr)
            root  = new BSTNode<T>(item, parent);

        (root.item > item) ?
            add(item, root.lchild, root) : add(item, root.rchild, root);
    }

    bool remove(T item, BSTNode<T> root) {
        BSTNode<T> node;

        if (root == nullptr)
            return false;
        if (root.item == item) {
            node = getMax(root.lchild);
            root.item = node.item;
            delete node;
            --itemQty;
            return true;
        }

        (root.item > item) ?
            remove(item, root.lchild) : remove(item, root.rchild);
    }
};

#endif  /* BST_H */