#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include<stdexcept>

#include "queue.h"
#include "node.h"

template<typename T>
class LinkedQueue : public Queue<T>
{
public:
    LinkedQueue() : frontPtr{nullptr}, backPtr{nullptr}
    {}

    void enqueue(T item)
    {
        (empty() ? backPtr : backPtr->next) = new Node<T>(item);

        if (empty())
            frontPtr = backPtr;
        else
            backPtr = backPtr->next;
    }

    T dequeue()
    {
        Node<T> *temp{frontPtr};
        T returnItem;
    
        if (empty())
            throw std::runtime_error("Dequeue on empty Queue");

        returnItem = frontPtr->item;
        frontPtr = frontPtr.next;
        delete temp;

        if (empty())
            backPtr = nullptr;

        return returnItem;
    }

    T front()
    {
        if (empty())
            throw std::runtime_error("frontPtr on empty Queue");

        return frontPtr->item;
    }

    bool empty()
    { return frontPtr == nullptr; }

    void clear()
    {
        Node<T> temp{frontPtr};
        while(frontPtr != nullptr)
        {
            frontPtr = frontPtr->next;
            delete temp;
            temp = frontPtr;
        }
        backPtr = nullptr;
    }

private:
    Node<T> *frontPtr;
    Node<T> *backPtr;
};

#endif  /* LINKED_QUEUE_H */