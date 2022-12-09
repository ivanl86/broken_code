#include <cstdint>

#include "bst_node.h"

#ifndef BST_H
#define BST_H

template<typename T>
class BinarySearchTree
{
public:
    BinarySearchTree() : root{nullptr}, itemQty{0} {}

    void add(T item) {
        BSTNode<T>* itr{root};

        if (root == nullptr)
            root = new BSTNode<T>(item);
        else {
            if (itr->item > item)
                while (itr->lchild != nullptr)
            while (itr != nullptr) {
                (itr->item > item) ? (itr = itr->lchild) : (itr = itr->rchild);
            }
            itr = new BSTNode<T>(item);
        }

        
        ++itemQty;
    }

    bool remove(T item) {
        BSTNode<T> *itr{root};

        while (itr != nullptr) {
            if (itr->item == item)
            {
                /* code */
                return true;
            }
            
            (itr->item > item) ?
                (itr = itr->lchild) : (itr = itr->rchild);
        }

        return false;
    }

    BSTNode<T>* find(T item) {
        
    }

    bool contains(T item) {
        BSTNode<T> *itr{root};

        while (itr != nullptr) {
            if (itr->item == item)
                return true;

            (itr->item > item) ?
                (itr = itr->lchild) : (itr = itr->rchild);
        }

        return false;
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
        // BSTNode<T> *itr{root};

        // while (itr != nullptr) {
        //     it
        // }
    }

    BSTNode<T>* getMin(BSTNode<T>* root) {

    }

private:
    BSTNode<T>* root;
    uint64_t itemQty;

};

#endif  /* BST_H */