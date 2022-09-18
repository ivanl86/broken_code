#include <stdexcept>

#include "node.h"
#include "queue.h"

#ifndef DEQUE_H
#define DEQUE_H

template<typename T>
class Deque : public Queue<T>
{
public:
    Deque() : frontPtr{nullptr}, backPtr{nullptr} {}

    void enqueueFront(T item)
    {
        (isEmpty() ? frontPtr : frontPtr->previous) = new Node<T>(item);
        (isEmpty() ? backPtr = frontPtr : frontPtr = frontPtr->previous);
    }

    void enqueueBack(T item)
    {
        (isEmpty() ? backPtr : backPtr->next) = new Node<T>(item);
        (isEmpty() ? frontPtr = backPtr : backPtr = backPtr->next);
//        if (frontPtr == backPtr)
//        {
//            frontPtr->next = backPtr;
//            backPtr->previous = frontPtr;
//        }
    }

    T dequeueFront()
    {
        if (isEmpty())
            throw std::runtime_error("Dequeue from empty Deque");
        
        Node<T> *tempPtr{frontPtr};
        T tempItem{frontPtr->item};

        frontPtr = frontPtr->next;
        delete tempPtr;

        return tempItem;
    }

    T dequeueBack()
    {
        if (isEmpty())
            throw std::runtime_error("Dequeue from empty Deque");
        
        Node<T> *tempPtr{backPtr};
        T tempItem{backPtr->item};

        backPtr = backPtr->previous;
        delete tempPtr;

        return tempItem;
    }

    T getFront()
    { return (isEmpty() ? throw std::runtime_error("Get from empty Qeque") : frontPtr->item); }

    T getBack()
    { return (isEmpty() ? throw std::runtime_error("Get from empty Qeque") : backPtr->item); }

    bool isEmpty()
    { return (frontPtr == nullptr || backPtr == nullptr); }

    void clearQueue()
    {
        Node<T> *tempPtr{frontPtr};
        while (!isEmpty())
        {
            frontPtr == frontPtr->next;
            delete tempPtr;
            tempPtr == frontPtr;
        }
        backPtr == nullptr;
    }

private:
    Node<T> *frontPtr;
    Node<T> *backPtr;
};

#endif  /* DEQUE_H */