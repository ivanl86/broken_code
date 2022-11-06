#include <functional>

#include "set.h"
#include "bst.h"

#ifndef ORDERED_SET_H
#define ORDERED_SET_H

template<typename T>
class OrderedSet : public Set<T>
{
public:
    OrderedSet(std::function<bool(T ,T)> comparator) : comparator{comparator} {}

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
        uint64_t counter{0};

        while (counter != position) {
            ++counter;
        }
        
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
    std::list<T>* toSequence() {
        std::list<T>* list{new std::list<T>};
        toSequence(list, bst.getRoot());
        return list;
    }

    // returns a set created from the union of A and B
    Set<T>* unionSet(const Set<T>* A, const Set<T>* B) {}

    // returns a set created from the intersection of A and B
    Set<T>* intersection(const Set<T>* A, const Set<T>* B) {

    }

    void inorderTraversal() {
        bst.inorderTraversal(bst.getRoot());
    }



private:
    BinarySearchTree<T> bst;

    std::function<bool(T ,T)> comparator;
    // std::function<void> process;

    void toSequence(std::list<T>* list, BSTNode<T>* root) {
        if (root == nullptr)
            return;

        toSequence(list, root->lchild);
        list->emplace_back(root->item);
        toSequence(list, root->rchild);
    }
};

#endif  /* ORDERED_SET_H */