#include <stdint.h>
#include <stdexcept>

#include "node.h"

#ifndef FORWARDLIST_H
#define FORWARDLIST_H

template <typename T>
class ForwardList
{
public:
    /** ForwardList constructor.
     *  Initializes head and tail to nullptr and count to zero */
    ForwardList() : head{nullptr}, tail{nullptr}, count{0}
    {}

    /** Inserts an item in the front of the list
     * @param item is the item to be inserted */
    void pushFront(const T& item)
    {
        Node<T>* newNode{new Node<T>(item)};

        newNode->next = head;
        head = newNode;

        if (empty())
            tail = head;

        ++count;
    }

    /** Inserts an item in the tail of the list
     * @param item is the item to be inserted */
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

    /** Inserts an item into the specified position
     * @param pos is the specified position
     * @param item is the item to be inserted
     * @throws throws runtime_error if position pos is out of bounds */
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
            itr = findPrev(pos);

            newNode->next = itr->next;
            itr->next = newNode;

            ++count;
        }
    }

    /** Erases the item in the front of the list
     * @throws throws runtime_error if the list is empty */
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

    /** Erases the item in the tail of the list
     * @throws throws runtime_error if the list is empty */
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

    /** Erases the item in the position pos
     * @param pos is the position where the item is to be erased
     * @returns the item in the position pos
     * @throws throws runtime_error if the list is empty or
     * position is out of bounds */
    T erase(const uint64_t& pos)
    {
        Node<T>* tmp{nullptr};
        Node<T>* itr{nullptr};
        T item{};

        if (empty())
            throw std::runtime_error("Empty List!");

        if (pos == 0)
        {
            item = front();
            popFront();
            return item;
        }
        else if (pos == size())
        {
            item = back();
            popBack();
            return item;
        }
        else
        {
            itr = findPrev(pos);
            tmp = itr->next;
            item = tmp->item;
            itr->next = itr->next->next;
            delete tmp;
            --count;
            return item;
        }
    }

    void erase(const uint64_t& start, const uint64_t& end)
    {}

    /** Erases the specified item in list
     * @param item is the item to be erased
     * @returns true if the item is found and erased, otherwise false
     * @throws throws runtime_error if the list is empty */
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

    /** Returns the item in the front of the list
     * @returns the item in the fornt of the list
     * @throws throws runtime_error if the list is empty */
    T front() const
    {
        if (empty())
            throw std::runtime_error("Empty List!");

        return head->item;
    }

    /** Returns the item in the back of the list
     * @returns the item in the back of the list
     * @throws throws runtime_error if the list is empty */
    T back() const
    {
        if (empty())
            throw std::runtime_error("Empty List!");

        return tail->item;
    }

    /** Checks if the list contains the item
     * @param item is the search term
     * @returns true if the item is found, otherwise false */
    bool contains(const T& item)
    {
        if (empty())
            throw std::runtime_error("Empty List!");

        return (head->item == item) ? true : contains(item, head->next);
    }

    /** Checks if the list is empty
     * @returns true if the list is empty, otherwise false */
    bool empty() const
    {
        return count == 0;
    }

    /** Returns the size of the list
     * @returns the number of items in the list */
    uint64_t size() const
    {
        return count;
    }

    /** Erases all items in the list
     * @throws throws runtime_error if the list is empty */
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

    /** Recursive function used by the public contains function
     * @param item is the search term
     * @param itr is the iterator
     * @returns true if the item is found, otherwise false */
    bool contains(const T& item, const Node<T>* itr)
    {
        if (itr == nullptr)
            return false;

        return (itr->item == item) ? true : contains(item, itr->next);
    }

    /** Finds the previous node of the specified position
     * @param pos is the specified position
     * @returns the previous node of the specified position */
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

    /** 
     * @param 
     * @returns 
     * @throws  */