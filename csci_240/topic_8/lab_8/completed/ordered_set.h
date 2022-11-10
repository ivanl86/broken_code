#include <list>
#include <cstdint>
#include <functional>

// #include "set.h"
#include "bst.h"

#ifndef ORDERED_SET_H
#define ORDERED_SET_H

enum MERGE {
    UNION, INTERSECTION, SUBTRACT
};

template<typename T>
class OrderedSet// : public Set<T>
{
public:
    OrderedSet(std::function<bool(T ,T)> comparator) : bst{comparator} {}

    // inserts an item into the set. Returns true if success or false otherwise.
    // It will be unsuccessful if an equal item already exists.
    bool insert(const T& item) {
        if (bst.empty())
            return bst.add(item);

        return (bst.contains(item) ? false : bst.add(item));
    }

    // removes an item, returns true if success or false otherwise
    bool erase(const T& item) {
        return bst.remove(item);
    }

    // removes an item at a certain position where 0 <= position <= size - 1,
    // returns true if success or false otherwise
    bool erase(const uint64_t& position) {
        T item;
        uint64_t counter{0};

        if (position > bst.size())
            return false;

        erase(item, bst.getRoot(), counter, position);
        return (erase(item)) ? true : false;
    }

    // removes all elements from the set
    void clear() {
        bst.clear();
    }

    // returns true if empty or false otherwise
    bool empty() {
        return bst.empty();
    }

    // number of elements in the set
    uint64_t size() {
        return bst.size();
    }

    // returns a ordered sequence of the set items
    std::list<T> toSequence() {
        std::list<T> list;
        toSequence(list, bst.getRoot());
        return list;
    }

    // returns a set created from the union of A and B
    static OrderedSet<T> merge( OrderedSet<T>& A,  OrderedSet<T>& B, MERGE type) {
        std::list<T> listA{A.toSequence()};
        std::list<T> listB{B.toSequence()};
        OrderedSet<T> set(A.comparator);

        return merge(listA, listB, set, type);
    }

    void inorderTraversal() {
        bst.inorderTraversal(bst.getRoot());
    }

private:
    BinarySearchTree<T> bst;

    std::function<bool(T ,T)> comparator;

    void erase(T& item, BSTNode<T>* root, uint64_t& counter, const uint64_t& position) {
        if (root == nullptr || counter > position)
            return;

        if (counter <= position) { 
            erase(item, root->lchild, counter, position);
            ++counter;
            if (counter == position) {
                item = root->item;
            }
            erase(item, root->rchild, counter, position);
        }
    }

    void toSequence(std::list<T>& list, BSTNode<T>* root) {
        if (root == nullptr)
            return;

        toSequence(list, root->lchild);
        list.emplace_back(root->item);
        toSequence(list, root->rchild);
    }

    // static OrderedSet<T> merge(const std::list<T>& A, const std::list<T>& B, OrderedSet<T>& C, MERGE type) {
    //     typename std::list<T>::iterator a{A.begin()};
    //     typename std::list<T>::iterator b{B.begin()};

    //     while (a != A.end() && b != B.end()) {
    //         if (*a < *b)
    //             fromA(a++, C, type);
    //         else if (*a == *b)
    //             fromBoth(a++, b++, C, type);
    //         else
    //             fromB(b++, C, type);
    //     }

    //     while (a != A.end())
    //         fromA(a++, C, type);
    //     while (b != B.end())
    //         fromB(b++, C, type);

    //     return C;
    // }

    // static void fromA(const typename std::list<T>::iterator a, OrderedSet<T>& C, MERGE type) {
    //     if (type == UNION || type == SUBTRACT)
    //         C.insert(*a);
    //     else if (type == INTERSECTION)
    //         return;
    // }

    // static void fromBoth(const typename std::list<T>::iterator a, const typename std::list<T>::iterator b, OrderedSet<T>& C, MERGE type) {
    //     if (type == UNION || type == INTERSECTION)
    //         C.insert(*a);
    //     else if (type == SUBTRACT)
    //         return;
    // }

    // static void fromB(const typename std::list<T>::iterator b, OrderedSet<T>& C, MERGE type) {
    //     if (type == UNION)
    //         C.insert(*b);
    //     else if (type == INTERSECTION || type == SUBTRACT)
    //         return;
    // }
};

#endif  /* ORDERED_SET_H */