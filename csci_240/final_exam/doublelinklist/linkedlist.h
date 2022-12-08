#include <stdint.h>
#include <functional>

#include "node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<typename T>
class LinkedList
{
public:
    LinkedList(std::function<bool(T,T)> comparator) : head{nullptr}, tail{nullptr}, count{0} {}

    void insert(const T& item) {
        Node<T>* tmp = new Node<T>(item);
        Node<T>* itr;
        if (empty()) {
            head = tmp;
            ++count;
        }
        else {
            // itr = head;
            insert(item, head);
        }
    }

    bool remove(const T& item) {}

    bool contain(const T& item) {}

    bool empty() const noexcept {
        return count == 0;
    }

    void clear() {}
private:
    void insert(const T& item, Node<T>* itr) {
        if (comparator(itr->item, item)) {// itr->item > item
            
        }
    }

    Node<T>* head;
    uint64_t count;
    std::function<bool(T,T)>comparator;
};

#endif  /* LINKEDLIST_H */