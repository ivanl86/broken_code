#include <iostream>


#include "p_queue.h"

#define TEST_VAL_1 18
#define TEST_VAL_2 20
#define TEST_VAL_3 9

int main(int argc, char const *argv[])
{
    PriorityQueue<int> pQueue([] (int l, int r) { return l < r; });

    pQueue.enqueue(TEST_VAL_1);
    pQueue.enqueue(TEST_VAL_2);
    pQueue.enqueue(TEST_VAL_3);

    std::cout << pQueue.dequeue() << '\n';
    std::cout << pQueue.dequeue() << '\n';
    std::cout << pQueue.dequeue() << '\n';

    return 0;
}

