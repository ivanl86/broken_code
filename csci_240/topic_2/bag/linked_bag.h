#include <stdexcept>

#include "bag.h"
#include "C:\Users\ivanl\OneDrive\Desktop\dev\broken_code\csci_240\topic_2\bag\node.h"

#ifndef LINKED_BAG_H
#define LINKED_BAG_H

template <typename T>
class LinkedBag : public Bag<T>
{
public:
    LinkedBag() : head{nullptr} {}

    bool add(T item)
    {
        head = new Node<T>(item, head);
        ++this->count;
        return true;
    }

    bool remove(T item)
    {
        Node<T> *iterator{findNode(item)};
        Node<T> *temp{head};

        if (iterator != nullptr)
        {
            iterator->item = head->item;
            head = head->children;
            delete temp;
            --this->count;
            return true;
        }
        return false;
    }

    bool contains(T item)
    {
        Node<T> *temp{head};
        while (temp != nullptr)
        {
            if (temp->item == item)
                return true;
            temp = temp->children;
        }
        return false;
    }

    size_t size()
    { return this->count; }

    T grab()
    {
        if (this->count == 0)
            throw std::runtime_error("Grab on empty bag!");
        return head->item;
    }


private:
    Node<T> *head;
    Node<T> *findNode(T item)
    {
        Node<T> *iterator{head};
        while (iterator != nullptr)
        {
            if (iterator->item == item)
                return iterator;
            iterator = iterator->children;
            
        }
        return nullptr;
    }
};

#endif  /* LINKED_BAG_H */