#include <iostream>
#include <ctime>

#include "p_queue.h"

size_t randRange(size_t, size_t);

void test_Enqueue_Dequeue();
void test_Multiple_Enqueue_Dequeue();

#define TEST_VAL_1 18
#define TEST_VAL_2 20
#define TEST_VAL_3 9

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    test_Multiple_Enqueue_Dequeue();

    // pQueue.enqueue(TEST_VAL_1);
    // pQueue.enqueue(TEST_VAL_2);
    // pQueue.enqueue(TEST_VAL_3);

    // std::cout << pQueue.dequeue() << '\n';
    // std::cout << pQueue.dequeue() << '\n';
    // std::cout << pQueue.dequeue() << '\n';
    return 0;
}

size_t randRange(size_t start, size_t end)
{ return (rand() % (end - start + 1)) + start; }

void test_Enqueue_Dequeue()
{}

void test_Multiple_Enqueue_Dequeue()
{
    PriorityQueue<int> pQueue([] (int l, int r) { return l > r; });

    for(size_t i{0}; i < 10; ++i)
        pQueue.enqueue(randRange(1, 1000));

    while (!pQueue.isEmpty())
        std::cout << pQueue.dequeue() << ' ';    
}