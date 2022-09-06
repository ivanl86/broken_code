#include <iostream>

#include "math.h"

int main(int argc, char const *argv[])
{
    long x{-25};
    long y{55};

    Math<long> m(Math<long>::abs(x), y);

    std::cout << "absolutte value of x is " << Math<long>::abs(x) << std::endl;
    std::cout << "The greatest value of the two is: " <<  Math<long>::max(x, y) << std::endl;
    std::cout << "The lowest value of the two is: " <<  Math<long>::min(x, y) << std::endl;

    //std::cout << Math<long>::area(x, y);
    std::cout << m.area();
    return 0;
}
