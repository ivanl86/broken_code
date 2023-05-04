#include <stdint.h>
#include <stdexcept>

#include "node.h"

#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

template <typename T>
class DoublyLinkedList
{
public:
    DoublyLinkedList() : head{nullptr}, tail{nullptr}, count{0}
    {}

    void pushFront(const T& item)
    {
        Node<T>* newNode = new Node<T>(item);

        if (empty())
            head = tail = newNode;
        else
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        ++count;
    }

    void pushBack(const T& item)
    {
        Node<T>* newNode = new Node<T>(item);

        if (empty())
            tail = head = newNode;
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = tail->next;
        }
        ++count;
    }

    void insert(const uint64_t& pos, const T& item)
    {
        Node<T>* newNode{nullptr};
        Node<T>* itr{nullptr};

        if (pos > size())
            throw std::runtime_error("Out of bounds!");

        if (pos == 0)
            pushFront(item);
        else if (pos == size())
            pushBack(item);
        else
        {
            newNode = new Node<T>(item);
            itr = (pos <= size() / 2) ? findForward(pos) : findBackward(pos);
            itr->prev->next = newNode;
            newNode->prev = itr->prev;
            newNode->next = itr;
            itr->prev = newNode;
            ++count;
        }
    }

    void popFront()
    {
        Node<T>* tmp{nullptr};

        if (empty())
            throw std::runtime_error("Empty List!");

        tmp = head;
        head = head->next;

        (head == nullptr) ? tail = head : head->prev = nullptr;

        delete tmp;
        --count;
    }

    void popBack()
    {
        Node<T>* tmp{nullptr};

        if (empty())
            throw std::runtime_error("Empty List!");

        tmp = tail;
        tail = tail->prev;

        (tail == nullptr) ? head = tail : tail->next = nullptr;

        delete tmp;
        --count;
    }

    T erase(const uint64_t& pos)
    {
        Node<T>* tmp{nullptr};
        Node<T>* itr{nullptr};
        T item{};

        if (empty())
            throw std::runtime_error("Empty List!");

        if (pos == 0)
            popFront();
        else if (pos == size())
            popBack();
        else
        {
            itr = (pos <= size() / 2) ? findForward(pos) : findBackward(pos);
            tmp = itr;
            item = tmp->item;
            itr->prev->next = itr->next;
            itr->next->prev = itr->prev;
            delete tmp;
            --count;
            return item;
        }
    }

    bool erase(const T& item)
    {
        Node<T>* tmp{nullptr};
        Node<T>* itr{nullptr};

        if (empty())
            throw std::runtime_error("Empty List!");

        if (head->item == item)
        {
            popFront();
            return true;
        }

        itr = head;
        while (itr != nullptr)
        {
            if (itr->item == item)
            {
                tmp = itr;
                itr->prev->next = itr->next;

                if (itr->next != nullptr)
                    itr->next->prev = itr->prev;

                delete tmp;
                --count;
                return true;
            }
            else
                itr = itr->next;
        }

        return false;
    }

    T front() const
    {
        return head->item;
    }

    T back() const
    {
        return tail->item;
    }

    bool contains(const T& item)
    {
        if (empty())
            throw std::runtime_error("Empty List!");

        if (head == nullptr)
            return false;
        
        return (head->item == item) ? true : contains(item, head->next);
    }

    bool empty() const
    {
        return count == 0;
    }

    uint64_t size() const
    {
        return count;
    }

    void clear()
    {
        Node<T>* tmp{nullptr};

        if (empty())
            throw std::runtime_error("Empty List!");

        while (!empty())
        {
            tmp = head;
            head = head->next;
            delete tmp;
            --count;
        }

        tail = head;
    }
private:
    Node<T>* head;
    Node<T>* tail;
    uint64_t count;

    bool contains(const T& item, const Node<T>* itr)
    {
        if (itr == nullptr)
            return false;

        return (itr->item == item) ? true : contains(item, itr->next);
    }

    Node<T>* findForward(uint64_t pos)
    {
        Node<T>* itr{head};

        while (pos > 0)
        {
            itr = itr->next;
            --pos;
        }

        return itr;
    }

    Node<T>* findBackward(uint64_t pos)
    {
        Node<T>* itr{head};

        while (pos > 0)
        {
            itr = itr->prev;
            --pos;
        }

        return itr;
    }
};


#endif  /* DOUBLYLINKLIST_H */