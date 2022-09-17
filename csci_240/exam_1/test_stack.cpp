#include <iostream>

#include "stack.h"

#define TEST_VAL 8

void test_Push_Pop(Stack<int> *);
void test_Multi_Push_Pop(Stack<int> *);

int main(int argc, char const *argv[])
{
    //Stack<int> *testItem{new Stack<int>};

    try
    {
        test_Push_Pop(new Stack<int>);
        //test_Multi_Push_Pop(new Stack<int>);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

    return 0;
}

void test_Push_Pop(Stack<int> *stack)
{
    if (!stack->empty())
        throw std::runtime_error("FAILED: initial stack not empty");
    stack->push(TEST_VAL);
    if (stack->empty())
        throw std::runtime_error("FAILED: stack empty after push");
    if (stack->pop() != TEST_VAL)
        throw std::runtime_error("FAILED: pop the incorrect item");
    if (!stack->empty())
        throw std::runtime_error("FAILED: stack does not pop");
    std::cout << "SUCCESS: testPop\n";
}

void test_Multi_Push_Pop(Stack<int> *stack)
{
    if (!stack->empty())
        throw std::runtime_error("FAILED: initial stack not empty");
    for(size_t i{1}; i <= 2; i++)
        stack->push(i);
    if (stack->empty())
        throw std::runtime_error("FAILED: stack empty after push");
    for(size_t i{2}; i >= 1; --i)
    {std::cout << stack->pop() << ' ';}
/*        if (stack->pop() == i)
            std::cout << i << ' ';
        else
            throw std::runtime_error("FAILED: stack does not pop in correct order");
    }*/
    std::cout << "SUCCESS: testMultiPush_Pop\n";
}