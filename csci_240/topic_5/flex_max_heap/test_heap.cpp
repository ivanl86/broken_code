#include <iostream>

#include "heap.h"
#include "f_max_heap.h"

#define TEST_VAL_1 10
#define TEST_VAL_2 13
#define TEST_VAL_3 15

int main(int argc, char const *argv[])
{
    int array[]{1,2,3,4,5,6};

    MaxHeap<int> heap(array, 6);

    heap.add(TEST_VAL_1);
    heap.add(TEST_VAL_3);
    heap.add(TEST_VAL_2);

    std::cout << heap.remove() << '\n';
    std::cout << heap.remove() << '\n';
    std::cout << heap.remove() << '\n';
/**/
    for(size_t i{1}; i <= 10; ++i)
    { heap.add(i); }

    for(size_t i{1}; i <= 10; ++i)
    { std::cout << heap.remove() << '\n'; }

    return 0;
}
