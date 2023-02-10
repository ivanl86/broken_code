#include <cstdint>

#ifndef BAG_H
#define BAG_H

template <typename T>
class Bag {
public:
    Bag() : count{0} {}
    virtual bool add(const T& item) = 0;
    virtual bool remove(const T& item) = 0;
    virtual bool contains(const T& item) = 0;
    virtual T peek() const = 0;
    virtual uint64_t size() const = 0;
protected:
    uint64_t count;
};

#endif  /* BAG_H */