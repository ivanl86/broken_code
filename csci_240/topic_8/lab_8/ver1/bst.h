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

    bool add(const T& item) {
        if (empty())
            root = new BSTNode<T>(item);
        else
            add(item, root, root->parent);
        // (empty()) ? add() : add(item, root, root->parent);
        ++itemQty;
        return true;
    }

    bool remove(const T& item) {
        if (empty())
            throw std::runtime_error("Empty!");

        return (root->item == item && size() == 1) ? remove() : remove(item, root);
    }

    BSTNode<T>* find(const T& item) {
        if (empty())
            throw std::runtime_error("Empty!");

        return find (item, root);
    }

    bool contains(const T& item) {
        if (empty())
            throw std::runtime_error("Empty!");

        return contains(item, root);
    }

    void clear() {
        if (empty())
            throw std::runtime_error("Empty!");

        clear(root);

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

private:
    BSTNode<T>* root;
    uint64_t itemQty;

    void add() {
        // root = new BSTNode<T>(item);
    }

    void add(const T& item, BSTNode<T>* root, BSTNode<T>* parent) {
        if (root == nullptr) {
            root = new BSTNode<T>(item, parent);
            (parent->item > item) ? parent->lchild = root : parent->rchild = root;
            return;
        }

        (root->item > item) ?
            add(item, root->lchild, root) : add(item, root->rchild, root);
    }

    bool remove() {
        delete root;
        root = nullptr;
        --itemQty;
        return true;
    }

    bool remove(const T& item, BSTNode<T>* root) {
        BSTNode<T>* tmp(nullptr);

        if (root == nullptr)
            return false;

        if (root->item == item) {
            if (root->lchild != nullptr) {
                tmp = getMax(root->lchild);
                root->item = tmp->item;
                (tmp == root->lchild) ? root->lchild = root->lchild->lchild : tmp->parent->rchild = tmp->lchild;
                delete tmp;
                --itemQty;
                return true;
            }
            else if (root->rchild != nullptr) {
                tmp = getMin(root->rchild);
                root->item = tmp->item;
                (tmp == root->rchild) ? root->rchild = nullptr : tmp->parent->lchild = nullptr;
                delete tmp;
                --itemQty;
                return true;
            }
            else {
                (root->parent->item < root->item) ? root->parent->rchild = nullptr : root->parent->lchild = nullptr;
                delete tmp;
                --itemQty;
                return true;
            }
        }

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

    void clear(BSTNode<T>* root) {
        if (root == nullptr)
            return;
        clear(root->lchild);
        clear(root->rchild);
        delete root;
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
};

#endif  /* BST_H */