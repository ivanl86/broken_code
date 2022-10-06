#include <functional>
#include <cmath>

#include "heap.h"

#ifndef GEN_HEAP_H
#define GEN_HEAP_H

#define ROOT 1
#define SCALING_FACTOR 2
#define DEFAULT_SIZE 15

template<typename T>
class GenHeap : public Heap<T>
{
public:
    // GenHeap(std::function<size_t(T, T)> comparator)
    // : GenHeap(DEFAULT_SIZE), comparator{comparator} {}

    GenHeap(size_t initialSize)
    : store{new T[initialSize + 1]}, currentSize{initialSize}, itemQty{0} {}

    GenHeap(std::function<size_t(T, T)> comparator, const T array[], const size_t size)
    : comparator{comparator}
    {
        size_t lastPIdx{getlastPIdx(size)};
        currentSize = size * SCALING_FACTOR;

        for (size_t i{0}; i < size; ++i)
            store[i] = array[i];

        heapify(lastPIdx);
    }

    void add(T item)
    {
        if (itemQty >= currentSize)
            resize();
        
        store[++itemQty] = item;
        upHeap(itemQty + 1);
    }

    T root()
    {
        if (itemQty < 1)
            throw std::runtime_error("Nothing to look");

        return store[ROOT];
    }

    T remove() 
    {
        T rtnItem{store[ROOT]};

        if (itemQty < 1)
            throw std::runtime_error("Nothing to remove");

        store[ROOT] = store[itemQty--];
        downHeap(ROOT);

        return rtnItem;
    }

    void clear() { itemQty = 0; }

    size_t size() { return itemQty; }

private:
    T *store;
    
    size_t itemQty;
    size_t currentSize;

    std::function<size_t(T, T)> comparator;

    void upHeap(size_t pIdx)
    {
        size_t maxIdx;

        if (pIdx < ROOT)
            return;

        maxIdx = comparator(pIdx);

        if (maxIdx == pIdx)
            return;

        swap(maxIdx, pIdx);

        upHeap(pIdx >> 1);
    }

    void downHeap(size_t pIdx)
    {
        size_t maxIdx;
        
        if (pIdx >= itemQty)
            return;

        maxIdx = comparator(pIdx);

        if (maxIdx == pIdx)
            return;

        swap(maxIdx, pIdx);

        downHeap(maxIdx);
    }

    void swap(size_t pIdx_1, size_t pIdx_2)
    {
        T temp{store[pIdx_1]};
        store[pIdx_1] = store[pIdx_2];
        store[pIdx_2] = temp;
    }

    void resize()
    {
        size_t newSize{currentSize * SCALING_FACTOR};
        T *newStore{new T[newSize]};

        for(size_t i{0}; i < currentSize; ++i)
            newStore[i] = store[i];

        delete[] store;
        store = newStore;
        currentSize = newSize;
    }

    size_t getlastPIdx(size_t n)
    { return static_cast<size_t>(
        ceil(static_cast<double>((n - 1) / 2.0))); }

    void heapify(size_t lastPIdx)
    {
        if (lastPIdx < ROOT)
            return;

        for(size_t i{lastPIdx}; i >= ROOT; --i)
            downHeap(i);
    }
};

#endif  /* GEN_HEAP_H */