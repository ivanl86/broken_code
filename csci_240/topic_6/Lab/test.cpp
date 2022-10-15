#include <iostream>

#include "set.h"
#include "hashset_lp.h"
#include "hashset_qp.h"

#define TEST_VAL_1 87
#define TEST_VAL_2 7

int h1(int);

void test_LP_Insert_Contain_Find_Erase();
void test_LP_Multiple_Insert_Contain_Find_Erase();
void test_LP_Multiple_Same_Value();
void test_LP_Resize();

void test_QP_Insert_Contain_Find_Erase();
void test_QP_Multiple_Insert_Contain_Find_Erase();
void test_QP_Multiple_Same_Value();
void test_QP_Resize();

int main(int argc, char const *argv[])
{
    std::cout << "START: Testing Linear Probing\n";
    test_LP_Insert_Contain_Find_Erase();
    test_LP_Multiple_Insert_Contain_Find_Erase();
    test_LP_Multiple_Same_Value();
    test_LP_Resize();
    std::cout << "END: Testing Linear Probing\n";

    std::cout << '\n';

    std::cout << "START: Testing Quadratic Probing\n";
    test_QP_Insert_Contain_Find_Erase();
    test_QP_Multiple_Insert_Contain_Find_Erase();
    test_QP_Multiple_Same_Value();
    test_QP_Resize();
    std::cout << "END: Testing Quadratic Probing\n";

    return 0;
}

int h1(int k)
{
    return k;
}

void test_LP_Insert_Contain_Find_Erase()
{
    HashSetLP<int> set(h1);

    std::cout << "START: test_Insert_Contain_Find_Erase\n";

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

void test_LP_Multiple_Insert_Contain_Find_Erase()
{
    HashSetLP<int> set(h1);
    size_t itemQty{30};

    std::cout << "START: test_Multiple_Insert_Contain_Find_Erase\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (!set.insert(i))
            std::cout << "FAILED: Insert\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (!set.contains(i))
            std::cout << "FAILED: Contains\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (set.find(i) == nullptr)
            std::cout << "FAILED: Find\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (!set.erase(i))
            std::cout << "FAILED: Erase\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (set.contains(i))
            std::cout << "FAILED: Erase\n";

    std::cout << "SUCEEDED: test_Multiple_Insert_Contain_Find_Erase\n";
}

void test_LP_Multiple_Same_Value()
{
    HashSetLP<int> set(h1);
    size_t itemQty{8};

    std::cout << "START: test_Multiple_Same_Value\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (!set.insert(TEST_VAL_1))
            std::cout << "FAILED: Insert\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (!set.contains(TEST_VAL_1))
            std::cout << "FAILED: Contains\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (set.find(TEST_VAL_1) == nullptr)
            std::cout << "FAILED: Find\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (!set.erase(TEST_VAL_1))
            std::cout << "FAILED: Erase\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (set.contains(TEST_VAL_1))
            std::cout << "FAILED: Erase\n";

    std::cout << "SUCEEDED: test_Multiple_Same_Value\n";
}

void test_LP_Resize()
{
    HashSetLP<int> set(h1);
    size_t itemQty{180};

    std::cout << "START: test_Resize\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (!set.insert(i))
            std::cout << "FAILED: Insert\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (!set.contains(i))
            std::cout << "FAILED: Contains\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (set.find(i) == nullptr)
            std::cout << "FAILED: Find\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (!set.erase(i))
            std::cout << "FAILED: Erase\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (set.contains(i))
            std::cout << "FAILED: Erase\n";

    std::cout << "SUCEEDED: test_Resize\n";
}

void test_QP_Insert_Contain_Find_Erase()
{
    HashSetQP<int> set(h1);

    std::cout << "START: test_Insert_Contain_Find_Erase\n";

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

void test_QP_Multiple_Insert_Contain_Find_Erase()
{
    HashSetQP<int> set(h1);
    size_t itemQty{30};

    std::cout << "START: test_Multiple_Insert_Contain_Find_Erase\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (!set.insert(i))
            std::cout << "FAILED: Insert\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (!set.contains(i))
            std::cout << "FAILED: Contains\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (set.find(i) == nullptr)
            std::cout << "FAILED: Find\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (!set.erase(i))
            std::cout << "FAILED: Erase\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (set.contains(i))
            std::cout << "FAILED: Erase\n";

    std::cout << "SUCEEDED: test_Multiple_Insert_Contain_Find_Erase\n";
}

void test_QP_Multiple_Same_Value()
{
    HashSetQP<int> set(h1);
    size_t itemQty{8};

    std::cout << "START: test_Multiple_Same_Value\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (!set.insert(TEST_VAL_2))
            std::cout << "FAILED: Insert\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (!set.contains(TEST_VAL_2))
            std::cout << "FAILED: Contains\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (set.find(TEST_VAL_2) == nullptr)
            std::cout << "FAILED: Find\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (!set.erase(TEST_VAL_2))
            std::cout << "FAILED: Erase\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (set.contains(TEST_VAL_2))
            std::cout << "FAILED: Erase\n";

    std::cout << "SUCEEDED: test_Multiple_Same_Value\n";
}

void test_QP_Resize()
{
    HashSetQP<int> set(h1);
    size_t itemQty{180};

    std::cout << "START: test_Resize\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (!set.insert(i))
            std::cout << "FAILED: Insert\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (!set.contains(i))
            std::cout << "FAILED: Contains\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (set.find(i) == nullptr)
            std::cout << "FAILED: Find\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (!set.erase(i))
            std::cout << "FAILED: Erase\n";

    for(size_t i{1}; i <= itemQty; ++i)
        if (set.contains(i))
            std::cout << "FAILED: Erase\n";

    std::cout << "SUCEEDED: test_Resize\n";
}