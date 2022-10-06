#include <iostream>

#include "p_queue.h"

#define TEST_VAL_1 18

int main(int argc, char const *argv[])
{
    PriorityQueue<int> pQueue;

    pQueue.enqueue(TEST_VAL_1);
    
    return 0;
}

