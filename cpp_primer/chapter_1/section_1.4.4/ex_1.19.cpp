#include <iostream>

int main()
{
    int v1 = 0, v2 = 0;
    std::cout << "Enter two nmber: ";
    std::cin >> v1 >> v2;
    if (v1 < v2)
    {
        while (v1 <= v2)
        {
            std::cout << v1 << std::endl;
            ++v1;
        }
    }
    else
    {
        while (v2 <= v1)
        {
            std::cout << v2 << std::endl;
            ++v2;
        }
    }

    return 0;
}