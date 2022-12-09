#include <cstddef>

#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class Queue
{
public:
    // Queue constructor
    Queue() {}

    // All Queue functions are pure virtual and will be overriden in the derived class

    // Takes an item as an argument and adds it to the collection at the back of the queue
    virtual void enqueue(T item) = 0;

    // Removes and returns the item at the front of the queue
    virtual T dequeue() = 0;

    // Returns the item at the front of the queue but does not remove it
    virtual T getFront() = 0;

    // Returns true if the queue is empty or false otherwise
    virtual bool isEmpty() = 0;

    // Removes all items from the queue
    virtual void clear() = 0;

private:
};



#endif  /* QUEUE_H */