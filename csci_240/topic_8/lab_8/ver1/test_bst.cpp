#include <iostream>

#include "bst.h"

#define TEST_VAL_0 100
#define TEST_VAL_1 10
#define TEST_VAL_2 15
#define TEST_VAL_3 20
#define TEST_VAL_4 5
#define TEST_VAL_5 0

void test_Add_Contains_Remove();

int main(int argc, char const *argv[])
{
    test_Add_Contains_Remove();

    return 0;
}

void test_Add_Contains_Remove()
{
    BinarySearchTree<int> bst;

    std::cout << "START: test_Add_Contains_Remove\n";

    std::cout << (bst.empty() ? "SUCCEED: Tree is initially empty!\n" : "FAILED: Tree is not initially empty\n!");

    bst.add(TEST_VAL_1);
    bst.add(TEST_VAL_2);
    bst.add(TEST_VAL_3);
    bst.add(TEST_VAL_4);
    bst.add(TEST_VAL_5);

    std::cout << (bst.contains(TEST_VAL_0) ? "SUCCEED: Added " : "FAILED: Added ") << TEST_VAL_0 << "\n";

    std::cout << (bst.contains(TEST_VAL_1) ? "SUCCEED: Added " : "FAILED: Added ") << TEST_VAL_1 << "\n";
    std::cout << (bst.contains(TEST_VAL_2) ? "SUCCEED: Added " : "FAILED: Added ") << TEST_VAL_2 << "\n";
    std::cout << (bst.contains(TEST_VAL_3) ? "SUCCEED: Added " : "FAILED: Added ") << TEST_VAL_3 << "\n";
    std::cout << (bst.contains(TEST_VAL_4) ? "SUCCEED: Added " : "FAILED: Added ") << TEST_VAL_4 << "\n";
    std::cout << (bst.contains(TEST_VAL_5) ? "SUCCEED: Added " : "FAILED: Added ") << TEST_VAL_5 << "\n";

    std::cout << "Before clear: Currently contains " << bst.size() << " item(s)\n";

    // std::cout << (bst.remove(TEST_VAL_1) ? "SUCCEED: Removed " : "FAILED: Removed ") << TEST_VAL_1 << "\n";
    // std::cout << (bst.remove(TEST_VAL_2) ? "SUCCEED: Removed " : "FAILED: Removed ") << TEST_VAL_2 << "\n";
    // std::cout << (bst.remove(TEST_VAL_5) ? "SUCCEED: Removed " : "FAILED: Removed ") << TEST_VAL_5 << "\n";
    bst.clear();

    std::cout << "After clear: Currently contains " << bst.size() << " item(s)\n";
}