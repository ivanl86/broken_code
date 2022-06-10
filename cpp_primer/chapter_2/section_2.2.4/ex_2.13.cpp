#include <iostream>

int i = 42;
int main()
{
    int i = 100;
    int j = i; // j should equal to 100

    std::cout << j << std::endl;
}