#include <iostream>

#include "sorted_forwardlist.h"

int main(int argc, char const *argv[])
{
    SortedForwardList<int> sfList;
    sfList.insert(5);
    sfList.insert(1);
    sfList.insert(9);
    sfList.insert(3);
    sfList.insert(6);

    std::cout << "Contains " << 2 << (sfList.contains(2) ? " : true\n" : " : false\n");

    while (!sfList.empty())
    {
        std::cout << sfList.erase((uint64_t) 0) << " ";
    }
    // std::cout << 5 << sfList.erase((int) 5) ? " Erased\n" : " Not found\n";
    return 0;
}
