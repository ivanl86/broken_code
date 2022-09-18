#include <iostream>

#include "node.h"
#include "queue.h"
#include "deque.h"

#define TEST_VAL 8

void test_EnqueueFront_DequeueFront(Queue<int> *);

int main(int argc, char const *argv[])
{
    try
    {
        test_EnqueueFront_DequeueFront(new Deque<int>);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

void test_EnqueueFront_DequeueFront(Queue<int> *deque)
{
    if (!deque->isEmpty())
        throw std::runtime_error("FAILED: initial Deque not empty");
    deque->enqueueFront(TEST_VAL);
    if (deque->isEmpty())
        throw std::runtime_error("FAILED: Deque empty after enqueue");
    if (deque->dequeueFront() != TEST_VAL)
        throw std::runtime_error("FAILED: Deque store the wrong value");
    std::cout << "SUCCESS: test_EnqueueFront_DequeueFront";
}