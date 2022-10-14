#include <iostream>

#include "HashSetLP.h"

#define TEST_VAL_1 87

int h1(int);

void test_Insert_Contain_Find_Erase();

int main(int argc, char const *argv[])
{
    test_Insert_Contain_Find_Erase();
    return 0;
}

int h1(int n)
{
    return n;
}

void test_Insert_Contain_Find_Erase()
{
    LPSet<int> set(h1);

    if (!set.insert(TEST_VAL_1))
        std::cout << "FAILED: Insert\n";;

    if (!set.contains(TEST_VAL_1))
        std::cout << "FAILED: Contains\n";

    if (set.find(TEST_VAL_1) == nullptr)
        std::cout << "FAILED: Find\n";

    if (!set.erase(TEST_VAL_1))
        std::cout << "FAILED: Erase\n";
    
    if (set.contains(TEST_VAL_1))
        std::cout << "FAILED: Erase\n";

    std::cout << "SUCEEDED: test_Insert_Contain_Find_Erase\n";
}