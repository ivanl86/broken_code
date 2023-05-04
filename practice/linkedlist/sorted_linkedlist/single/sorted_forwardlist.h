#include <stdint.h>
#include <stdexcept>

#include "node.h"

#ifndef SORTED_FORWARDLIST_H
#define SORTED_FORWARDLIST_H

template <typename T>
class SortedForwardList
{
public:
    /** SortedForwardList constructor.
     *  Initializes head to nullptr and count to zero */
    SortedForwardList() : head{nullptr}, count {0}
    {}

    /** Inserts an item into list
     * @param item is the item to be inserted */
    void insert(const T& item)
    {
        Node<T>* newNode = new Node<T>(item);
        Node<T>* itr{nullptr};

        if (empty())
        {
            head = newNode;
            ++count;
        }
        else if (head->item > item)
        {
            newNode->next = head;
            head = newNode;
            ++count;
        }
        else
        {
            itr = findPrev(item);
            newNode->next = itr->next;
            itr->next = newNode;
            ++count;
        }
    }

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
            tmp = head;
            head = head->next;
            delete tmp;
            --count;
            return true;
        }
        else
        {
            itr = findPrevItem(item);
            if (itr != nullptr)
            {
                tmp = itr->next;
                itr->next = itr->next->next;
                delete tmp;
                --count;
                return true;
            }
        }

        return false;
    }

    /** Erases the item in the position pos
     * @param pos is the position where the item is to be erased
     * @returns the item in the position pos
     * @throws throws runtime_error if the list is empty or
     * position pos is out of bounds */
    T erase(const uint64_t& pos)
    {
        Node<T>* tmp{nullptr};
        Node<T>* itr{nullptr};
        T item{};

        if (empty())
            throw std::runtime_error("Empty List!");

        if (pos < 0 || pos >= size())
            throw std::runtime_error("Out of Bounds!");

        if (pos == 0)
        {
            tmp = head;
            item = tmp->item;
            head = head->next;
            delete tmp;
            --count;
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

    /** Returns the item in the front of the list
     * @returns the item in the fornt of the list
     * @throws throws runtime_error if the list is empty */
    T front() const
    {
        if (empty())
            throw std::runtime_error("Empty List!");

        return head->item;
    }

    bool contains(const T& item)
    {
        if (empty())
            throw std::runtime_error("Empty List!");

        return contains(item, head);
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
        if (empty())
            throw std::runtime_error("Empty List!");
    }

private:
    Node<T>* head;
    uint64_t count;

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

    /** Finds the previous node of the node to be inserted into the list
     * @param item is the search term
     * @returns itr is the previous node of the node to be inserted into the list */
    Node<T>* findPrev(const T& item)
    {
        Node<T>* itr{nullptr};

        itr = head;
        while (true)
        {
            if (itr->next == nullptr || itr->next->item >= item)
                return itr;
            else
                itr = itr->next;
        }
    }

    /** Finds the previous node of the node containing the search item
     * @param item is the search term
     * @returns itr is the previous node of the node containing the item,
     * otherwise nullptr */
    Node<T>* findPrevItem(const T& item)
    {
        Node<T>* itr{nullptr};

        itr = head;
        while (itr->next != nullptr)
        {
            if (itr->next->item == item)
                return itr;
            else
                itr = itr->next;
        }
        return nullptr;
    }
};

#endif  /* SORTED_FORWARDLIST_H */