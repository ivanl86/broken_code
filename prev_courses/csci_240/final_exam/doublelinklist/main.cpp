#include <iostream>
#include <ctime>

#include "circularlinkedlist.h"

#define TESTVAL_1 88
#define TESTVAL_2 68
#define TESTVAL_3 76
#define TESTVAL_4 18
#define TESTVAL_5 11

#define ARRAY_SZ 10

void test_Insert_Contain_Remove();
void test_Random_Insert_Contain_Remove();
void test_Random_Insert_Clear();
uint64_t rng(const uint64_t, const uint64_t);

int main(int argc, char const *argv[])
{
    srand(static_cast<uint64_t>(time(NULL)));

    test_Insert_Contain_Remove();
    std::cout << "\n";
    test_Random_Insert_Contain_Remove();
    std::cout << "\n";
    test_Random_Insert_Clear();
    return 0;
}

void test_Insert_Contain_Remove()
{
    CircularLinkedList<int> list;

    std::cout << "START: test_Insert_Contain_Remove\n";
    std::cout << "List is initially " << (list.empty() ? "" : "not ") << "empty\n";

    list.insert(TESTVAL_1);
    list.insert(TESTVAL_2);
    list.insert(TESTVAL_3);

    std::cout << "List is " << (list.empty() ? "" : "not ") << "empty after insert\n";
    std::cout << "List contains " << list.size() << " item(s)\n";

    std::cout << "List does " << (list.contain(TESTVAL_2) ? "" : "not ") << "contain " << TESTVAL_2 << "\n";
    std::cout << "List does " << (list.contain(TESTVAL_4) ? "" : "not ") << "contain " << TESTVAL_4 << "\n";

    std::cout << TESTVAL_1 << " is " << (list.remove(TESTVAL_1) ? "" : "not ") << "removed\n";
    std::cout << TESTVAL_2 << " is " << (list.remove(TESTVAL_2) ? "" : "not ") << "removed\n";
    std::cout << TESTVAL_3 << " is " << (list.remove(TESTVAL_3) ? "" : "not ") << "removed\n";

    std::cout << "List is " << (list.empty() ? "" : "not ") << "empty after remove\n";
    std::cout << "List contains " << list.size() << " item(s)\n";

    std::cout << "END: test_Insert_Contain_Remove\n";
}

void test_Random_Insert_Contain_Remove()
{
    CircularLinkedList<int> list;
    uint64_t array[] {
        rng(1,1000),rng(1,1000),rng(1,1000),rng(1,1000),rng(1,1000),
        rng(1,1000),rng(1,1000),rng(1,1000),rng(1,1000),rng(1,1000)
    };
    bool marks[ARRAY_SZ] {};
    uint64_t count{0};
    uint64_t random{0};

    std::cout << "START: test_Random_Insert_Contain_Remove\n";
    std::cout << "List is initially " << (list.empty() ? "" : "not ") << "empty\n";

    for(size_t i{0}; i < ARRAY_SZ; ++i) {
        list.insert(array[i]);
    }

    std::cout << "List is " << (list.empty() ? "" : "not ") << "empty after insert\n";
    std::cout << "List contains " << list.size() << " item(s)\n";

    std::cout << "Array contains: { ";
    for(size_t i{0}; i < ARRAY_SZ; ++i)
        std::cout << array[i] << " ";
    std::cout << "}\n";

    std::cout << "Removed: { ";
    while (count < ARRAY_SZ) {
        random = rng(0, ARRAY_SZ);
        if (!marks[random]) {
            if (list.remove(array[random])) {
                std::cout << array[random] << " ";
                marks[random] = true;
            }
            ++count;
        }
    }
    std::cout << "}\n";

    std::cout << "List is " << (list.empty() ? "" : "not ") << "empty after remove\n";
    std::cout << "List contains " << list.size() << " item(s)\n";

    std::cout << "END: test_Random_Insert_Contain_Remove\n";
}

void test_Random_Insert_Clear()
{
    CircularLinkedList<int> list;
    uint64_t array[] {
        rng(1,1000),rng(1,1000),rng(1,1000),rng(1,1000),rng(1,1000),
        rng(1,1000),rng(1,1000),rng(1,1000),rng(1,1000),rng(1,1000)
    };

    std::cout << "START: test_Random_Insert_Clear\n";
    std::cout << "List is initially " << (list.empty() ? "" : "not ") << "empty\n";

    for(size_t i{0}; i < ARRAY_SZ; ++i) {
        list.insert(array[i]);
    }

    std::cout << "List is " << (list.empty() ? "" : "not ") << "empty after insert\n";
    std::cout << "List contains " << list.size() << " item(s)\n";

    std::cout << "Array contains: { ";
    for(size_t i{0}; i < ARRAY_SZ; ++i)
        std::cout << array[i] << " ";
    std::cout << "}\n";

    list.clear();

    std::cout << "List not contain: { ";
    for(size_t i{0}; i < ARRAY_SZ; ++i)
    {
        if (!list.contain(array[i]))
            std::cout << array[i] << " ";
    }
    std::cout << "}\n";

    std::cout << "List is " << (list.empty() ? "" : "not ") << "empty after clear\n";
    std::cout << "List contains " << list.size() << " item(s)\n";

    std::cout << "END: test_Random_Insert_Contain_Remove\n";
}

uint64_t rng(const uint64_t start, const uint64_t end)
{
    return rand() % (end - start) + start;
}