#include<vector>
#include<cstdlib>
#include<functional>

#include"skiplist_node.h"

#ifndef SKIPLIST
#define SKIPLIST

#define LV_0 0
#define LV_1 1

// Note: It is assumed that type T has overloded comparison operators
template<typename T>
class Skiplist
{
public:
    Skiplist(std::function<bool(T,T)> comparator)
        : comparator{comparator}, itemQty{0} {}

    // Adds an item into the container.
    void add(const T& item)
    {
        SkiplistNode<T>* newNode(new SkiplistNode<T>(item));
        std::vector<SkiplistNode<T>*> itr = priorNode(item);

        if (itemQty <= 0)
        {
            levels.emplace_back(newNode);
            // levels.at(LV_0) = newNode;

            while (getsPromoted())
            {
                levels.at(LV_0)->levels.emplace_back(nullptr);
                levels.emplace_back(newNode);
            }
        }
        else
        {
            newNode->levels.at(0) = itr.at(0)->levels.at(0);
            itr.at(0)->levels.at(0) = newNode;

            // while (getsPromoted())
            {
                promoteNode(newNode);
            }
        }

        ++itemQty;
    }

    // Removes and returns an item from the container
    T remove(const T& item)
    {
        --itemQty;
        return item;
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

    std::vector<SkiplistNode<T>*> priorNode(const T& item)
    {
        std::vector<SkiplistNode<T>*> itr{levels};

        for(int i{static_cast<int>(levels.size() - 1)}; i >= 0; --i)
        {
            while (itr.at(i) != nullptr)// || comparator(itr.at(i)->item, item))
                if (comparator(itr.at(i)->item, item))
                    itr.at(i) = itr.at(i)->levels.at(LV_0);
                else
                    break;
        }
        return itr;
    }

    SkiplistNode<T>* pNode(const T& item)
    {
        SkiplistNode<T>* itr{levels.at(LV_0)};

        while (itr != nullptr)
            if (comparator(itr->item, item))
                itr = itr->levels.at(LV_0);
            else
                break;

        return itr;
    }

    void promoteNode(SkiplistNode<T>* & node)
    {
        SkiplistNode<T>* itr{pNode(node->item)};

        // node->levels.emplace_back(node);
        node->levels.emplace_back(nullptr);
        node->levels.at(node->levels.size() - 1) = node;

        if (levels.size() < node->levels.size())
            levels.emplace_back(nullptr);

        for(size_t i{LV_1}; i < levels.size() - 1; ++i)
        {
            itr->levels.at(i) = node;
            node = itr->levels.at(i)->levels.at(LV_0);
        }
    }
};

#endif /* SKIPLIST */
