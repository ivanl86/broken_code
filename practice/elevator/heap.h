#include <cstdint>

#ifndef HEAP_H
#define HEAP_H

template <typename T>
class Heap {
public:
    virtual void add(const T&) = 0;
    virtual T root() const = 0;
    virtual T remove() = 0;
    virtual void clear() = 0;
    virtual uint64_t size() const = 0;
};

#endif  /* HEAP_H */