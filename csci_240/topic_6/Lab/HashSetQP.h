#include <functional>

#include "set.h"
#include "valuestate_pair.h"

#ifndef HASHSETQP_H
#define HASHSETQP_H

#define DEFAULT_SIZE 157
#define MAX_ATTEMPT 27
#define MAX_OCCUPANCY 0.6
#define SCALING_FACTOR 2

template<typename T>
class HashSetQP : Set<T>
{
public:
    HashSetQP(std::function<int(T)> h_1)
    : h_1{h_1}, set{new VSPair<T>[DEFAULT_SIZE]}, currentSz{DEFAULT_SIZE}, itemQty{0}
    {}

    bool insert(const T& item)
    {
        int attempt{0};
        int hash{h_1(item)};
        int idx{h_2(hash)};
        int i{1};

        if (itemQty >= (currentSz * MAX_OCCUPANCY))
            resize();

        while ((set[idx].state != EMPTY && set[idx].state != AVAILABLE) && idx < currentSz)
        {
            idx = h_2(hash + (i * i));
            ++i;
            ++attempt;
            if (attempt > MAX_ATTEMPT)
                return false;
        }

        if (idx >= currentSz)
            return false;

        set[idx].value = item;
        set[idx].state = OCCUPIED;
        ++itemQty;

        return true;
    }

    bool erase(const T& item)
    {
        int attempt{0};
        int hash{h_1(item)};
        int idx{h_2(hash)};
        int i{1};

        while (set[idx].state != EMPTY && idx < currentSz)
        {
            if (set[idx] == item && set[idx].state == OCCUPIED)
            {
                set[idx].state = AVAILABLE;
                --itemQty;

                return true;
            }
            ++attempt;
            if (attempt >= currentSz)
                return false;

            idx = h_2(hash + (i * i));
            ++i;
        }

        return false;
    }

    const T* find(const T& item)
    {
        int attempt{0};
        int hash{h_1(item)};
        int idx{h_2(hash)};
        int i{1};
        const int *rtn;

        while (set[idx].state != EMPTY && idx < currentSz)
        {
            if (set[idx] == item && set[idx].state == OCCUPIED)
                return &set[idx].value;

            ++attempt;
            if (attempt >= currentSz)
                return nullptr;

            idx = h_2(hash + (i * i));
            ++i;
        }

        return nullptr;
    }

    bool contains(const T& item)
    {
        int attempt{0};
        int hash{h_1(item)};
        int idx{h_2(hash)};
        int i{1};

        while (set[idx].state != EMPTY && idx < currentSz)
        {
            if (set[idx] == item && set[idx].state == OCCUPIED)
                return true;

            ++attempt;
            if (attempt >= currentSz)
                return false;

            idx = h_2(hash + (i * i));
            ++i;
        }

        return false;
    }

private:
    VSPair<T> *set;
    size_t currentSz;
    size_t itemQty;

    std::function<int(T)> h_1;

    int h_2(int k)
    { return abs(k) % currentSz; }

    void resize()
    {
        int hash;
        int idx;
        size_t newSize{currentSz * SCALING_FACTOR};
        VSPair<T> *newSet{new VSPair<T>[newSize]};

        for(size_t i{0}; i < currentSz; ++i)
        {
            if (set[i].state == OCCUPIED)
            {
                hash = h_1(set[i].value);
                idx = h_2(hash);
                newSet[idx] = set[i];
            }
        }

        delete[] set;
        set = newSet;
        currentSz = newSize;
    }
};

#endif  /* HASHSETQP_H */