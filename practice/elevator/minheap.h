#include <stdexcept>

#include "heap.h"

#ifndef MAXHEAP_H
#define MAXHEAP_H

#define ROOT 1
#define DEFAULT_HEAP_SIZE 6

template <typename T>
class MinHeap : public Heap<T> {
public:
    MinHeap() : MinHeap(DEFAULT_HEAP_SIZE) {}

    MinHeap(const uint64_t& maxSize)
    : store{new T[maxSize + 1]}, itemQty{0}, maxSize{maxSize} {}

    void add(const T& item) {
        if (itemQty >= maxSize)
            throw std::runtime_error("Heap is Full!");

        ++itemQty;
        store[itemQty] = item;

        upHeap(itemQty >> 1);
    }

    T root() const {
        if (itemQty <= 0)
            throw std::runtime_error("Root on an empty heap");

        return store[ROOT];
    }

    T remove() {
        T item{store[ROOT]};

        if (itemQty <= 0)
            throw std::runtime_error("Remove on an empty heap");

        store[ROOT] = store[itemQty];
        --itemQty;
        downHeap(ROOT);

        return item;
    }

    void clear() {
        itemQty = 0;
    }

    uint64_t size() const {
        return itemQty;
    }

private:
    T* store;
    uint64_t itemQty;
    uint64_t maxSize;

    void upHeap(uint64_t parentIdx) {
        uint64_t maxIdx;

        if (parentIdx < ROOT)
            return;

        maxIdx = compare(parentIdx);

        if (maxIdx == parentIdx)
            return;

        swap(maxIdx, parentIdx);

        upHeap(parentIdx >> 1);
    }

    void downHeap(uint64_t parentIdx) {
        uint64_t maxIdx;

        if (parentIdx >= itemQty)
            return;

        maxIdx = compare(parentIdx);

        if (maxIdx == parentIdx)
            return;

        swap(maxIdx, parentIdx);

        downHeap(maxIdx);
    }
    uint64_t compare(uint64_t parentIdx) {
        uint64_t returnIdx;
        uint64_t leftChild{parentIdx << 1};
        uint64_t rightChild{leftChild + 1};

        returnIdx = (leftChild <= itemQty && store[leftChild] < store[parentIdx] ? leftChild : parentIdx);
        returnIdx = (rightChild <= itemQty && store[rightChild] < store[returnIdx] ? rightChild : returnIdx);

        return returnIdx;
    }

    void swap(uint64_t idx1, uint64_t idx2) {
        T temp{store[idx1]};
        store[idx1] = store[idx2];
        store[idx2] = temp;
    }
};

#endif  /* MAXHEAP_H */