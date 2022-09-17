#include <iostream>

#include "linkedStack.h"

#define TEST_VAL 5

void test_Push_Pop(LinkedStack<int> *);
void test_Multi_Push_Pop(LinkedStack<int> *);
void test_Pop_Clear(LinkedStack<int> *);

int main(int argc, char const *argv[])
{
    try
    {
        test_Push_Pop(new LinkedStack<int>);
        test_Multi_Push_Pop(new LinkedStack<int>);
        test_Pop_Clear(new LinkedStack<int>);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

void test_Push_Pop(LinkedStack<int> *stack)
{
    if (!stack->empty())
        throw std::runtime_error("FAILED: initial Stack not empty");
    stack->push(TEST_VAL);
    if (stack->empty())
        throw std::runtime_error("FAILED: Stack empty after push");
    if (stack->peek() != TEST_VAL)
        throw std::runtime_error("FAILED: peek on wrong item");
    stack->pop();
    if (!stack->empty())
        throw std::runtime_error("FAILED: Stack not empty after pop");
    delete stack;
    std::cout << "SUCCESS: test_Push_Pop\n";
}

void test_Multi_Push_Pop(LinkedStack<int> *stack)
{
    if (!stack->empty())
        throw std::runtime_error("FAILED: initial Stack not empty");
    for(size_t i{1}; i <= 10; ++i)
        stack->push(i);
    if (stack->empty())
        throw std::runtime_error("FAILED: Stack empty after push");
    for(size_t i{10}; i >= 1; --i)
        if (stack->pop() != i)
            throw std::runtime_error("FAILED: does not pop in correct order");
    if (!stack->empty())
        throw std::runtime_error("FAILED: Stack not empty after pop");
    delete stack;
    std::cout << "SUCCESS: test_Multi_Push_Pop\n";
}

void test_Pop_Clear(LinkedStack<int> *stack)
{
    if (!stack->empty())
        throw std::runtime_error("FAILED: initial Stack not empty");
    for(size_t i{1}; i <= 10; ++i)
        stack->push(i);
    if (stack->empty())
        throw std::runtime_error("FAILED: Stack empty after push");
    stack->clear();
    if (!stack->empty())
        throw std::runtime_error("FAILED: Stack not empty after clear");
    delete stack;
    std::cout << "SUCCESS: test_Pop_Clear\n";
}