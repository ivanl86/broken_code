#include <functional>

#include "set.h"

#ifndef HASHSET_H
#define HASHSET_H

#define INITIAL_SIZE 157
#define PROB_LIMIT 27

enum Status {EMPTY, AVAILABLE, OCCUPIED};

template<typename T>
class Hashset: public Set<T>
{
    struct Element
    {
        Element() : status{EMPTY} {}
        Element(const &T item) : item{item}, status{EMPTY} {}

        T item;
        Status status;
    };

public:
    Hashset(std::function<int(const &T)> hashcode)
        : hashcode{hashcode}, store{new Element[INITIAL_SIZE]}, count{0}
    {}
    bool insert(const T& item)
    {
        int s = locateAvailPos(item);
        if (s >= 0)
        {
            store[s].item = item;
            store[s].status = OCCUPIED;
            ++count;
            return true;
        }
        return false;
    }
    bool erase(const T& item)
    {
        int s = locateItem(item);
        if (s >= 0)
        {
            store[s].status = AVAILABLE;
            --count;
            return true;
        }
        return false;
    }
    const T* find(const T& item)
    {
        int s = locateItem(item);
        if (s >= 0)
            return &(store[s].item);

        return nullptr;
    }
    bool contains(const T& item)
    {
        int s = locateItem(item);
        if (s >= 0 && store[s].status == OCCUPIED)
            return true;

        return false;
    }
protected:
    size_t count;
    Element *store;

    std::function<int(const &T)> hashcode;
    int locateItem(const &T) = 0;
    int locateAvailPos(const T&) = 0;
};

#endif  /* HASHSET_H */