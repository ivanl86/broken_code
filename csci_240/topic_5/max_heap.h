#include <cstddef>
#include <cstdint>
#include <stdexcept>

#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#define ROOT 1

template<typename T, size_t S>
class MaxHeap : public Heap<T> // Heap<T> T is referred from the T in MaxHeap and will be passed into Heap
{
public:
    MaxHeap() : itemQty{0}
    {}

    void add(T item)
    {
        if (itemQty >= S)
            throw std::runtime_error("Add on full heap");

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
    T store[S + 1];

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

        // rtnIdx = (store[pIdx] <= store[lChild] ? pIdx : lChild);
        rtnIdx = (lChild <= itemQty && store[pIdx] <= store[lChild] ? lChild : pIdx);

        // if (rChild <= itemQty)
            // rtnIdx = (store[rtnIdx] <= store[rChild] ? rtnIdx : rChild);
        rtnIdx = (rChild <= itemQty && store[rtnIdx] <= store[rChild] ? rChild : rtnIdx);

        return rtnIdx;
    }

    void swap(size_t p1Idx, size_t p2Idx)
    {
        T temp{store[p1Idx]};
        store[p1Idx] = store[p2Idx];
        store[p2Idx] = temp;
    }
};

#endif  /* MAX_HEAP_H */