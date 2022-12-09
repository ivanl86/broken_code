#include "queue.h"
#include "gen_heap.h"

#ifndef PQUEUE_H
#define PQUEUE_H

template<typename T>
class PriorityQueue : public Queue<T>
{
public:
    PriorityQueue(std::function<bool(T ,T)> comparator) : gHeap{comparator} {}

    PriorityQueue(std::function<bool(T ,T)> comparator, const T array[], const size_t size)
    : gHeap{comparator, array, size} {}

    void enqueue(T item)
    { gHeap.add(item); }

    T dequeue()
    { return gHeap.remove(); }

    T getFront()
    { return gHeap.root(); }

    bool isEmpty()
    { return gHeap.size() == 0; }

    void clear()
    { gHeap.clear(); }

private:
    GenHeap<T> gHeap;
};

#endif  /* PQUEUE_H */