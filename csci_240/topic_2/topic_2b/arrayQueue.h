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
    // ArrayQueue constructor
    // creates an array of Queue on the heap with the DEFAULT_SIZE, 8
    // initialize front and currentCount to zero
    // initialize back to -1
    // initialize currentSize to DEFAULT_SIZE, 8
    ArrayQueue() : inQueue{new T[DEFAULT_SIZE]}, front{0}, back{-1},
                   currentCount{0}, currentSize{DEFAULT_SIZE} {}

    // Takes an item as an argument and adds it to the collection at the back of the queue
    void enqueue(T item)
    {
        if (currentCount >= currentSize)
            resize();
        
        if (back >= currentSize - 1)
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

    // Removes and returns the item at the front of the queue
    T dequeue()
    {
        T frontQueue{inQueue[front]};

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

        return frontQueue;
    }

    // Returns the item at the front of the queue but does not remove it
    T getFront()
    {
        if (isEmpty())
            throw std::runtime_error("The queue is empty!");

        return inQueue[front];
    }

    // Returns true if the queue is empty or false otherwise
    bool isEmpty()
    { return currentCount <= 0; }

    // Removes all items from the queue
    void clear()
    {
        currentCount = 0;
        front = 0;
        back = -1;
    }

private:
    T *inQueue;
    size_t front;
    int back;
    size_t currentCount;
    size_t currentSize;

    // Resize the arrayQueue by multipling the currentSize with the SCALING_FACTOR
    // when a new item to be enqueued will exceed the currentSize
    void resize()
    {
        currentSize *= SCALING_FACTOR;
        T *newQueue{new T[currentSize]};

        for(size_t i{0}; i < (currentSize / SCALING_FACTOR); ++i)
                newQueue[i] = inQueue[++back % (currentSize / SCALING_FACTOR)];       

        delete[] inQueue;
        inQueue = newQueue;
        front = 0;
        back = currentCount - 1;
    }
};

#endif  /* ARRAYQUEUE_H */