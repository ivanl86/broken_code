#include <iostream>

extern int ix = 1024; // definition, no error on the global scope

int main()
{
    extern int ix = 1024; // definition, it throws error on a local declaration
    int iy; // definition
    extern int iz; // declaration
    return 0;
}