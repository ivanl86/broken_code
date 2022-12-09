#include <iostream>

#ifndef ARRAY_H
#define ARRAY_H

template<typename T, size_t S>
void printArray(T array[])
{
    std::cout << "[ ";
    for (size_t i = 0; i < S; ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << "]\n";
}

#endif