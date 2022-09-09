#include <stdexcept>
#include "queue.h"

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#define DEFAULT_SIZE 8
#define SCALING_FACTOR 2

template<typename T>
class ArrayQueue : public Queue<T>
{
public:
    // creates an array of Queue on the heap with the DEFAULT_SIZE, 8
    // initialize front and currentCount to zero
    // initialize back to -1
    // initialize currentSize to DEFAULT_SIZE, 8
    ArrayQueue() : inQueue{new T[DEFAULT_SIZE]}, front{0}, back{-1},
                   currentCount{0}, currentSize{DEFAULT_SIZE} {}

    void enqueue(T item)
    {
        if (currentCount >= currentSize)
            resize();
        
        if (back == currentSize - 1)
        {
            back = 0;
            inQueue[back] = item;
            ++currentCount;
        }
        else
        {
            inQueue[++back] = item;
            ++currentCount;
        }

    }

    T dequeue()
    {
        T temp{inQueue[front]};

        if (isEmpty())
            throw std::runtime_error("The queue is empty!");
        
        if (front >= currentSize -1)
        {
            front = 0;
            --currentCount;
        }
            
        else
        {
            ++front;
            --currentCount;
        }

        return temp;
    }

    T getFront()
    {
        if (isEmpty())
            throw std::runtime_error("The queue is empty!");

        return inQueue[front];
    }

    bool isEmpty()
    {
        if (currentCount <= 0)
            return true;
        return false;
    }

    void clear()
    {
        currentCount = 0;
        front = 0;
        back = 0;
    }

private:
    T *inQueue;
    size_t front;
    int back;
    size_t currentCount;
    size_t currentSize;

    void resize()
    {
        size_t previousSize{currentSize};
        T *newQueue{new T[currentSize]};
        currentSize *= SCALING_FACTOR;

        if (back < front)
        {
            for(size_t i{0}; front + i < previousSize; ++i)
                newQueue[i] = inQueue[front + i];
            for(size_t i{0}; i <= back; ++i)
                newQueue[(front - back + 1) + i] = inQueue[i];
        }
        else
            for(size_t i{0}; i < previousSize; ++i)
                newQueue[i] = inQueue[i];

        inQueue = newQueue;
        front = 0;
        back = currentCount - 1;
    }
};

#endif  /* ARRAYQUEUE_H */