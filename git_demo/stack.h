#include <stdexcept>

#ifndef STACK_H
#define STACK_H

template<typename T>
struct Node
{
    T item;
    Node<T>* next;
};

template<typename T>
class Stack
{
public:
    Stack() : head{nullptr} {}

    void push(const T& item) {
        head = new Node<T>{item, head};
    }

    void pop() {
        if (empty())
            throw std::runtime_error("Pop on empty stack");

        Node<T>* tmp = head;
        head->next;
        delete tmp;
    }

    T peek() {
        if (empty())
            throw std::runtime_error("Peek on empty stack");

        return head->item;
    }

    bool empty() {
        return head == nullptr;
    }
private:
    Node<T>* head;
};

#endif  /* STACK_H */