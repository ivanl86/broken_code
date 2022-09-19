#include <iostream>

#include "node.h"
#include "queue.h"
#include "deque.h"

#define TEST_VAL 8

void test_EnqueueFront_DequeueFront(Queue<int> *);
void test_Mutlti_EnqueueFront_DequeueFront(Queue<int> *);
void test_Mutlti_EnqueueBack_DequeueBack(Queue<int> *);

int main(int argc, char const *argv[])
{
    try
    {
        test_EnqueueFront_DequeueFront(new Deque<int>);
        // test_Mutlti_EnqueueFront_DequeueFront(new Deque<int>);
        test_Mutlti_EnqueueBack_DequeueBack(new Deque<int>);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

void test_EnqueueFront_DequeueFront(Queue<int> *deque)
{
    std::cout << "TESTING: test_EnqueueFront_DequeueFront\n";
    if (!deque->isEmpty())
        throw std::runtime_error("FAILED: initial Deque not empty");
    deque->enqueueFront(TEST_VAL);
    if (deque->isEmpty())
        throw std::runtime_error("FAILED: Deque empty after enqueue");
    if (deque->dequeueFront() != TEST_VAL)
        throw std::runtime_error("FAILED: Deque store the wrong value");
    std::cout << "SUCCESS: test_EnqueueFront_DequeueFront\n";
}

void test_Mutlti_EnqueueFront_DequeueFront(Queue<int> *deque)
{
    if (!deque->isEmpty())
        throw std::runtime_error("FAILED: initial Deque not empty");
    for(size_t i{1}; i <= 10; ++i)
        deque->enqueueFront(i);
    if (deque->isEmpty())
        throw std::runtime_error("FAILED: Deque empty after enqueue");
    while (!deque->isEmpty())
        std::cout << deque->dequeueFront() << ' ';
    std::cout << '\n';
    std::cout << "SUCCESS: test_Mutlti_EnqueueFront_DequeueFront\n";
}

void test_Mutlti_EnqueueBack_DequeueBack(Queue<int> *deque)
{
    std::cout << "TESTING: test_Mutlti_EnqueueBack_DequeueBack\n";
    if (!deque->isEmpty())
        throw std::runtime_error("FAILED: initial Deque not empty");
    for(size_t i{1}; i <= 10; ++i)
        deque->enqueueBack(i);
    if (deque->isEmpty())
        throw std::runtime_error("FAILED: Deque empty after enqueue");
    //while (!deque->isEmpty())
    std::cout << "Starting dequeueBack\n";
    for(size_t i{1}; i <= 10; ++i)
        std::cout << deque->dequeueBack() << ' ';
    std::cout << '\n';
    std::cout << "SUCCESS: test_Mutlti_EnqueueBack_DequeueBack\n";
}