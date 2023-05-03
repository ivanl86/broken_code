#include <iostream>

#include "doublylinkedlist.h"

int main(int argc, char const *argv[])
{
    DoublyLinkedList<int> dlist;
    dlist.pushBack(1);
    dlist.pushFront(5);
    dlist.insert(1, 8);
    dlist.insert(3, 2);
    dlist.insert(0, 9);
    dlist.pushFront(7);
    dlist.pushBack(4);

    std::cout << (dlist.contains(3) ? "True" : "False") << "\n";

    while (!dlist.empty())
    {
        std::cout << " " << dlist.front();
        dlist.popFront();
    }

    std::cout << "\n";

    dlist.pushBack(1);
    dlist.pushFront(5);
    dlist.insert(1, 8);
    dlist.insert(3, 2);
    dlist.insert(0, 9);
    dlist.pushFront(7);
    dlist.pushBack(4);

    std::cout << (dlist.contains(5) ? "True" : "False") << "\n";

    while (!dlist.empty())
    {
        std::cout << " " << dlist.back();
        dlist.popBack();
    }

    std::cout << "\n";

    dlist.pushBack(1);
    dlist.pushFront(5);
    dlist.insert(1, 8);
    dlist.insert(3, 2);
    dlist.insert(0, 9);
    dlist.pushFront(7);
    dlist.pushBack(4);

    for (size_t i = 0; i < 10; ++i)
    {
        std::cout << i << " ";
        std::cout << (dlist.erase((int)i) ? "Erased\n" : "Not in the List\n");
    }

    return 0;
}
