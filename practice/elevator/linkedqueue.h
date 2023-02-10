#include "queue.h"
#include "node.h"

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

template <typename T>
class LinkedQueue : public Queue<T> {
public:
    LinkedQueue() : frontPtr{nullptr}, backPtr{nullptr} {}

    void enqueue(const T& item) {
        Node<T>* newNode{new Node<T>(item)};

        if (empty())
            frontPtr = newNode;
        else
            backPtr->next = newNode;

        backPtr = newNode;
    }

    T dequeue() {
        T item;
        Node<T>* tempPtr{frontPtr};

        if (empty())
            throw std::runtime_error("The queue is empty!");

        item = frontPtr->item;
        frontPtr = frontPtr->next;
        delete tempPtr;

        if (frontPtr == nullptr)
            backPtr = nullptr;

        return item;
    }

    T front() const {
        return frontPtr->item;
    }

    bool empty() const {
        return backPtr == nullptr;
    }

    void clear() {
        Node<T>* tempPtr{frontPtr};

        while(!empty()) {
            frontPtr = frontPtr->next;
            delete tempPtr;
            tempPtr = frontPtr;
        }
        backPtr = nullptr;
    }

private:
    Node<T>* frontPtr;
    Node<T>* backPtr;
};

#endif  /* LINKEDQUEUE_H */