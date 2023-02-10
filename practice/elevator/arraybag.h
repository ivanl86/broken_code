#include <stdexcept>

#include "bag.h"

#ifndef ARRAYBAG_H
#define ARRAYBAG_H

#define DEFAULT_BAG_SIZE 8
#define SCALING_FACTOR 2

template <typename T>
class ArrayBag : public Bag<T> {
public:
    ArrayBag() : ArrayBag(DEFAULT_BAG_SIZE) {}

    ArrayBag(const uint64_t& size)
    : store{new T[size]}, maxSize{size} {}

    bool add(const T& item) {
        if (this->count >= maxSize)
            resize();

        store[this->count] = item;
        ++this->count;
        return true;
    }

    bool remove(const T& item) {
        int64_t idx{find(item)};

        if (idx < 0)
            return false;

        --this->count;
        store[idx] = store[this->count];
        return true;
    }

    bool contains(const T& item) {
        return find(item) >= 0;
    }

    T peek() const {
        if (this->count <= 0)
            throw std::runtime_error("Peek on empty bag!");

        return store[0];
    }

    uint64_t size() const {
        return this->count;
    }
private:
    T* store;
    uint64_t maxSize;

    int64_t find(const T& item) {
        for(size_t i{0}; i < this->count; ++i) {
            if (store[i] == item)
                return i;
        }
        return -1;
    }

    void resize() {
        maxSize *= SCALING_FACTOR;
        T* newStore{new T[maxSize]};

        for(size_t i{0}; i < this->count; ++i)
            newStore[i] = store[i];

        delete[] store;
        store = newStore;
    }
};

#endif  /* ARRAYBAG_H */