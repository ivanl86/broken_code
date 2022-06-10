#include <iostream>

int main()
{
    int i = 0, &r1 = i;
    double d = 0, &r2 = d;

    r2 = 3.14159; // assign r2 to 3.14159
    std::cout << r2 << std::endl;
    r2 = r1; // assign r2 to r1 and r1 is a reference to i
    std::cout << r2 << std::endl;
    i = r2; // assign i to r2 and r2 is a reference to d
    std::cout << i << std::endl;
    r1 = d; // assign r1 to d
    std::cout << r1 << std::endl;
}