#include <iostream>

#include "forwardlist.h"

int main(int argc, char const *argv[])
{
    ForwardList<int> list;
    list.pushBack(1);
    list.pushFront(5);
    list.insert(1, 8);
    std::cout << list.front() << "\n";
    list.popFront();
    std::cout << list.front() << "\n";
    std::cout << list.back() << "\n";
    return 0;
}
