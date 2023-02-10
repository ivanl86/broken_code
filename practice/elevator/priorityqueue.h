#include "minheap.h"

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

template <typename T>
class PriorityQueue : public Queue<T> {
public:
    PriorityQueue() : mHeap(DEFAULT_HEAP_SIZE), max_size{DEFAULT_HEAP_SIZE} {}
    PriorityQueue(const uint64_t& max_size) : mHeap(max_size), max_size{max_size} {}

    void enqueue(const T& item) {
        mHeap.add(item);
    }

    T dequeue() {
        return mHeap.remove();
    }

    T front() const {
        return mHeap.root();
    }

    bool empty() const {
        return mHeap.size() == 0;
    }

    void clear() {
        mHeap.clear();
    }

    uint64_t maxSize() {
        return max_size;
    }

private:
    MinHeap<T> mHeap;
    uint64_t max_size;
};

#endif  /* PRIORITYQUEUE_H */