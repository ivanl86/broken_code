#include<vector>

#ifndef SKIPLIST_NODE
#define SKIPLIST_NODE

template<typename T>
struct SkiplistNode
{
    T item;
    std::vector<SkiplistNode<T>*> levels;

    SkiplistNode()
    { levels.push_back(nullptr); }

    SkiplistNode(const T& item) : item{item}
    { levels.push_back(nullptr); }
};

#endif /* SKIPLIST_NODE */
