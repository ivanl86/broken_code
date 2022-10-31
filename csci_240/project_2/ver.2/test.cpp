#include <iostream>
#include <ctime>

#include "skiplist.h"

#define TEST_VAL1 11
#define TEST_VAL2 21
#define TEST_VAL3 15
#define TEST_VAL4 19
#define TEST_VAL5 25

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
    sList.add(TEST_VAL1);
    sList.add(TEST_VAL2);
    sList.add(TEST_VAL3);
    sList.add(TEST_VAL4);
    sList.add(TEST_VAL5);
    std::cout << "Contians " << sList.size() << " items before remove\n";

    if (sList.contains(TEST_VAL4))
        std::cout << "SUCCEED: It contains " << TEST_VAL4 << "!\n";
    else
        std::cout << "FAILED: It does not contains " << TEST_VAL4 << "!\n";

    try
    { std::cout << sList.remove(TEST_VAL4) << " is being removed!\n"; }
    catch(const std::exception& e)
    { std::cerr << e.what() << '\n'; }

    if (sList.contains(TEST_VAL4))
        std::cout << "SUCCEED: It contains " << TEST_VAL4 << "!\n";
    else
        std::cout << "FAILED: It does not contains " << TEST_VAL4 << "!\n";

    std::cout << "Contians " << sList.size() << " items after remove\n";
}