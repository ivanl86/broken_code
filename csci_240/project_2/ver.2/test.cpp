#include <iostream>
#include <ctime>

#include "skiplist.h"

void test_Add_Contains_Remove();

int main(int argc, char const *argv[])
{
    srand(static_cast<size_t>(time(NULL)));
    test_Add_Contains_Remove();

    return 0;
}

void test_Add_Contains_Remove()
{
    Skiplist<int> sList([] (int l, int r) { return l > r; }); // ascending order
    sList.add(10);
    sList.add(15);
    sList.add(20);
    sList.add(25);
    sList.add(5);
    std::cout << "Contians " << sList.size() << " items before remove\n";
    try
    {
        sList.remove(20);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if (sList.contains(20))
        std::cout << "SUCCEED: It contains!\n";
    else
        std::cout << "FAILED: It does not contains!\n";
    std::cout << "Contians " << sList.size() << " items after remove\n";
}