#include <iostream>
#include <stdexcept>

#include "bag.h"
#include "array_bag.h"
#include "linked_bag.h"

const int TEST_VAL{5};
const int TEST_VALS[]{1,2,3,4,5,6,7,8,9,10,11};
const size_t TEST_VAL_SIZE{11};

void testAdd_Size(Bag<int> *);
void testContains(Bag<int> *);
void testContainsUsingArray(Bag<int> *);

int main(int argc, char const *argv[])
{
    // Bag<int> *bag{new ArrayBag<int>};

    try
    {
        testAdd_Size(new LinkedBag<int>);

        testContains(new LinkedBag<int>);
    
        testContainsUsingArray(new LinkedBag<int>);

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}

void testAdd_Size(Bag<int> *bag)
{
    bag->add(TEST_VAL);
    
    if (bag->size() != 1)
        throw std::runtime_error("FAILED: Tested Add function. Size did not return correct value");

    std::cout << "PASSED! Add passed\n";

    delete bag;
}

void testContains(Bag<int> *bag)
{
    bag->add(TEST_VAL);
    
    if (!bag->contains(TEST_VAL))
        throw std::runtime_error("FAILED: Tested Contains function. Did not report membership");

    std::cout << "PASSED! Contains passed\n";

    delete bag;
}

void testContainsUsingArray(Bag<int> *bag)
{
    for(size_t i{0}; i < TEST_VAL_SIZE; ++i)
        bag->add(TEST_VALS[i]);
    
    if (!bag->contains(TEST_VALS[0]))
        throw std::runtime_error("FAILED: Tested Contains function on first item added. Did not report membership");
    if (!bag->contains(TEST_VALS[TEST_VAL_SIZE - 1]))
        throw std::runtime_error("FAILED: Tested Contains function on last item added. Did not report membership");
    if (!bag->contains(TEST_VALS[TEST_VAL_SIZE >> 1]))
        throw std::runtime_error("FAILED: Tested Contains function on middle item added. Did not report membership");
    if (bag->contains(0))
        throw std::runtime_error("FAILED: Tested Contains function on value not added. Did not report membership");

    std::cout << "PASSED! Contains on multiple values passed\n";

    delete bag;
}