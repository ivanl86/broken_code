#include <stdint.h>
#include <stdexcept>

#include "node.h"

#ifndef DEQUE_H
#define DEQUE_H

template<typename T>
class Deque
{
public:
    Deque() : front{nullptr}, back{nullptr} {}

    void pushFront(const T& item) {
        Node<T>* tmp = new Node<T>(item);

        if (isEmpty()) {
            front = tmp;
            back = front;
        }
        else {
            front->prev = tmp;
            tmp->next = front;
            front = tmp;
        }
    }

    void pushBack(const T& item) {
        Node<T>* tmp = new Node<T>(item);

        if (isEmpty()) {
            back = tmp;
            front = back;
        }
        else {
            back->next = tmp;
            tmp->prev = back;
            back = tmp;
        }
    }

    T popFront() {
        Node<T>* tmp;
        T item;

        if (isEmpty())
            throw std::runtime_error("Pop on empty queue");

        tmp = front;
        item = front->item;
        front = front->next;
        delete tmp;

        if (front != nullptr)
            front->prev = nullptr;

        return item;
    }

    T popBack() {
        Node<T>* tmp;
        T item;

        if (isEmpty())
            throw std::runtime_error("Pop on empty queue");

        tmp = back;
        item = back->item;
        back = back->prev;
        delete tmp;

        if (back != nullptr)
            back->next = nullptr;

        return item;
    }

    T getFront() {
        return front->item;
    }

    T getBack() {
        return back->item;
    }

    bool isEmpty() {
        return (front == nullptr || back == nullptr);
    }

    void clear() {
        Node<T>* tmp;

        if (isEmpty())
            throw std::runtime_error("Pop on empty queue");

        while (!isEmpty()) {
            tmp = front;
            front = front->next;
            delete tmp;
        }
        back = nullptr;
    }

private:
    Node<T>* front;
    Node<T>* back;
};

#endif  /* DEQUE_H */