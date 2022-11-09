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
void test_Insert_ErasePos_Empty_Clear();
void test_ToSequence_Merge();

int main(int argc, char const *argv[])
{
    test_Insert_EraseItem_Empty_Clear();
    std::cout << "\n";
    test_Insert_ErasePos_Empty_Clear();
    std::cout << "\n";
    test_ToSequence_Merge();
    return 0;
}

void test_Insert_EraseItem_Empty_Clear() { // Ascending Order
    OrderedSet<int> set( [] (int l, int r) { return l > r; } );
    uint64_t pos{4};

    std::cout << "START: test_Insert_EraseItem_Empty_Clear\n";
    for(size_t i{0}; i < 50; ++i)
        std::cout << "-";
    std::cout << "\n";

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

    std::cout << "Set is " << (set.empty() ? "" : "not ") << "empty after Add\n";
    std::cout << "Contains " << set.size() << " item(s) after Add\n";

    set.inorderTraversal();
    std::cout << "\n";

    std::cout << (set.erase(TEST_VAL_1) ? "SUCCEED: Erased " : "FAILED: Not erased ") << TEST_VAL_1 << "\n";
    std::cout << (set.erase(TEST_VAL_3) ? "SUCCEED: Erased " : "FAILED: Not erased ") << TEST_VAL_3 << "\n";
    std::cout << (set.erase(TEST_VAL_1) ? "SUCCEED: Erased " : "FAILED: Not erased ") << TEST_VAL_1 << "\n";

    set.inorderTraversal();
    std::cout << "\n";

    std::cout << "Contains " << set.size() << " item(s) after EraseItem\n";

    set.clear();

    std::cout << "Set is " << (set.empty() ? "" : "not ") << "empty after Clear\n";
    std::cout << "Contains " << set.size() << " item(s) after Clear\n";

    for(size_t i{0}; i < 50; ++i)
        std::cout << "-";
    std::cout << "\n";
    std::cout << "END: test_Insert_EraseItem_Empty_Clear\n";
}

void test_Insert_ErasePos_Empty_Clear() { // Descending Order
    OrderedSet<int> set( [] (int l, int r) { return l < r; } );
    uint64_t pos1{4};
    uint64_t pos2{9};

    std::cout << "START: test_Insert_EraseItem_Empty_Clear\n";
    for(size_t i{0}; i < 50; ++i)
        std::cout << "-";
    std::cout << "\n";

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

    std::cout << "Set is " << (set.empty() ? "" : "not ") << "empty after Add\n";
    std::cout << "Contains " << set.size() << " item(s) after Add\n";

    set.inorderTraversal();
    std::cout << "\n";

    std::cout << (set.erase(static_cast<uint64_t>(pos2)) ? "SUCCEED: Erased " : "FAILED: Not erased ") << "at position " << pos2 << "\n";

    set.inorderTraversal();
    std::cout << "\n";

    std::cout << (set.erase(static_cast<uint64_t>(pos1)) ? "SUCCEED: Erased " : "FAILED: Not erased ") << "at position " << pos1 << "\n";

    set.inorderTraversal();
    std::cout << "\n";

    std::cout << (set.erase(static_cast<uint64_t>(pos1)) ? "SUCCEED: Erased " : "FAILED: Not erased ") << "at position " << pos1 << "\n";

    set.inorderTraversal();
    std::cout << "\n";

    std::cout << "Contains " << set.size() << " item(s) after ErasePos\n";

    set.clear();

    std::cout << "Set is " << (set.empty() ? "" : "not ") << "empty after Clear\n";
    std::cout << "Contains " << set.size() << " item(s) after Clear\n";

    for(size_t i{0}; i < 50; ++i)
        std::cout << "-";
    std::cout << "\n";
    std::cout << "END: test_Insert_EraseItem_Empty_Clear\n";
}

void test_ToSequence_Merge()
{
    uint64_t array_sz{8};
    int arrayA[8]{90,45,78,101,99,12,199,123};
    int arrayB[8]{45,100,199,77,89,90,1,123};
    OrderedSet<int> setA( [] (int l, int r) { return l > r; } );
    OrderedSet<int> setB( [] (int l, int r) { return l > r; } );
    OrderedSet<int> setC( [] (int l, int r) { return l > r; } );
    OrderedSet<int> setD( [] (int l, int r) { return l > r; } );
    OrderedSet<int> setE( [] (int l, int r) { return l > r; } );
    std::list<int> list;

    std::cout << "START: test_ToSequence_Merge\n";
    for(size_t i{0}; i < 50; ++i)
        std::cout << "-";
    std::cout << "\n";

    for(size_t i{0}; i < array_sz; ++i) {
        setA.insert(arrayA[i]);
        setB.insert(arrayB[i]);
    }

    list = setA.toSequence();

    for (int l : list)
        std::cout << l << " ";
    std::cout << "\n";

    setC = OrderedSet<int>::merge(setA, setB, UNION);
    // setD = OrderedSet<int>::merge(setA, setB, INTERSECTION);
    // setE = OrderedSet<int>::merge(setA, setB, SUBTRACT);

    for(size_t i{0}; i < 50; ++i)
        std::cout << "-";
    std::cout << "\n";
    std::cout << "END: test_ToSequence_UnionSet_Intersection\n";
}