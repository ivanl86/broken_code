#include <iostream>

int main()
{
    std::cin >> int input_value; // (a) can't declare and read the variable at the same time, declare the variable type before reading the variable to fix the problem
    int i = { 3.14 }; // (b) it can't compile because it can't initialize a integer variable with a double value, change the variable type to double to fix the problem
    double salary = wage = 9999.99; // (c) wage needs to declare variable type, declare variable type for wage to fix the problem
    int a = 3.14; // (d) it can compile but it loses information due to the int type can't hold a double value, change the variable type to double to fix the problem

    return 0;
}