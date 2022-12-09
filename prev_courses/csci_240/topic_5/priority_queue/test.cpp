#include <iostream>
#include <ctime>
#include <stdio.h>

#include "p_queue.h"

int randRange(size_t, size_t);

void test_Max_Enqueue_Front_Dequeue();
void test_Max_Enqueue_Dequeue_Empty();
void test_Max_Enqueue_Dequeue_Resize();

void test_Min_Enqueue_Front_Dequeue();
void test_Min_Enqueue_Dequeue_Empty();
void test_Min_Enqueue_Dequeue_Resize();

void test_Array_Constructor();

#define TEST_VAL_1 18
#define TEST_VAL_2 20
#define TEST_VAL_3 9

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    try
    {
        std::cout << "Testing Max Priority Queue: \n";

        test_Max_Enqueue_Front_Dequeue();
        test_Max_Enqueue_Dequeue_Empty();
        test_Max_Enqueue_Dequeue_Resize();

        std::cout << "\nTesting Min Priority Queue: \n";

        test_Min_Enqueue_Front_Dequeue();
        test_Min_Enqueue_Dequeue_Empty();
        test_Min_Enqueue_Dequeue_Resize();

        std::cout << "\nTesting Max Priority Queue: \n";

        test_Array_Constructor();
    }
    catch(const std::exception& e)
    { std::cerr << e.what() << '\n'; }

    return 0;
}

// Random number generator
int randRange(size_t start, size_t end)
{ return (rand() % (end - start + 1)) + start; }

void test_Max_Enqueue_Front_Dequeue()
{
    PriorityQueue<int> pQueue([] (int l, int r) { return l > r; });

    if (!pQueue.isEmpty())
        std::cout << "FAILED: Queue is not initially empty\n";

    pQueue.enqueue(TEST_VAL_1);
    pQueue.enqueue(TEST_VAL_2);
    pQueue.enqueue(TEST_VAL_3);

    if (pQueue.isEmpty())
        std::cout << "FAILED: Queue is empty after enqueue\n";

    if (pQueue.getFront() != TEST_VAL_2)
        std::cout << "FAILED: Queue not in max priority\n";

    std::cout << pQueue.dequeue() << ' ';
    std::cout << pQueue.dequeue() << ' ';
    std::cout << pQueue.dequeue() << '\n';

    if (!pQueue.isEmpty())
        std::cout << "FAILED: Queue is not empty after dequeue\n";

    std::cout << "SUCCEED: enqueue_front_dequeue passed\n";
}

void test_Max_Enqueue_Dequeue_Empty()
{
    PriorityQueue<int> pQueue([] (int l, int r) { return l > r; });

    if (!pQueue.isEmpty())
        std::cout << "FAILED: Queue is not initially empty\n";

    for(size_t i{0}; i < 10; ++i)
        pQueue.enqueue(randRange(1, 1000));

    if (pQueue.isEmpty())
        std::cout << "FAILED: Queue is empty after enqueue\n";

    while (!pQueue.isEmpty())
        std::cout << pQueue.dequeue() << ' ';

    std::cout << '\n';

    if (!pQueue.isEmpty())
        std::cout << "FAILED: Queue is not empty after dequeue\n";

    std::cout << "SUCCEED: enqueue_dequeue_empty passed\n";
}

void test_Max_Enqueue_Dequeue_Resize()
{
    PriorityQueue<int> pQueue([] (int l, int r) { return l > r; });

    if (!pQueue.isEmpty())
        std::cout << "FAILED: Queue is not initially empty\n";

    for(size_t i{0}; i < 20; ++i)
        pQueue.enqueue(randRange(1, 1000));

    if (pQueue.isEmpty())
        std::cout << "FAILED: Queue is empty after enqueue\n";

    while (!pQueue.isEmpty())
        std::cout << pQueue.dequeue() << ' ';

    std::cout << '\n';

    if (!pQueue.isEmpty())
        std::cout << "FAILED: Queue is not empty after dequeue\n";

    std::cout << "SUCCEED: enqueue_dequeue_resize work properly\n";
}

void test_Min_Enqueue_Front_Dequeue()
{
    PriorityQueue<int> pQueue([] (int l, int r) { return l < r; });

    if (!pQueue.isEmpty())
        std::cout << "FAILED: Queue is not initially empty\n";

    pQueue.enqueue(TEST_VAL_1);
    pQueue.enqueue(TEST_VAL_2);
    pQueue.enqueue(TEST_VAL_3);

    if (pQueue.isEmpty())
        std::cout << "FAILED: Queue is empty after enqueue\n";

    if (pQueue.getFront() != TEST_VAL_3)
        std::cout << "FAILED: Queue not in min priority\n";

    std::cout << pQueue.dequeue() << ' ';
    std::cout << pQueue.dequeue() << ' ';
    std::cout << pQueue.dequeue() << '\n';

    if (!pQueue.isEmpty())
        std::cout << "FAILED: Queue is not empty after dequeue\n";

    std::cout << "SUCCEED: enqueue_front_dequeue passed\n";
}

void test_Min_Enqueue_Dequeue_Empty()
{
    PriorityQueue<int> pQueue([] (int l, int r) { return l < r; });

    if (!pQueue.isEmpty())
        std::cout << "FAILED: Queue is not initially empty\n";

    for(size_t i{0}; i < 10; ++i)
        pQueue.enqueue(randRange(1, 1000));

    if (pQueue.isEmpty())
        std::cout << "FAILED: Queue is empty after enqueue\n";

    while (!pQueue.isEmpty())
        std::cout << pQueue.dequeue() << ' ';

    std::cout << '\n';

    if (!pQueue.isEmpty())
        std::cout << "FAILED: Queue is not empty after dequeue\n";

    std::cout << "SUCCEED: enqueue_dequeue_empty passed\n";
}

void test_Min_Enqueue_Dequeue_Resize()
{
    PriorityQueue<int> pQueue([] (int l, int r) { return l < r; });

    if (!pQueue.isEmpty())
        std::cout << "FAILED: Queue is not initially empty\n";

    for(size_t i{0}; i < 20; ++i)
        pQueue.enqueue(randRange(1, 1000));

    if (pQueue.isEmpty())
        std::cout << "FAILED: Queue is empty after enqueue\n";

    while (!pQueue.isEmpty())
        std::cout << pQueue.dequeue() << ' ';

    std::cout << '\n';

    if (!pQueue.isEmpty())
        std::cout << "FAILED: Queue is not empty after dequeue\n";

    std::cout << "SUCCEED: enqueue_dequeue_resize work properly\n";
}

void test_Array_Constructor()
{
    int array[] {randRange(1, 1000), randRange(1, 1000), randRange(1, 1000), randRange(1, 1000)};
    int arraySz{4};
    PriorityQueue<int> pQueue([] (int l, int r) { return l > r; }, array, arraySz);

    if (pQueue.isEmpty())
        std::cout << "FAILED: Queue constructor does not take in the array\n";

    while (!pQueue.isEmpty())
        std::cout << pQueue.dequeue() << ' ';

    std::cout << '\n';

    if (!pQueue.isEmpty())
        std::cout << "FAILED: Queue is not empty after dequeue\n";

    std::cout << "SUCCEED: array_constructor passed\n";
}
