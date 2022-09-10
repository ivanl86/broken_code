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
    LinkedQueue() : front{nullptr}, back{nullptr} {}

    // Takes an item as an argument and adds it to the collection at the back of the queue
    void enqueue(T item)
    {
        Node<T>* newNode{new Node<T>(item, nullptr)};

        if(isEmpty())
            front = newNode;
        else
            back->nextItem = newNode;
        
        back = newNode;
    }

    // Removes and returns the item at the front of the queue
    T dequeue()
    {
        Node<T> *frontQueue{front};
        T item;

        if (isEmpty())
            throw std::runtime_error("The queue is empty!");

        item = frontQueue->item;

        front = front->nextItem;

        delete frontQueue;

        return item;
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
        Node<T>* it{front};
        while(it != nullptr)
        {
            front = front->nextItem;
            delete it;
            it = front;
        }

        back = nullptr;
    }

private:
    Node<T> *front;
    Node<T> *back;
};

#endif  /* LINKEDQUEUE_H */