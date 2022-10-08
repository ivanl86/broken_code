#include <cstdint>

#ifndef HEAP_H
#define HEAP_H

template<typename T>
struct Heap
{
    virtual void add(T item) = 0;
    virtual T root() = 0;
    virtual T remove() = 0;
    virtual uint64_t size() = 0;
    virtual void clear() = 0;
};

#endif  /* HEAP_H */