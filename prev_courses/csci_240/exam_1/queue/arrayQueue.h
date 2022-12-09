#include <stdexcept>

#include "queue.h"

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#define DEFAULT_SIZE 4
#define SCALING_FACTOR 2

template<typename T>
class ArrayQueue : public Queue<T>
{
public:
    ArrayQueue() : item{new T[DEFAULT_SIZE]}, frontIdx{0}, backIdx{-1}, currentCount{0}, currentSize{DEFAULT_SIZE} {}

    void enqueue(T newItem)
    {
        if (currentCount >= currentSize)
            resize();
        
        ++backIdx %= currentSize;
        item[backIdx] = newItem;
    }
private:
    T *item;
    int frontIdx;
    int backIdx;
    size_t currentCount;
    size_t currentSize;
};

#endif  /* ARRAYQUEUE_H */