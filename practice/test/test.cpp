#include <iostream>
#include <cmath>

#include "func.hpp"

int fib(const int);
int factorial(const int);
int pow(const int, const int);
int mul(const int, const int);
int sum(const int);
// int sum(const int, const int);

int main(int argc, char const *argv[])
{
    int n{9};
    int array[] {3, 2, 1, 4};
    uint64_t size{sizeof(array) / sizeof(int)};
    // std::cout << pow(3, 3) << "\n";
    // std::cout << mul(3, 3) << "\n";
    // std::cout << sum(1000) << "\n";
    // std::cout << sum(10, 1) << "\n";
    // for(size_t i{0}; i < 50; ++i)
    // {
    //     std::cout << " " << rand() % 2;
    // }
    // for(size_t i{0}; i < size; ++i)
    // {
    //     std::cout << " " << array[i];
    // }
    // std::cout << "\n";
    // bubbleSort(array, size);
    // for(size_t i{0}; i < size; ++i)
    // {
    //     std::cout << " " << array[i];
    // }
    // std::cout << "\n";
    // bool isTrue{true};
    // std::cout << (isTrue ? std::to_string(90) : "hello");
    std::cout << n << "! = " << factorial(n) << "\n";
    std::cout << "sum(" << n << ") = " << sum(n) << "\n";
    std::cout << "Fib(" << n << ") = " << fib(n) << "\n";
    return 0;
}

int fib(const int n)
{
    return (n <= 1) ? n : fib(n - 1) + fib(n - 2); 
}

int factorial (const int n)
{
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int pow(const int x, const int y)
{
    if (y == 0)
        return 1;
    return (y > 1) ? x * pow(x, y - 1) : x;
}

int mul(const int i, const int j)
{
    if (i == 0 || j == 0)
        return 0;
    return (i > 1) ? j + mul(i - 1, j) : j;
}

int sum(const int n)
{
    return (n <= 1) ? n : n + sum(n - 1);
}

// int sum(const int n)
// {
//     return (n * (n + 1)) / 2;
// }

// int sum(const int n, const int start)
// {
//     if (start > n)
//         return 0;
//     if (start == n)
//         return n;
//     return sum(((n + start) / 2), start) + sum(n , ((n + start) / 2) + 1);
// }