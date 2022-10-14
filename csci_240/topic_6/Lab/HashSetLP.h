#include <functional>

#include "set.h"
#include "keyvalue_pair.h"

#ifndef HASHSETLP_H
#define HASHSETLP_H

#define DEFAULT_SIZE 157
#define MAX_ATTEMPT 27

template<typename T>
class LPSet : Set<T>
{
public:
    LPSet(std::function<int(T)> h_1) : h_1{h_1}, set{new KVPair<T>[DEFAULT_SIZE]}, currentSz{DEFAULT_SIZE}
    {}

    bool insert(const T& item)
    {
        int attempt{0};
        int hash{h_1(item)};
        int idx{h_2(hash)};

        while ((set[idx].state != EMPTY && set[idx].state != AVAILABLE) && idx < currentSz)
        {
            ++idx;
            ++attempt;
            if (attempt >= MAX_ATTEMPT)
                return false;
        }

        if (idx >= currentSz)
            return false;

        set[idx].key = hash;
        set[idx].state = OCCUPIED;
        return true;
    }

    bool erase(const T& item)
    {
        int hash{h_1(item)};
        int idx{h_2(hash)};

        while (set[idx].state != EMPTY && idx < currentSz)
        {
            if (set[idx].key == item && set[idx].state == OCCUPIED)
            {
                set[idx].state = AVAILABLE;
                return true;
            }
            ++idx;
        }

        return false;
    }

    const T* find(const T& item)
    {
        int hash{h_1(item)};
        int idx{h_2(hash)};
        const int *rtn;

        while (set[idx].state != EMPTY && idx < currentSz)
        {
            if (set[idx].key == item && set[idx].state == OCCUPIED)
            {
                rtn = &set[idx].key;
                return rtn;
            }
            ++idx;
        }

        return nullptr;
    }

    bool contains(const T& item)
    {
        int hash{h_1(item)};
        int idx{h_2(hash)};

        while (set[idx].state != EMPTY && idx < currentSz)
        {
            if (set[idx].key == item && set[idx].state == OCCUPIED)
                return true;

            ++idx;
        }

        return false;
    }

private:
    KVPair<T> *set;
    size_t currentSz;

    std::function<int(T)> h_1;

    int h_2(int k)
    {
        return k % currentSz;
    }
};

#endif  /* HASHSETLP_H */