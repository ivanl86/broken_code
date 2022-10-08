#include <stdexcept>
#include "heap.h"

#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#define EMPTY 0
#define ROOT 1
#define SCALING_FACTOR 2
#define DEFAULT_SIZE 9

template<typename T>
class MinHeap : public Heap<T>
{
public:
    MinHeap() : MinHeap(DEFAULT_SIZE) {}

    MinHeap(uint64_t initialSize) : currentSize{initialSize + 1}, itemQty{0}, store{new T[initialSize]} {}

    void add(T item)
    {
        if (itemQty >= currentSize)
            resize();

        store[++itemQty] = item;
        upHeap(itemQty >> 1);
    }

    T root()
    {
        if (itemQty <= EMPTY)
            throw std::runtime_error("Root on empty heap");
        
        return store[ROOT];
    }

    T remove()
    {
        T rtnItem;
    
        if (itemQty <= EMPTY)
            throw std::runtime_error("Remove on empty heap");
        
        rtnItem = store[ROOT];
        store[ROOT] = store[itemQty--];
        downHeap(ROOT);
    
        return rtnItem;
    }

    uint64_t size() { return itemQty; }

    void clear() { itemQty = 0; }

private:
    void upHeap(uint64_t pIdx)
    {
        uint64_t minIdx;

        if (pIdx < ROOT)
            return;

        minIdx = compare(pIdx);

        if (minIdx == pIdx)
            return;

        swap(pIdx, minIdx);

        upHeap(pIdx >> 1);
    }

    void downHeap(uint64_t pIdx)
    {
        uint64_t minIdx;

        if (pIdx >= itemQty)
            return;

        minIdx = compare(pIdx);

        if (minIdx == pIdx)
            return;

        swap(pIdx, minIdx);

        downHeap(minIdx);
    }

    uint64_t compare(uint64_t pIdx)
    {
        uint64_t rtnIdx;
        uint64_t lChild{pIdx << 1};
        uint64_t rChild{lChild + 1};

        rtnIdx = (lChild <= itemQty && store[lChild] < store[pIdx]) ? lChild : pIdx;
        rtnIdx = (rChild <= itemQty && store[rChild] < store[rtnIdx]) ? rChild : rtnIdx;

        return rtnIdx;
    }

    void swap(uint64_t left, uint64_t right)
    {
        T temp{store[left]};
        store[left] = store[right];
        store[right] = temp;
    }

    void resize()
    {
        uint64_t newSize{currentSize * SCALING_FACTOR};
        T *newStore{new T[newSize]};

        for(size_t i{ROOT}; i <= currentSize; ++i)
            newStore[i] = store[i];

        delete[] store;
        store = newStore;
        currentSize = newSize;
    }

    uint64_t currentSize;
    uint64_t itemQty;

    T *store;
};

#endif  /* MIN_HEAP_H */