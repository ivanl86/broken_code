#include<vector>

#ifndef SKIPLIST_NODE
#define SKIPLIST_NODE

template<typename T>
struct SkiplistNode
{
    T item;
    std::vector<SkiplistNode<T>*> levels;

    SkiplistNode(T& item) : item{item}
    { levels.push_back(nullptr); }
};

#endif /* SKIPLIST_NODE */
