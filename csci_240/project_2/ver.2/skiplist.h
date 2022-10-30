#include<vector>
#include<cstdlib>
#include<functional>

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
        : comparator{comparator}, itemQty{0}
    {
        levels.emplace_back(new SkiplistNode<T>);
    }

    // Adds an item into the container.
    void add(const T& item)
    {
        std::vector<SkiplistNode<T>*> newNode{new SkiplistNode<T>(item)};
        std::vector<SkiplistNode<T>*> itr;

        while (getsPromoted())
        { promoteNode(newNode); }

        itr = priorNode(item);

        for(int i{static_cast<int>(newNode.size() - 1)}; i >= 0; --i)
        {
            if (itemQty == 0)
            { levels.at(i)->next = newNode; }
            else
            {
                newNode.at(i)->next.at(LEVEL_0) = itr.at(i)->next.at(LEVEL_0); // the newNode.next points to itr.next
                itr.at(i)->next.at(LEVEL_0) = newNode.at(i);                   // the itr.next points to newNode
            }
        }
        ++itemQty;
    }

    // Removes and returns an item from the container
    T remove(const T& item)
    {
        return item;
    }

    // Checks if item is already in the container. Returns true if it is and false otherwise
    bool contains(const T& item)
    {
        std::vector<SkiplistNode<T>*> itr = priorNode(item);
        return true;
    }

    // returns the number of items stored in the set
    size_t size() { return itemQty; }

private:
    std::vector<SkiplistNode<T>*> levels; // the nodes of the skiplist
    size_t itemQty; // the number of items stored

    std::function<bool(T,T)> comparator;

    bool getsPromoted() { return static_cast<bool>(rand() & 1); }

    std::vector<SkiplistNode<T>*> priorNode(const T& item)
    {
        std::vector<SkiplistNode<T>*> itr{levels};

        for(int i{static_cast<int>(levels.size() - 1)}; i >= 0; --i)
        {
            while (itr.at(i)->next.at(LEVEL_0) != nullptr)
            {
            if (comparator(item, itr.at(i)->next.at(LEVEL_0)->item))
                itr.at(i) = itr.at(i)->next.at(LEVEL_0);
            else
                break;
            }
        }
        return itr;
    }

    void promoteNode(std::vector<SkiplistNode<T>*>& newNode)
    {
        newNode.emplace_back(newNode.at(LEVEL_0));
        if (levels.size() < newNode.size())
        {
            levels.emplace_back(levels.at(LEVEL_0));
            levels.at(levels.size() - 1)->next.at(LEVEL_0) = nullptr;
        }
    }
};

#endif /* SKIPLIST */
