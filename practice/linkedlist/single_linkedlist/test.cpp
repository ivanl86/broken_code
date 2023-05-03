#include <iostream>

#include "forwardlist.h"

int main(int argc, char const *argv[])
{
    ForwardList<int> list;
    list.pushBack(1);
    list.pushFront(5);
    list.insert(1, 8);
    list.insert(3, 2);
    list.insert(0, 9);
    list.pushFront(7);
    list.pushBack(4);

    std::cout << (list.contains(3) ? "True" : "False") << "\n";

    while (!list.empty())
    {
        std::cout << " " << list.front();
        list.popFront();
    }

    std::cout << "\n";

    list.pushBack(1);
    list.pushFront(5);
    list.insert(1, 8);
    list.insert(3, 2);
    list.insert(0, 9);
    list.pushFront(7);
    list.pushBack(4);

    std::cout << (list.contains(5) ? "True" : "False") << "\n";

    while (!list.empty())
    {
        std::cout << " " << list.back();
        list.popBack();
    }

    std::cout << "\n";

    list.pushBack(1);
    list.pushFront(5);
    list.insert(1, 8);
    list.insert(3, 2);
    list.insert(0, 9);
    list.pushFront(7);
    list.pushBack(4);

    for (size_t i = 0; i < 10; ++i)
    {
        std::cout << i << " ";
        std::cout << (list.erase((int) i) ? "Erased\n" : "Not in the List\n");
    }

    return 0;
}
