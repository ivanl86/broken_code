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
    GenHeap(std::function<bool(T, T)> comparator)
    : GenHeap(comparator, DEFAULT_SIZE) {}

    GenHeap(std::function<bool(T, T)> comparator, size_t initialSize)
    : store{new T[initialSize]}, comparator{comparator}, currentSize{initialSize}, itemQty{0} {}

    GenHeap(std::function<bool(T, T)> comparator, const T array[], const size_t size)
    : comparator{comparator}, itemQty{size}
    {
        size_t lastPIdx{getlastPIdx(size)};
        currentSize = size * SCALING_FACTOR;
        store = new T[currentSize];

        for (size_t i{0}; i < size; ++i)
            store[i + 1] = array[i];

        heapify(lastPIdx);
    }

    void add(T item)
    {
        if (itemQty >= currentSize)
            resize();

        store[++itemQty] = item;
        upHeap(itemQty >> 1);
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

    std::function<bool(T, T)> comparator;

    void upHeap(size_t pIdx)
    {
        size_t maxIdx;

        if (pIdx < ROOT)
            return;

        maxIdx = compare(pIdx);

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

        maxIdx = compare(pIdx);

        if (maxIdx == pIdx)
            return;

        swap(maxIdx, pIdx);

        downHeap(maxIdx);
    }

    size_t compare(size_t pIdx)
    {
        size_t rtnIdx;

        size_t lChild{pIdx << 1};
        size_t rChild{lChild + 1};

        rtnIdx = ((lChild <= itemQty && comparator(store[lChild], store[pIdx])) ? lChild : pIdx);

        rtnIdx = ((rChild <= itemQty && comparator(store[rChild], store[rtnIdx])) ? rChild : rtnIdx);

        return rtnIdx;
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

        for(size_t i{ROOT}; i <= currentSize; ++i)
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