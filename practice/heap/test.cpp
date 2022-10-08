#include <iostream>
#include <ctime>

#include "min_heap.h"

#define TEST_VAL_1 78
#define TEST_VAL_2 33
#define TEST_VAL_3 32
#define TEST_VAL_4 54

void test_Add_Remove_Root();
void test_Add_Resize_Remove();

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    test_Add_Remove_Root();
    std::cout << '\n';
    test_Add_Resize_Remove();

    return 0;
}

uint64_t randRange(uint64_t start, uint64_t end)
{ return (rand() % (end - start + 1)) + start; }

void test_Add_Remove_Root()
{
    MinHeap<int> mHeap;

    std::cout << "Testing add_remove_root:\n";

    if (mHeap.size() != 0)
        std::cout << "FAILED: Heap is not initially empty\n";

    mHeap.add(TEST_VAL_1);
    mHeap.add(TEST_VAL_2);
    mHeap.add(TEST_VAL_3);
    mHeap.add(TEST_VAL_4);

    if (mHeap.size() == 0)
        std::cout << "FAILED: Heap is empty after add\n";

    if (mHeap.root() != TEST_VAL_3)
        std::cout << "FAILED: Not a min heap\n";

    while (mHeap.size() != 0)
        std::cout << mHeap.remove() << ' ';

    std::cout << '\n';

    if (mHeap.size() != 0)
        std::cout << "FAILED: Heap is not empty after remove\n";

    std::cout << "SUCCEDED: Add_Remove_Root passed\n";
}

void test_Add_Resize_Remove()
{
    MinHeap<int> mHeap;

    std::cout << "Testing add_Resize_remove:\n";

    const int addSize{20};
    uint16_t count{};

    if (mHeap.size() != 0)
        std::cout << "FAILED: Heap is not initially empty\n";

    for(size_t i{0}; i < addSize; ++i)
        mHeap.add(randRange(1, 100));

    if (mHeap.size() == 0)
        std::cout << "FAILED: Heap is empty after add\n";

    while (mHeap.size() != 0)
    {
        std::cout << mHeap.remove() << ' ';
        ++count;
    }

    std::cout << '\n';

    if (mHeap.size() != 0)
        std::cout << "FAILED: Heap is not empty after remove\n";

    if (count != addSize)
        std::cout << "FAILED: Removed different number of items";

    std::cout << "SUCCEDED: Add_Resize_Remove passed\n";
}