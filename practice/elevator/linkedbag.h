#include "node.h"
#include "bag.h"

#ifndef LINKEDBAG_H
#define LINKEDBAG_H

template <typename T>
class LinkedBag : public Bag<T> {
public:
    LinkedBag() : head{nullptr} {}

    bool add(const T& item) {
        head = new Node<T>(item, head);

        ++this->count;
        return true;
    }

    bool remove(const T& item) {
        Node<T>* iterator{head};
        Node<T>* temp;

        if (iterator == nullptr)
            return false;

        if (iterator->item == item) {
            temp = iterator;
            head = iterator->next;
            delete temp;
            return true;
        }

        while (iterator->next != nullptr) {
            if (iterator->next->item == item) {
                temp = iterator->next;
                iterator 
            }
        }
        
    }

    bool contains(const T& item) {
        Node<T>* iterator{head};

        while (iterator != nullptr) {
            if (iterator->item == item)
                return true;
            iterator = iterator->next;
        }
        return false;
    }

    T peek() const {
        return head->item;
    }

    uint64_t size() const {
        return this->count;
    }
private:
    Node<T>* head;

    Node<T>* grab(const T& item) {
        Node<T>* iterator{head};

        while(iterator != nullptr) {
            if (iterator->item == item)
                return iterator;
            iterator = iterator->next;
        }
        return nullptr;
    }
};

#endif  /* LINKEDBAG_H */