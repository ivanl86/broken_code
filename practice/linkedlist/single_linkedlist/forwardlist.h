#include <stdint.h>
#include <stdexcept>

#include "node.h"

#ifndef FORWARDLIST_H
#define FORWARDLIST_H

template <typename T>
class ForwardList
{
public:
    ForwardList() : head{nullptr}, tail{nullptr}, count{0} {}

    void pushFront(const T& item)
    {
        Node<T>* newNode{new Node<T>(item)};

        newNode->next = head;
        head = newNode;

        if (empty())
            tail = head;

        ++count;
    }

    void pushBack(const T& item)
    {
        Node<T>* newNode{new Node<T>(item)};

        if (empty())
        {
            tail = newNode;
            head = tail;
        }
        else
        {
            tail->next = newNode;
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

        newNode = new Node<T>(item);
        itr = findPrev(pos);

        newNode->next = itr->next;
        itr->next = newNode;

        ++count;
    }

    void popFront()
    {
        Node<T>* tmp{nullptr};

        if (empty())
            throw std::runtime_error("Empty List!");

        tmp = head;
        head = head->next;

        if (head == nullptr)
            tail = head;

        delete tmp;
        --count;
    }

    void popBack()
    {
        Node<T>* tmp{nullptr};
        Node<T>* itr{nullptr};

        if (empty())
            throw std::runtime_error("Empty List!");
        
        tmp = tail;
        if (size() == 1)
            head = tail = nullptr;
        else
        {
            itr = findPrev(size() - 1);
            tail = itr;
        }

        delete tmp;
        --count;
    }

    void erase(const uint64_t& pos)
    {
        Node<T>* tmp{nullptr};
        Node<T>* itr{nullptr};

        if (empty())
            throw std::runtime_error("Empty List!");

        if (pos == 0)
            popFront();
        else if (pos == size())
            popBack();

        itr = findPrev(pos);
        tmp = itr->next;
        itr->next = itr->next->next;

        delete tmp;
        --count;
    }

    void erase(const uint64_t& start, const uint64_t& end)
    {}

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
        while (itr->next != nullptr)
            if (itr->next->item == item)
            {
                tmp = itr->next;
                itr->next = itr->next->next;
                delete tmp;
                --count;
                return true;
            }
            else
                itr = itr->next;

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

    Node<T>* findPrev(uint64_t pos)
    {
        Node<T>* prev{head};

        while (pos > 1)
        {
            prev = prev->next;
            --pos;
        }

        return prev;
    }
};


#endif  /* FORWARDLIST_H */