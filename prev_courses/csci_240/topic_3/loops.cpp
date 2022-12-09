#include <iostream>

int main(int argc, char const *argv[])
{
    for(size_t i{0}; i < 10; ++i)
    {
        for(size_t j{0}; j < i; ++j)
        {
            std::cout << i << " " << j << std::endl;
        }
    }
    

    return 0;
}
