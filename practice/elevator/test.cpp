#include <iostream>

#include "linkedqueue.h"
#include "priorityqueue.h"
#include "arraybag.h"

void testLinkedQueue(Queue<int>*);
void testPriorityQueue(Queue<int>*, uint64_t);
void testArrayBag(Bag<int>*, uint64_t);

int main()
{
    testLinkedQueue(new LinkedQueue<int>);
    testPriorityQueue(new PriorityQueue<int>(10), 10);
    testArrayBag(new ArrayBag<int>, 10);

    return 0;
}

void testLinkedQueue(Queue<int>* linkedQueue) {
    int array[] {6,8,9,2,4,7,1,5,0,3};

    std::cout << "start testing Linked Queue!\n";
    for(size_t i{0}; i < 10; ++i) {
        linkedQueue->enqueue(array[i]);
    }
    while (!linkedQueue->empty()) {
        std::cout << linkedQueue->dequeue();
    }
    std::cout << "\n";
}

void testPriorityQueue(Queue<int>* priorityQueue, uint64_t size) {
    int array[] {6,8,9,2,4,7,1,5,0,3};

    std::cout << "start testing Priority Queue!\n";
    for(size_t i{0}; i < size; ++i) {
        priorityQueue->enqueue(array[i]);
    }
    while (!priorityQueue->empty()) {
        std::cout << priorityQueue->dequeue();
    }
    std::cout << "\n";
}

void testArrayBag(Bag<int>* arrayBag, uint64_t size) {
    int array[] {6,8,9,2,4,7,1,5,0,3};
    // int array[] {6,8,9,2,4,7,1};

    std::cout << "start testing Array Bag!\n";

    for(size_t i{0}; i < size; ++i) {
        if (arrayBag->add(array[i]))
            std::cout << array[i];
    }
    std::cout << "\n";

        // if (arrayBag->contains(array[3])) {
        //     std::cout << array[3];
        //     arrayBag->remove(array[3]);
        // }
    for(size_t i{0}; i < size; ++i) {
        if (arrayBag->contains(array[i])) {
            std::cout << array[i];
            arrayBag->remove(array[i]);
        }
    }
}