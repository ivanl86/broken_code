#include <iostream>

int main()
{
    int i = 0;
    double* dp = &i; // illegal, can't use int to initialize double
    int *ip = i; // illegal, pointer must point to a reference
    int *p = &i; // legal
    
    return 0;
}