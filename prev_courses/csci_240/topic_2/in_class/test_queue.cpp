#include <iostream>
#include <stdexcept>

#include "queue.h"
#include "node.h"
#include "array_queue.h"
#include "linked_Queue.h"

#define TEST_VAL 5

void testEnqueue_Empty(Queue<int> *);
void testEnqueueMultiItems(Queue<int> *);
void testDequeue(Queue<int> *);
void testDequeueMultiItems(Queue<int> *);
void testClear(Queue<int> *);

int main(int argc, char const *argv[])
{
    try
    {
        testEnqueue_Empty(new ArrayQueue<int>);
        testEnqueueMultiItems(new ArrayQueue<int>);
        testDequeue(new ArrayQueue<int>);
        testDequeueMultiItems(new ArrayQueue<int>);
        testClear(new ArrayQueue<int>);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}

void testEnqueue_Empty(Queue<int> *queue)
{
    if (!queue->empty())
        throw std::runtime_error("FAILED: initit not empty");

    queue->enqueue(TEST_VAL);

    if (queue->empty())
        throw std::runtime_error("FAILED: empty after add");

    std::cout << "SUCCESS: testEnqueue_Empty\n";
}

void testEnqueueMultiItems(Queue<int> *queue)
{
    for(size_t i{1}; i <= 30; ++i)
        queue->enqueue(i);

    if (queue->empty())
        throw std::runtime_error("FAILED: empty after add");

    std::cout << "SUCCESS: testEnqueueMultiItems\n";
}

void testDequeue(Queue<int> *queue)
{
    for(size_t i{1}; i <= 30; ++i)
        queue->enqueue(i);

    for(size_t i{1}; i <= 30; ++i)
        if (queue->dequeue() != i)
            throw std::runtime_error("FAILED: did not dequeue in correct order");

    std::cout << "SUCCESS: testDequeue\n";
}

void testDequeueMultiItems(Queue<int> *queue)
{

}

void testClear(Queue<int> *queue)
{

}
