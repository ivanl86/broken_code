#include <iostream>

#include "queue.h"
#include "arrayQueue.h"
#include "linkedQueue.h"

const int TEST_VAL{1};
const int TEST_VALS_1[]{1,2,3,4,5,6};
const int TEST_VALS_2[]{7,8,9,10,11,12};
const int TEST_VALS_3[]{13,14,15,16,17,18};
const int TEST_VALS_4[]{19,20,21,22,23,24,25,26};
const int TEST_VAL_SIZE{6};
const int TEST_VAL_SIZE_2{8};

void testEnqueueDequeue(Queue<int> *);
void testCircularQueue(Queue<int> *);
void testResize(Queue<int> *);
void testCircularResize(Queue<int> *);

int main(int argc, char const *argv[])
{
    try
    {/**/
        std::cout << "Start testing ArrayQueue\n";
        testEnqueueDequeue(new ArrayQueue<int>);
        std::cout << std::endl;
        testCircularQueue(new ArrayQueue<int>);
        std::cout << std::endl;
        testResize(new ArrayQueue<int>);
        std::cout << std::endl;
        testCircularResize(new ArrayQueue<int>);
        std::cout << std::endl;

        std::cout << "Start testing LinkedQueue\n";
        testEnqueueDequeue(new LinkedQueue<int>);
        std::cout << std::endl;
        testCircularQueue(new LinkedQueue<int>);
        std::cout << std::endl;
        testResize(new LinkedQueue<int>);
        std::cout << std::endl;
        testCircularResize(new LinkedQueue<int>);
        std::cout << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }

    return 0;
}

void testEnqueueDequeue(Queue<int> *queue)
{
    queue->enqueue(TEST_VAL);

    if (queue->getFront() != TEST_VAL)
        throw std::runtime_error("FAILED: The enqueue function did not add the correct value\n");

    std::cout << (queue->isEmpty() ? "The queue is empty\n" : "The queue is not empty\n");

    if (queue->dequeue() != TEST_VAL)
        throw std::runtime_error("FAILED: The dequeue function did not remove the correct value\n");
    
    std::cout << (queue->isEmpty() ? "The queue is empty\n" : "The queue is not empty\n");

    delete queue;

    std::cout << "SUCCEED: The enqueue and dequeue function passed\n";
}

void testCircularQueue(Queue<int> *queue)
{
    for(size_t i{0}; i < TEST_VAL_SIZE; ++i)
        queue->enqueue(TEST_VALS_1[i]);
    while (!queue->isEmpty())
        std::cout << queue->dequeue() << ' ';

    std::cout << std::endl;

    for(size_t i{0}; i < TEST_VAL_SIZE; ++i)
        queue->enqueue(TEST_VALS_2[i]);
    for(size_t i{0}; i < 4; ++i)
        std::cout << queue->dequeue() << ' ';

    std::cout << std::endl;

    for(size_t i{0}; i < TEST_VAL_SIZE; ++i)
        queue->enqueue(TEST_VALS_3[i]);
    while (!queue->isEmpty())
        std::cout << queue->dequeue() << ' ';

    std::cout << std::endl;

    for(size_t i{0}; i < TEST_VAL_SIZE_2; ++i)
        queue->enqueue(TEST_VALS_4[i]);
    while (!queue->isEmpty())
        std::cout << queue->dequeue() << ' ';

    std::cout << std::endl;

    delete queue;

    std::cout << "SUCCEED: The enqueue and dequeue function in circular passed\n";
}

void testResize(Queue<int> *queue)
{
    for(size_t i{0}; i < TEST_VAL_SIZE; ++i)
        queue->enqueue(TEST_VALS_1[i]);
    for(size_t i{0}; i < TEST_VAL_SIZE; ++i)
        queue->enqueue(TEST_VALS_2[i]);

    while (!queue->isEmpty())
        std::cout << queue->dequeue() << ' ';

    std::cout << std::endl;

    delete queue;

    std::cout << "SUCCEED: The resize function passed\n";
}

void testCircularResize(Queue<int> *queue)
{
    for(size_t i{0}; i < TEST_VAL_SIZE; ++i)
        queue->enqueue(TEST_VALS_1[i]); // 1,2,3,4,5,6
    while (!queue->isEmpty())
        std::cout << queue->dequeue() << ' ';

    std::cout << std::endl;

    for(size_t i{0}; i < TEST_VAL_SIZE; ++i)
        queue->enqueue(TEST_VALS_2[i]); // 7,8,9,10,11,12
    for(size_t i{0}; i < TEST_VAL_SIZE; ++i)
        queue->enqueue(TEST_VALS_3[i]); // 13,14,15,16,17,18

    while (!queue->isEmpty())
        std::cout << queue->dequeue() << ' ';

    std::cout << std::endl;

    delete queue;

    std::cout << "SUCCEED: The resize function in circular passed\n";
}