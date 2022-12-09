//#include <iostream>

#include "pointer.h"
#include "array.h"

int main(int argc, char const *argv[])
{
    int array[]{1,2,3,4,5};

    printArray<int, 5>(array);

    //printArray(array, 5);
    //int *a{nullptr};
    //int b{55};
    //a = &b;
//
    //std::cout << a << ' ' << *a << std::endl;
//
    //*a = 10;
    //
    //std::cout << a << ' ' << *a++ << std::endl;
//
    //std::cout << a << ' ' << *a << std::endl;
    

    return 0;
}

void printArray(int *array, size_t size)
{
    int* a{array};
    std::cout << "[ ";

    // while (a < array + size)
    // {
    //     std::cout << *a++ << ' ';
    // }

    for (size_t i{0}; i < size; ++i)
    {
        std::cout << array[i] << ' ';
    }
    
    std::cout << "]\n";
}