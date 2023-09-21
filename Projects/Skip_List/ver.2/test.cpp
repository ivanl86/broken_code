#include <iostream>
#include <ctime>

#include "skiplist.h"

#define TEST_VAL1 11
#define TEST_VAL2 21
#define TEST_VAL3 15
#define TEST_VAL4 19
#define TEST_VAL5 25

void test_Add_Contains_Remove();
void test_Add_Size_Remove();

int main(int argc, char const *argv[])
{
    srand(static_cast<size_t>(time(NULL)));

    test_Add_Contains_Remove();
    std::cout << "\n";
    test_Add_Size_Remove();

    return 0;
}

void test_Add_Contains_Remove()
{
    Skiplist<int> sList([] (int l, int r) { return l > r; }); // ascending order

    std::cout << "START: test_Add_Contains_Remove\n";

    sList.add(TEST_VAL1);
    sList.add(TEST_VAL2);
    sList.add(TEST_VAL3);
    sList.add(TEST_VAL4);
    sList.add(TEST_VAL5);


    std::cout << "Contians " << sList.size() << " items before remove\n";

    std::cout << (sList.contains(TEST_VAL4) ? "SUCCEED: It contains " : "FAILED: It does not contains ") << TEST_VAL4 << "!\n"; 

    try
    { std::cout << sList.remove(TEST_VAL4) << " is being removed!\n"; }
    catch(const std::exception& e)
    { std::cerr << e.what() << '\n'; }

    std::cout << (sList.contains(TEST_VAL4) ? "SUCCEED: It contains " : "FAILED: It does not contains ") << TEST_VAL4 << "!\n"; 

    std::cout << "Contians " << sList.size() << " items after remove\n";
}

void test_Add_Size_Remove()
{
    Skiplist<int> sList([] (int l, int r) { return l > r; }); // descending order
    int array[] {TEST_VAL1,TEST_VAL3,TEST_VAL4,TEST_VAL2,TEST_VAL5};
    int i{0};

    std::cout << "START: test_Add_Size_Remove\n";

    sList.add(TEST_VAL1);
    sList.add(TEST_VAL2);
    sList.add(TEST_VAL3);
    sList.add(TEST_VAL4);
    sList.add(TEST_VAL5);

    while (sList.size() != 0)
    {
        try
        {
            std::cout << sList.remove(array[i]) << ' ';
            ++i;
        }
        catch(const std::exception& e)
        { std::cerr << e.what() << '\n'; }
    }
    std::cout << "\n";

    std::cout << (sList.size() != 0 ? "FAILED: It is not" : "SUCCEED: It is") << " empty";
}