#include <iostream>

// string variables initial values are always empty   
// integer variables initial values are equal to 0
std::string global_str;
int global_int;

int main()
{
    int local_int;
    std::string local_str;

    std::cout << global_str << std::endl; // undefined
    std::cout << global_int << std::endl; // zero
    std::cout << local_str << std::endl; // undefined
    std::cout << local_int << std::endl; // zero
    return 0;
}