#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <cmath>

#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#define ROOT 1
#define SCALING_FACTOR 2
#define DEFAULT_SIZE 16

template<typename T, size_t S>
class MaxHeap : public Heap<T> // Heap<T> T is referred from the T in MaxHeap and will be passed into Heap
{
public:
    MaxHeap() : MaxHeap(DEFAULT_SIZE) {}

    MaxHeap(const T array[], size_t size)
    {
        size_t lastParent{getLastParent(size)};

        for(size_t i{0}; i < size; ++i)
            store[i + 1] = array[i];
        // call heapify
        heapify(lastParent);
    }

    MaxHeap(size_t initialSize) : store{new T[initialSize + 1]}
    {}

    void add(T item)
    {
        if (itemQty > S)
            throw std::runtime_error("add on full heap");

        store[++itemQty] = item;

        upHeap(itemQty >> 1);
    }

    T root()
    {
        if (itemQty == 0)
            throw std::runtime_error("Root on an empty heap!");

        return store[ROOT];
    }

    T remove()
    {
        T rtn{store[ROOT]};

        if (itemQty == 0)
            throw std::runtime_error("Remove on an empty heap!");

        store[ROOT] = store[itemQty--];
        downHeap(ROOT);

        return rtn;
    }

    void clear()
    { itemQty = 0; }

    size_t size()
    { return itemQty; }

private:
    size_t itemQty;
    size_t currentSize;

    T *store;

    void upHeap(size_t pIdx)
    {
        size_t maxIdx;

        if (pIdx == 0)
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

        rtnIdx = (store[pIdx] <= store[lChild] ? pIdx : lChild);

        if (rChild <= itemQty)
            rtnIdx = (store[rtnIdx] <= store[rChild] ? rtnIdx : rChild);

        return rtnIdx;
    }

    void swap(size_t p1Idx, size_t p2Idx)
    {
        T temp{store[p1Idx]};
        store[p1Idx] = store[p2Idx];
        store[p2Idx] = temp;
    }

    size_t getLastParent(size_t n)
    { return static_cast<size_t>
        (ceil(static_cast<double>(n - 1) / 2.0)); }

    void resize()
    {
        size_t newSize{currentSize * SCALING_FACTOR};
        T *newStore{new T[newSize]};

        for(size_t i{ROOT}; i < currentSize; ++i)
        {
            newStore[i] = store[i];
        }

        delete store;
        store = newStore;
        currentSize = newSize;
    }

    void heapify(size_t lastParent)
    {
        if (lastParent == 0)
            return;

        for(size_t i{lastParent}; i >= ROOT; --i)
                downHeap(i);
};

#endif  /* MAX_HEAP_H */
/*
void heapify(size_t idx)
{
    
    size_t maxIdx;

    if (idx == 0)
        return;

    maxIdx = compare(idx);
    if (maxIdx != idx)
    {
        swap(idx, maxIdx);
        downHeap(maxIdx);
    }

    heapify(idx - 1);
}
*/

/*
void heapify(size_t idx)
{
    if (idx == 0)
        return;

    downHeap(idx);

    heapify(idx - 1);
}
*/

/*
    void heapify(size_t lastParent)
    {
        size_t maxIdx{};

        if (lastParent == 0)
            return;

        for(size_t i{lastParent}; i >= ROOT; --i)
        {
            maxIdx = compare(i);
            if (maxIdx != i)
            {
                swap(i, maxIdx);
                downHeap(maxIdx);
            }
        }
    }
*/

