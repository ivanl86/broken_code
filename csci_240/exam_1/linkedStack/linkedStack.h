#include <stdexcept>

#include "node.h"

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

template<typename T>
class LinkedStack
{
public:
    LinkedStack() : head{nullptr} {}

    ~LinkedStack() { clear(); }
    
    void push(T item)
    { head = new Node<T>(item, head); }

    T peek()
    {
        if (empty())
            throw std::runtime_error("Peek on empty Stack");
        return head->item;
    }

    T pop()
    {
        if (empty())
            throw std::runtime_error("Pop on empty Stack");

        Node<T> *tempHead{head};
        T tempItem{head->item};

        head = head->next;

        delete tempHead;
        return tempItem;
    }

    bool empty()
    { return head == nullptr; }

    void clear()
    {
        
        while (!empty())
        {
            Node<T> *temp{head->next};
            delete head;
            head = temp;
        }
        
    }

private:
    Node<T> *head;


};


#endif  /* LINKEDSTACK_H */