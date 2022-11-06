#include <iostream>

#include "ordered_set.h"

#define TEST_VAL_0 100
#define TEST_VAL_1 40
#define TEST_VAL_2 15
#define TEST_VAL_3 20
#define TEST_VAL_4 5
#define TEST_VAL_5 0
#define TEST_VAL_6 30
#define TEST_VAL_7 35
#define TEST_VAL_8 50

void test_Insert_EraseItem_Empty_Clear();

int main(int argc, char const *argv[])
{
    test_Insert_EraseItem_Empty_Clear();
    return 0;
}

void test_Insert_EraseItem_Empty_Clear() {
    OrderedSet<int> set( [] (int l, int r) { return l > r; } );

    try {
        std::cout << "Set is initially " << (set.empty() ? "" : "not ") << "empty\n";
        std::cout << "Contains " << set.size() << " item(s) before Add\n";

        std::cout << (set.insert(TEST_VAL_1) ? "SUCCEED: Added " : "FAILED: Not added ") << TEST_VAL_1 << "\n";
        std::cout << (set.insert(TEST_VAL_2) ? "SUCCEED: Added " : "FAILED: Not added ") << TEST_VAL_2 << "\n";
        std::cout << (set.insert(TEST_VAL_3) ? "SUCCEED: Added " : "FAILED: Not added ") << TEST_VAL_3 << "\n";
        std::cout << (set.insert(TEST_VAL_4) ? "SUCCEED: Added " : "FAILED: Not added ") << TEST_VAL_4 << "\n";
        std::cout << (set.insert(TEST_VAL_5) ? "SUCCEED: Added " : "FAILED: Not added ") << TEST_VAL_5 << "\n";
        std::cout << (set.insert(TEST_VAL_6) ? "SUCCEED: Added " : "FAILED: Not added ") << TEST_VAL_6 << "\n";
        std::cout << (set.insert(TEST_VAL_7) ? "SUCCEED: Added " : "FAILED: Not added ") << TEST_VAL_7 << "\n";
        std::cout << (set.insert(TEST_VAL_8) ? "SUCCEED: Added " : "FAILED: Not added ") << TEST_VAL_8 << "\n";
        std::cout << (set.insert(TEST_VAL_1) ? "SUCCEED: Added " : "FAILED: Not added ") << TEST_VAL_1 << "\n";

        std::list<int>* orderedList = set.toSequence();

        std::cout << "Set is " << (set.empty() ? "" : "not ") << "empty after Add\n";
        std::cout << "Contains " << set.size() << " item(s) after Add\n";

        set.inorderTraversal();
        std::cout << "\n";

        std::cout << (set.erase(TEST_VAL_1) ? "SUCCEED: Erased " : "FAILED: Not erased ") << TEST_VAL_1 << "\n";
        std::cout << (set.erase(TEST_VAL_3) ? "SUCCEED: Erased " : "FAILED: Not erased ") << TEST_VAL_3 << "\n";

        std::cout << "Contains " << set.size() << " item(s) after Erase\n";

        set.inorderTraversal();
        std::cout << "\n";

        set.clear();

        std::cout << "Set is " << (set.empty() ? "" : "not ") << "empty after Clear\n";
        std::cout << "Contains " << set.size() << " item(s) after Clear\n";

        // while (!orderedList->empty())
        //     std::cout << orderedList->()
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
}

bool ascending = [] (int l, int r) { return l > r; };