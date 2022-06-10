#include <iostream>

int main()
{
    int v1 = 0, v2 = 0;
    std::cout << "Enter a small nmber: ";
    std::cin >> v1;
    std::cout << "Enter a large nmber: ";
    std::cin >> v2;
    while (v1 <= v2)
    {
        std::cout << v1 << std::endl;
        ++v1;        
    }
    return 0;
}