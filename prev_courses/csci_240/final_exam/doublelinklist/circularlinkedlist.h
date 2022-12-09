#include <stdexcept>
#include <cstdlib>

#include "node.h"

#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

template<typename T>
class CircularLinkedList
{
public:
    CircularLinkedList() : head{nullptr}, count{0} {}

    void insert(const T& item) {
        Node<T>* tmp{nullptr};
        if (count == 0) {
            head = new Node<T>(item);
            head->next = head;
        }
        else {
            tmp = new Node<T>(item, head->next);
            head->next = tmp;
        }
        ++count;
    }

    bool remove(const T& item) {
        uint64_t pass{0};

        if (count == 0)
            return false;

        while (pass < count) {
            if (head->next->item == item) {
                return remove();
            }
            else {
                head = head->next;
                ++pass;
            }
        }
        return false;
    }

    bool contain(const T& item) {
        uint64_t pass{0};

        if (count == 0)
            return false;

        while (pass < count) {
            if (head->item == item) {
                return true;
            }
            else {
                head = head->next;
                ++pass;
            }
        }
        return false;
    }

    uint64_t size() {
        return count;
    }

    bool empty() {
        return count == 0;
    }

    void clear() {
        Node<T>* tmp{nullptr};

        if (count == 0)
            throw std::runtime_error("Clear on empty list");

        while (count != 0) {
            tmp = head;
            head = head->next;
            delete tmp;
            --count;
        }
    }

private:
    bool remove() {
        Node<T>* tmp = head->next;

        head->next = head->next->next;
        --count;
        delete tmp;

        return true;
    }

    Node<T>* head;
    uint64_t count;
};

#endif  /* CIRCULARLINKEDLIST_H */