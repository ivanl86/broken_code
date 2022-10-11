#include <functional>

#include "queue.h"
#include "gen_heap.h"

#ifndef P_QUEUE_H
#define P_QUEUE_H

template<typename T>
class PriorityQueue : public Queue<T>
{
public:
    PriorityQueue(std::function<bool(T, T) cmp) : gHeap{cmp} {}

    PriorityQueue(std::function<bool(T, T) cmp, size_t initialSize) : gHeap{cmp, intiialSize} {}

    PriorityQueue(std::function<bool(T, T) cmp, const T array[], size_t initialSize) : gHeap{cmp, array, size} {}

    void enqueue(T item)
    {
        gHeap.add(item);
    }

    T dequeue()
    {
        return gHeap.remove();
    }

    T getFront()
    {
        return gHeap.root();
    }

    void clear()
    {
        gHeap.clear;
    }

    bool empty()
    {
        return gHeap.size() == 0;
    }

private:
    GenHeap<T> gHeap;
};

#endif  /* P_QUEUE_H */