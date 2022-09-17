#include <stdexcept>

#include "node.h"
#include "queue.h"

#ifndef DEQUE_H
#define DEQUE_H

template<typename T>
class Deque : public Queue
{
public:
    Deque() : frontPtr{nullptr}, backPtr{nullptr} {}

    void enqueueFront(T item)
    {
        (isEmpty() ? frontPtr : frontPtr->previous) = new Node<T>(item);
        (isEmpty() ? backPtr = frontPtr : frontPtr = frontPtr->previous);
    }
    


    bool isEmpty()
    { return (frontPtr == nullptr && backPtr == nullptr); }

private:
    Node<T> *frontPtr;
    Node<T> *backPtr;
};

#endif  /* DEQUE_H */