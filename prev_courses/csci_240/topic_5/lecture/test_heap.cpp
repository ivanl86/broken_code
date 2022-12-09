#include <iostream>

#include "heap.h"
#include "max_heap.h"

#define TEST_VAL_1 10
#define TEST_VAL_2 13
#define TEST_VAL_3 15
#define TEST_VAL_4 1
#define TEST_VAL_5 55

int main(int argc, char const *argv[])
{
    MaxHeap<int, 8> heap;

    for (size_t i{1}; i <= 2; ++i)
    {
        heap.add(TEST_VAL_4);
        heap.add(TEST_VAL_2);
        heap.add(TEST_VAL_3);
        heap.add(TEST_VAL_1);
        heap.add(TEST_VAL_5);

        std::cout << heap.remove() << '\n';
        std::cout << heap.remove() << '\n';
        std::cout << heap.remove() << '\n';
        std::cout << heap.remove() << '\n';
        std::cout << heap.remove() << '\n';
    }

    for(size_t i{1}; i <= 4; ++i)
    { heap.add(i); }

    for(size_t i{1}; i <= 4; ++i)
    { std::cout << heap.remove() << ' '; }

    return 0;
}
