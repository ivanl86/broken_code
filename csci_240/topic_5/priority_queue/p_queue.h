#include "queue.h"
#include "gen_heap.h"

#ifndef PQUEUE_H
#define PQUEUE_H

template<typename T>
class PriorityQueue : public Queue<T>
{
public:
    //Queue(std::function<size_t(T ,T)> comparator) : GenHeap(comparator) {}

    Queue() {}

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