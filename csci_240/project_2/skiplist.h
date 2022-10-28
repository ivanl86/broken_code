#include<functional>
#include<vector>
#include<cstdlib>

#include"skiplist_node.h"

#ifndef SKIPLIST
#define SKIPLIST

#define LEVEL_0 0

// Note: It is assumed that type T has overloded comparison operators
template<typename T>
class Skiplist
{
public:
    Skiplist(std::function<bool(T,T)> comparator)
        : comparator{comparator}, itemQty{0}, emptyNode{new SkiplistNode<T>(0, nullptr)}
    {
        levels.emplace_back(emptyNode);
    }

    // Adds an item into the container.
    void add(const T& item)
    {
        // size_t curLv{levels.size() - 1};
        std::vector<SkiplistNode<T>*> itr{levels};
        SkiplistNode<T> *newNode(new SkiplistNode<T>(item, newNode));

        if (itemQty < 1)
            levels.at(LEVEL_0)= newNode;
            levels.at(LEVEL_0)->levels.at(LEVEL_0) = levels.at(LEVEL_0);
            // levels.at(LEVEL_0) = new SkiplistNode<T>(item, levels.at(LEVEL_0));


        // for(size_t i{levels.size() - 1}; i >= 0; --i)
        // {
        //     while (itr.at(i) != nullptr)
        //     {
        //         if (itr.at(i)->item >= item)
        //             break;
        //         itr.at(i) = itr.at(i)->levels.at(i);
        //     }
        // }
        


        ++itemQty;

        while (getsPromoted())
        {
            ;
        }
    }

    // Removes and returns an item from the container
    T remove(const T& item)
    {

    }

    // Checks if item is already in the container. Returns true if it is and false otherwise
    bool contains(const T& item)
    {
        return true;
    }

    // returns the number of items stored in the set
    size_t size() { return itemQty; }

private:
    SkiplistNode<T> *emptyNode;
    std::vector<SkiplistNode<T>*> levels;
    size_t itemQty;

    std::function<bool(T,T)> comparator;

    bool getsPromoted() { return static_cast<bool>(rand() & 1); }

    SkiplistNode<T> *precedingNode(const T &item)
    {
    }

    void promoteNode()
    {}
};

#endif /* SKIPLIST */
