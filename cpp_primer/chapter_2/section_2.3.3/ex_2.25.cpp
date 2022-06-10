#include <iostream>

int main()
{
    { // a
        int ip,  &r = ip;
        std::cout << ip << std::endl;
        std::cout << r << std::endl;
    }
    { // b
        int i, *ip = 0;
        std::cout << i << std::endl;
        std::cout << ip << std::endl;
    }
    { // c
        int *ip, ip2;
        std::cout << ip << std::endl;
        std::cout << ip2 << std::endl;
    }
    
}