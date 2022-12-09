#include <iostream>

int main(int argc, char const *argv[])
{
    for (size_t i{0}; i < 27; ++i)
    {
        std::cout << i * i << ',';
    }
    return 0;
}
