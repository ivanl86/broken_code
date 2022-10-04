#include <iostream>

#include "heap.h"
#include "f_max_heap.h"

#define TEST_VAL 10
#define TEST_VAL_2 13
#define TEST_VAL_3 15

int main(int argc, char const *argv[])
{
    MaxHeap<int, 8> heap;
    heap.add(TEST_VAL_3);
    heap.add(TEST_VAL_2);
    heap.add(TEST_VAL);

    std::cout << heap.remove() << '\n';
    std::cout << heap.remove() << '\n';
    std::cout << heap.root() << '\n';
    return 0;
}
