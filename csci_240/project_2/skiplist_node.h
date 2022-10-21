#include<vector>

#ifndef SKIPLIST_NODE
#define SKIPLIST_NODE

template<typename T>
struct SkiplistNode
{
    T item;

    std::vector<SkiplistNode<T>*> levels;
};

#endif /* SKIPLIST_NODE */
