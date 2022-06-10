

#include <iostream>

int main()
{
    int val = 128;
    int val2 = 256;
    int *ptr = &val;

    std::cout << ptr << std::endl;
    std::cout << *ptr << std::endl;

    *ptr = val2;
    std::cout << ptr << std::endl;
    std::cout << *ptr << std::endl;

    return 0;
}