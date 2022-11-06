#include <iostream>

#include "bst.h"

#define TEST_VAL_1 10
#define TEST_VAL_2 15
#define TEST_VAL_3 20

void test_Add_Contains_Remove();

int main(int argc, char const *argv[])
{
    test_Add_Contains_Remove();

    return 0;
}

void test_Add_Contains_Remove()
{
    BinarySearchTree<int> bst;

    std::cout << (bst.empty() ? "SUCCEED: Tree is initially empty!\n" : "FAILED: Tree is not initially empty\n!");
    bst.add(TEST_VAL_1);
    std::cout << (bst.contains(TEST_VAL_1) ? "SUCCEED: Add\n" : "FAILED: Add\n");
    std::cout << (bst.remove(0) ? "SUCCEED: Remove\n" : "FAILED: Remove\n");

    bst.add(TEST_VAL_2);
    std::cout << (bst.contains(TEST_VAL_2) ? "SUCCEED: Add\n" : "FAILED: Add\n");
    bst.add(TEST_VAL_3);
    std::cout << (bst.contains(TEST_VAL_2) ? "SUCCEED: Add\n" : "FAILED: Add\n");
}