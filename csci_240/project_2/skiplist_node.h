#include<vector>

#ifndef SKIPLIST_NODE
#define SKIPLIST_NODE

template<typename T>
struct SkiplistNode
{
    T item;

    std::vector<SkiplistNode<T>*> levels;

    SkiplistNode(T item) : SkiplistNode<T>(item, nullptr) {}
    SkiplistNode(T item, SkiplistNode<T> *levels) : item{item}, levels{levels} {}
};

#endif /* SKIPLIST_NODE */
