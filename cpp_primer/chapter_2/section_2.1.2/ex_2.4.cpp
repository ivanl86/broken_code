#include <iostream>

int main()
{
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl; // result is 32
    std::cout << u - u2 << std::endl; // resutlt will wrap around
    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl; // result is 32
    std::cout << i - i2 << std::endl; // result is -32
    std::cout << i - u << std::endl;  // result is 0
    std::cout << u - i << std::endl;  // result is 0
    return 0;
}