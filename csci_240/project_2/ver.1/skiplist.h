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
        // levels.emplace_back(new SkiplistNode<T>(0, nullptr));
    }

    // Adds an item into the container.
    void add(const T& item)
    {
        std::vector<SkiplistNode<T>*> itr;
        // SkiplistNode<T> *newNode(new SkiplistNode<T>(item, nullptr));
        std::vector<SkiplistNode<T>*> newNode;
        newNode.emplace_back(new SkiplistNode<T>(item, nullptr));

        while (getsPromoted()) {
            newNode.emplace_back(newNode.at(LEVEL_0)); }

        if (levels.size() <= 0 && itemQty == 0)
            levels = newNode;
        else
        {
            itr = priorNode(item);

            if (comparator(item, itr.at(LEVEL_0)->item))
            {
                newNode.at(LEVEL_0)->levels.at(LEVEL_0) = itr.at(LEVEL_0)->levels.at(LEVEL_0);
                itr.at(LEVEL_0)->levels.at(LEVEL_0) = newNode.at(LEVEL_0);
            }
            else
            {
                newNode.at(LEVEL_0)->levels.at(LEVEL_0) = itr.at(LEVEL_0);
                levels.at(LEVEL_0) = newNode.at(LEVEL_0);
            }
        }

        // if (levels.size() == 3)
        //     levels.at(2)->levels.at(0) = nullptr;

        ++itemQty;
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
    std::vector<SkiplistNode<T>*> levels;
    size_t itemQty;

    std::function<bool(T,T)> comparator;

    bool getsPromoted() { return static_cast<bool>(rand() & 1); }

    std::vector<SkiplistNode<T>*> priorNode(const T &item)
    {
        // int lv{static_cast<int>(levels.size() - 1)};
        std::vector<SkiplistNode<T>*> itr{levels};

        // while (lv >= 0 && itr.at(lv)->levels.at(LEVEL_0) != nullptr)
        // {
        //     if (comparator(item, itr.at(lv)->levels.at(LEVEL_0)->item)) // item > itr.at(lv)->levels.at(lv)->item
        //         itr.at(lv) = itr.at(lv)->levels.at(LEVEL_0);
        //     else
        //         --lv;
        // }
        for(int i{static_cast<int>(levels.size() - 1)}; i >= 0; --i)
        {
            while (itr.at(i)->levels.at(LEVEL_0) != nullptr)
                if (comparator(item, itr.at(i)->levels.at(LEVEL_0)->item))
                    itr.at(i) = itr.at(i)->levels.at(LEVEL_0);
                else
                    break;
        }
        
        return itr;
    }

    void promoteNode(std::vector<SkiplistNode<T>*> &node)
    {
        node.emplace_back(node.at(LEVEL_0));
    }
};

#endif /* SKIPLIST */

/*
        while (lv >= 0 && itr.at(lv)->levels.at(lv) != nullptr)
        {
            if (comparator(item, itr.at(lv)->levels.at(lv)->item)) // item > itr.at(lv)->levels.at(lv)->item
                itr.at(lv) = itr.at(lv)->levels.at(lv);
            else
                --lv;
        }

        levels.at(LEVEL_0)->levels.emplace_back(newNode);

        add(item)

        std::vector<SkiplistNode<T>*> itr;
        SkiplistNode<T> *newNode(new SkiplistNode<T>(item, nullptr));

        std::vector<SkiplistNode<T>*> newSNode;

        if (levels.size() <= 0)
        {
            levels.emplace_back(newNode);
            // if (true)
            //     levels.emplace_back(levels.at(LEVEL_0));
        }
        else
        {
            itr = priorNode(item);

            if (comparator(item, itr.at(LEVEL_0)->item))
            {
                newNode->levels.at(LEVEL_0) = itr.at(LEVEL_0)->levels.at(LEVEL_0);
                itr.at(LEVEL_0)->levels.at(LEVEL_0) = newNode;
            }
            else
            {
                newNode->levels.at(LEVEL_0) = itr.at(LEVEL_0);
                levels.at(LEVEL_0) = newNode;
                while (getsPromoted())
                    promoteNode(levels);
            }
        }

        ++itemQty;
*/