#include <iostream>

#include "stack.h"

void testPush(Stack<int> *);

int main(int argc, char const *argv[])
{
    //Stack<int> *testItem{new Stack<int>};

    try
    {
        testPush(new Stack<int>);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

    return 0;
}

void testPush(Stack<int> *stack)
{
    if (!stack->empty())
        throw std::runtime_error("FAILED: initial stack not empty");
    stack->push(5);
    if (stack->empty())
        throw std::runtime_error("FAILED: stack empty after push");
    std::cout << "SUCCESS: testPush\n";
}

void testPop(Stack<int> *stack)
{
    if (!stack->empty())
        throw std::runtime_error("FAILED: initial stack not empty");
    stack->push(5);
    if (stack->empty())
        throw std::runtime_error("FAILED: stack empty after push");
    std::cout << "SUCCESS: testPush\n";
}