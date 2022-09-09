#include <stdexcept>

#include "queue.h"
#include "node.h"

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

template<typename T>
class LinkedQueue: public Queue<T>
{
public:
    // Queue constructor
    LinkedQueue() : front{nullptr} {}

    // Takes an item as an argument and adds it to the collection at the back of the queue
    void enqueue(T item)
    {
        front = new Node<T>(item, front);
    }

    // Removes and returns the item at the front of the queue
    T dequeue()
    {
        Node<T> *frontQueue{front};

        if (isEmpty())
            throw std::runtime_error("The queue is empty!");
    
        front = front->nextItem;
        return frontQueue->item;
    }

    // Returns the item at the front of the queue but does not remove it
    T getFront()
    {
        if (isEmpty())
            throw std::runtime_error("The queue is empty!");

        return front->item;
    }

    // Returns true if the queue is empty or false otherwise
    bool isEmpty()
    { return front == nullptr; }

    // Removes all items from the queue
    void clear()
    {
        front == nullptr;
    }

private:
    Node<T> *front;
};

#endif  /* LINKEDQUEUE_H */