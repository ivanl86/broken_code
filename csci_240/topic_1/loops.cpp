#include <iostream>
#define VAL 10
#include <vector>
#include <string>

int main(int argc, char const *argv[])
{
    int i{};
    std::string s{};

    //std::cout << "Enter an integer greater than zero: ";
    //std::cin >> i;

    std::cout << "Enter a string: ";
    std::cin >> s;

    i <<= 1; // i = i << 1

    std::vector<int> v{1,2,3,4,5,i};

    std::cout << s << std::endl;

/*
    // for (declaration;test;update)
    for (;;)
    {
        std::cout << i-- << std::endl;
        if (i <= 0) break;
    }

    i = 11;
    while (i-- > 0)
    {
        std::cout << i << std::endl;
    }

    i = 10;
    do
    {
        std::cout << i << std::endl;
    } while (i-- > 0);

    for (int &i : v)
        i = 20;

    //v.push_back(55);

    for (int i : v)
    {
        std::cout << i << std::endl;
    }

    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << std::endl;
    }
*/
    return 0;
}
