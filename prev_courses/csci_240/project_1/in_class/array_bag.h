#include <stdexcept>

#include "bag.h"

#ifndef ARRAY_BAG_H
#define ARRAY_BAG_H

#define DEFAULT_SIZE 10
#define SCALING_FACTOR 2

template <typename T>
class ArrayBag : public Bag<T>
{
public:
    ArrayBag() : store{new T[DEFAULT_SIZE]} {}

    bool add(T item)
    {
        if (this->count >= currentSize)
            resize();
        store[this->count++] = item;
        return true;
    }

    bool remove(T item)
    {
        int i = indexOf(item);
        if (i > 0)
        {
            store[i] = store[--this->count];
            return true;
        }
        return false;
    }

    bool contains(T item)
    { return indexOf(item) >= 0; }

    size_t size()
    { return this->count; }

    T grab()
    {
        if (this->count == 0)
            throw std::runtime_error("Grab on empty bag!");
        return store[0];
    }

private:
    T *store;
    size_t currentSize;

    void resize()
    {
        currentSize *= SCALING_FACTOR;
        T *newStore{new T[currentSize]};
        for (size_t i = 0; i < this->count; ++i)
            newStore[i] = store[i];
        delete[] store;
        store = newStore;
    }

    int indexOf(T item)
    {
        for (size_t i = 0; i < this->count; ++i)
            if (store[i] == item)
                return i;
        return -1;
    }
};

#endif