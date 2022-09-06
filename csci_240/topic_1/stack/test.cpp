#include <iostream>

#include "array.h"
#include "stack.h"

int main(int argc, char const *argv[])
{
    // int array[]{1,2,3,4,5};
    // printArray<int, 5>(array);

    Stack<int> stack;
    for (size_t i = 0; i < 10; ++i)
        stack.push(i);
    while(!stack.isEmpty())
        std::cout << stack.pop() << ' ';
    std::cout << std::endl;

    return 0;
}
