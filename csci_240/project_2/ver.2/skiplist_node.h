#include<vector>

#ifndef SKIPLIST_NODE
#define SKIPLIST_NODE

template<typename T>
struct SkiplistNode
{
    T item; // holds the object in the node
    std::vector<SkiplistNode<T>*> next; // levels is changed to next for less confusion and better readability

    SkiplistNode() : next{nullptr} {}
    SkiplistNode(T item) : SkiplistNode<T>(item, nullptr) {}
    SkiplistNode(T item, SkiplistNode<T> *levels) : item{item}, next{levels} {}
};

#endif /* SKIPLIST_NODE */
