#include <iostream>

#include "bst.h"

#define TEST_VAL1 10
#define TEST_VAL2 15

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
    bst.add(TEST_VAL1);
    std::cout << (bst.contains(TEST_VAL1) ? "SUCCEED: Add\n" : "FAILED: Add\n");
    bst.add(TEST_VAL2);
    std::cout << (bst.contains(TEST_VAL2) ? "SUCCEED: Add\n" : "FAILED: Add\n");
    // std::cout << (bst.remove(TEST_VAL1) ? "SUCCEED: Remove\n" : "FAILED: Remove\n");
}