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
        : comparator{comparator}, itemQty{0}
    {

    }

    // Adds an item into the container.
    void add(const T& item)
    {
        SkiplistNode<T>* newNode{new SkiplistNode<T>(item, nullptr)};
        std::vector<SkiplistNode<T>*> currentLevel(levels.size(), nullptr);


        if (levels.size() <= 0)
            levels.emplace_back(newNode);
        else
        {
            for (size_t i{levels.size() - 1}; i >= 0; --i)
            {
                while (levels.at(i) != nullptr)
                {
                    if (comparator(levels.at(i)->item, item))
                        currentLevel.at(i)->item = item;
                    else if (currentLevel.at(i)->levels.at(i) != nullptr)
                        currentLevel.at(i) = currentLevel.at(i)->levels.at(i);
                }
            }
        }
        levels.at(LEVEL_0)->levels.at(LEVEL_0) = precedingNode(item, levels.size() - 1);

        levels.at(LEVEL_0)->levels.at(LEVEL_0) = newNode;

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
    SkiplistNode<T> *next;
    std::vector<SkiplistNode<T>*> levels;
    size_t itemQty;

    std::function<bool(T,T)> comparator;

    bool getsPromoted() { return static_cast<bool>(rand() & 1); }

    SkiplistNode<T> *precedingNode(const T &item, size_t lv)
    {
        SkiplistNode<T>*preceNode;
        std::vector<SkiplistNode<T>*>iterator{levels};
        while (iterator.at(lv) != nullptr)
        {
            if (comparator(iterator.at(lv)->item, item))
                preceNode = iterator.at(lv);
            iterator.at(lv) = iterator.at(lv)->levels.at(lv);
        }
        return preceNode;
    }
};

#endif /* SKIPLIST */
