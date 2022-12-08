#include <iostream>
#include <cstdlib>
#include <ctime>

#include "deque.h"

#define TESTVAL_1 88
#define TESTVAL_2 68
#define TESTVAL_3 76
#define TESTVAL_4 18
#define TESTVAL_5 11

#define ARRAY_SZ 10

void test_Push_Get_Pop();
void test_Random_Push_Pop();
void test_Array_Push_Pop();
void test_Push_Clear();
uint64_t rng(const uint64_t, const uint64_t);

int main(int argc, char const *argv[])
{
    srand(static_cast<uint64_t>(time(NULL)));

    time_t curr_time;
    char *tm = ctime(&curr_time);
    std::cout << "Current Time is: " << tm << "\n";

    test_Push_Get_Pop();
    std::cout << "\n";
    test_Random_Push_Pop();
    std::cout << "\n";
    test_Array_Push_Pop();
    std::cout << "\n";
    test_Push_Clear();

    return 0;
}

void test_Push_Get_Pop()
{
    Deque<int> deque;

    std::cout << "START: test_Push_Get_Pop\n";
    std::cout << "Deque is initially " << (deque.isEmpty() ? "" : "not ") << "empty\n";

    deque.pushFront(TESTVAL_1);
    deque.pushFront(TESTVAL_2);
    deque.pushBack(TESTVAL_3);
    deque.pushBack(TESTVAL_4);
    deque.pushBack(TESTVAL_5);

    std::cout << "Deque is " << (deque.isEmpty() ? "" : "not ") << "empty after push\n";

    std::cout << "The item in the front is " << deque.getFront() << "\n";
    std::cout << "The item in the back is " << deque.getBack() << "\n";

    std::cout << "popFront: { ";
    while (!deque.isEmpty())
        std::cout << deque.popFront() << " ";
    std::cout << "}\n";

    std::cout << "Deque is " << (deque.isEmpty() ? "" : "not ") << "empty after pop\n";

    deque.pushFront(TESTVAL_1);
    deque.pushBack(TESTVAL_2);

    std::cout << "Deque is " << (deque.isEmpty() ? "" : "not ") << "empty after push\n";

    std::cout << "popBack: { ";
    while (!deque.isEmpty())
        std::cout << deque.popBack() << " ";
    std::cout << "}\n";

    std::cout << "END: test_Push_Get_Pop\n";
}

void test_Random_Push_Pop()
{
    Deque<int> deque;
    uint64_t array[] {rng(1,1000),rng(1,1000),rng(1,1000),rng(1,1000),rng(1,1000),
                      rng(1,1000),rng(1,1000),rng(1,1000),rng(1,1000),rng(1,1000)};

    std::cout << "START: test_Random_Push_Pop\n";
    std::cout << "Deque is initially " << (deque.isEmpty() ? "" : "not ") << "empty\n";

    for(size_t i{0}; i < ARRAY_SZ; ++i)
        static_cast<bool>(rng(0,1)) ? deque.pushFront(array[i]) : deque.pushBack(array[i]);

    std::cout << "Deque is " << (deque.isEmpty() ? "" : "not ") << "empty after push\n";

    std::cout << "Array contains: { ";
    for(size_t i{0}; i < ARRAY_SZ; ++i)
        std::cout << array[i] << " ";
    std::cout << "}\n";

    std::cout << "popFront: { ";
    for(size_t i{0}; i < ARRAY_SZ / 2; ++i)
        std::cout << deque.popFront() << " ";
    std::cout << "}\n";

    std::cout << "popBack: { ";
    while (!deque.isEmpty())
        std::cout << deque.popBack() << " ";
    std::cout << "}\n";

    std::cout << "Deque is " << (deque.isEmpty() ? "" : "not ") << "empty after pop\n";
    std::cout << "END: test_Random_Push_Pop\n";
}

void test_Array_Push_Pop()
{
    Deque<int> deque;
    uint64_t array[] {1,2,3,4,5,6,7,8,9,10};

    std::cout << "START: test_Array_Push_Pop\n";
    std::cout << "Deque is initially " << (deque.isEmpty() ? "" : "not ") << "empty\n";

    for(size_t i{0}; i < ARRAY_SZ; ++i)
        deque.pushFront(array[i]);

    std::cout << "Deque is " << (deque.isEmpty() ? "" : "not ") << "empty after push\n";

    std::cout << "popFront: { ";
    while (!deque.isEmpty())
        std::cout << deque.popFront() << " ";
    std::cout << "}\n";

    std::cout << "Deque is " << (deque.isEmpty() ? "" : "not ") << "empty after pop\n";

    for(size_t i{0}; i < ARRAY_SZ; ++i)
        deque.pushBack(array[i]);

    std::cout << "Deque is " << (deque.isEmpty() ? "" : "not ") << "empty after push\n";

    std::cout << "popBack: { ";
    while (!deque.isEmpty())
        std::cout << deque.popBack() << " ";
    std::cout << "}\n";

    std::cout << "Deque is " << (deque.isEmpty() ? "" : "not ") << "empty after pop\n";
    std::cout << "END: test_Array_Push_Pop\n";
}

void test_Push_Clear()
{
    Deque<int> deque;
    uint64_t array[] {1,2,3,4,5,6,7,8,9,10};

    std::cout << "START: test_Push_Clear\n";
    std::cout << "Deque is initially " << (deque.isEmpty() ? "" : "not ") << "empty\n";

    for(size_t i{0}; i < ARRAY_SZ; ++i)
        static_cast<bool>(rng(0,1)) ? deque.pushFront(array[i]) : deque.pushBack(array[i]);

    std::cout << "Deque is " << (deque.isEmpty() ? "" : "not ") << "empty after push\n";

    deque.clear();

    std::cout << "Deque is " << (deque.isEmpty() ? "" : "not ") << "empty after clear\n";
    std::cout << "END: test_Push_Clear\n";
}

uint64_t rng(const uint64_t start, const uint64_t end)
{
    return rand() % (end - start) + start;
}