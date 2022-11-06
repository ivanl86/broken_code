#include <functional>

#include "set.h"
#include "bst.h"

#ifndef ORDERED_SET_H
#define ORDERED_SET_H

template<typename T>
class OrderSet : Set<T>
{
public:
    OrderSet(std::function<bool(T ,T)> comparator) : comparator{comparator} {}

    // inserts an item into the set. Returns true if success or false otherwise.
    // It will be unsuccessful if an equal item already exists.
    bool insert(const T& item) {
        return (bst.contains(item) ? false : bst.add(item));
    }

    // removes an item, returns true if success or false otherwise
    bool erase(const T& item) {
        return bst.remove(item);
    }

    // removes an item at a certain position where 0 <= position <= size - 1,
    // returns true if success or false otherwise
    bool erase(const uint64_t& position) {}

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
    std::list<T>* toSequence() {}

    // returns a set created from the union of A and B
    Set<T>* unionSet(const Set<T>* A, const Set<T>* B) {}

    // returns a set created from the intersection of A and B
    Set<T>* intersection(const Set<T>* A, const Set<T>* B) {}

private:
    BinarySearchTree<T> bst;

    std::function<bool(T ,T)> comparator;

    void inorderTraversal(BSTNode<T>* root) {
        
    }
};

#endif  /* ORDERED_SET_H */