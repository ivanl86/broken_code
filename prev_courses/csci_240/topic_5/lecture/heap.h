#include <cstddef>

#ifndef HEAP_H
#define HEAP_H

template<typename T>
struct Heap
{
    virtual void add(T) = 0;
    virtual T root() = 0;
    virtual T remove() = 0;
    virtual void clear() = 0;
    virtual size_t size() = 0;
};

#endif  /* HEAP_H */