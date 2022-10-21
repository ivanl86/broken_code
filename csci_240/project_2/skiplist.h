#include<vector>
#include<cstdlib>

#include"skiplist_node.h"

#ifndef SKIPLIST
#define SKIPLIST

// Note: It is assumed that type T has overloded comparison operators
template<typename T>
class Skiplist
{
public:
    // Adds an item into the container.
    void add(const T& item)
    {

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

    bool getsPromoted() { return static_cast<bool>(rand() & 1); }
};

#endif /* SKIPLIST */
