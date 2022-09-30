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
    MaxHeap()
    {}

    void add(T item)
    {
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
        size_t rtn = compare(pIdx);

        if (rtn != pIdx)
        {
            swap(pIdx);
            downHeap(pIdx);
        }
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

    void swap(size_t pIdx)
    {
        T temp{store[pIdx]};
        size_t lChild{pIdx << 1};
        size_t rChild{lChild + 1};

        if (store[lChild] > store[rChild])
        {
            store[pIdx] = store[lChild];
            store[lChild] = temp;

        }
        else
        {
            store[pIdx] = store[rChild];
            store[rChild] = temp;
        }
    }

};

#endif  /* MAX_HEAP_H */