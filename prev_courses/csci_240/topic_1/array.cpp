#include <iostream>
#include <array>

void printArray(int a[], size_t size)
{
    std::cout << sizeof(a) << std::endl;
    std::cout << "[ ";
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << "]" << std::endl;
}

void printArray(std::array<int,4> &a)
{
    std::cout << sizeof(a) << std::endl;
    std::cout << "[ ";
    for (size_t i = 0; i < a.size(); ++i)
    {
        std::cout << a.at(i) << " ";
    }
    std::cout << "]" << std::endl;
}
/*
int main(int argc, char const *argv[])
{
    int array[20]{1,2,3,4};
    double d{20};
    //std::cout << sizeof(array) << std::endl;

    std::array<int,4> array2{1,2,3,4};

    printArray(array2);
    return 0;
}
*/