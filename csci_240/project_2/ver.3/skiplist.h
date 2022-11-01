#include<vector>
#include<cstdlib>
#include<functional>

#include"skiplist_node.h"

#ifndef SKIPLIST
#define SKIPLIST

// Note: It is assumed that type T has overloded comparison operators
template<typename T>
class Skiplist
{
public:
    Skiplist(std::function<bool(T,T)> comparator) : comparator{comparator}, itemQty{0}
    { levels.push_back(nullptr); }

    // Adds an item into the container.
    void add(const T& item)
    {
        SkiplistNode<T> newNode{new SkiplistNode<T>(item)};
    }

    // Removes and returns an item from the container
    T remove(const T& item)
    {

    }

    // Checks if item is already in the container. Returns true if it is and false otherwise
    bool contains(const T& item)
    {

    }

    // returns the number of items stored in the set
    size_t size() { return itemQty; }

private:
    std::vector<SkiplistNode<T>*> levels;
    size_t itemQty;

    std::function<bool(T,T)> comparator;

    bool getsPromoted() { return static_cast<bool>(rand() & 1); }
};

#endif /* SKIPLIST */
