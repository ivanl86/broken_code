#include <cstddef>

#ifndef BAG_H
#define BAG_H

template <typename T>
class Bag
{
public:
    Bag() : count{0} {}

    virtual bool add(T item) = 0;
    virtual bool remove(T item) = 0;
    virtual bool contains(T item) = 0;
    virtual size_t size() = 0;
    virtual T grab() = 0;

protected:
    size_t count;
};

#endif