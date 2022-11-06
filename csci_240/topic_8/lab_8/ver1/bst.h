#include <cstdint>

#include "bst_node.h"

#ifndef BST_H
#define BST_H

enum Extrema {MIN, MAX};

template<typename T>
class BinarySearchTree
{
public:
    BinarySearchTree() : root{nullptr}, itemQty{0} {}

    void add(const T& item) {
        if (root == nullptr)
            root = new BSTNode<T>(item);
        else
            add(item, root, root->parent);

        ++itemQty;
    }

    bool remove(const T& item) {
        if (root->item == item && itemQty == 1) {
            delete root->parent;
            delete root;
            root = nullptr;
            return true;
        }
        return remove(item, root);
    }

    BSTNode<T>* find(const T& item) {
        return find (item, root);
    }

    bool contains(const T& item) {
        return contains(item, root);
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

    BSTNode<T>* getMax(BSTNode<T>* root) {
        if (root == nullptr)
            return root;

        if (root->rchild == nullptr)
            return root;

        getMax(root->rchild);
    }

    BSTNode<T>* getMin(BSTNode<T>* root) {
        if (root == nullptr)
            return root;

        if (root->lchild == nullptr)
            return root;

        getMin(root->lchild);
    }

private:
    BSTNode<T>* root;
    uint64_t itemQty;

    void add(const T& item, BSTNode<T>* root, BSTNode<T>* parent) {
        if (root == nullptr) {
            root = new BSTNode<T>(item, parent);
            (parent->item > item) ? parent->lchild = root : parent->rchild = root;
            return;
        }

        (root->item > item) ?
            add(item, root->lchild, root) : add(item, root->rchild, root);
    }

    bool remove(const T& item, BSTNode<T>* root) {
        BSTNode<T>* node(nullptr);

        if (root == nullptr)
            return false;

        // if (root->item == item) {
        //     if (root->parent == nullptr)
        //         (root->parent->item > root->item) ?
        //             root->parent->lchild = nullptr : root->parent->rchild = nullptr;
        // }

        // if (root->item == item) {
        //     if (root->lchild != nullptr)
        //         node = getMax(root->lchild);
        //     else if (root->rchild != nullptr)
        //         node = getMin(root->rchild);
            
        //     if (node == nullptr) {
        //         delete root;
        //         root = nullptr;
        //         --itemQty;
        //         return true;
        //     }
        //     else {
        //         root->item = node->item;
        //         delete node;
        //         node = nullptr;
        //         --itemQty;
        //         return true;
        //     }
        // }

        (root->item > item) ?
            remove(item, root->lchild) : remove(item, root->rchild);
    }

    bool contains(T item, BSTNode<T>* root) {
        if (root == nullptr)
            return false;

        if (root->item == item)
            return true;

        (root->item > item) ?
            contains(item, root->lchild) : contains(item, root->rchild);
    }

    BSTNode<T>* getExtremaParent(BSTNode<T>* root, Extrema extrema) {
        if (extrema = MIN)
            if (root->lchild == nullptr)
                return root->parent;
        else
            if (root->rchild == nullptr)
                return root->parent;

        (extrema == MIN) ?
            getExtremaParent(root->lchild, extrema) : getExtremaParent(root->rchild, extrema);
    }

    // BSTNode<T>* rotateRight(BSTNode<T>* root) {
    //     BSTNode<T>* temp = root->lchild;
    //     root->lchild = 
    // }

    // BSTNode<T>* rotateLeft() {}
};

#endif  /* BST_H */