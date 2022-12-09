#include <iostream>
#include <cstdlib>
#include <ctime>

int randomRange(int, int);

int main(int argc, char const *argv[])
{
    srand(time(NULL)); // should be called at the beginning of main
    
    int count{};
    for(size_t i{0}; i < 1000; ++i)
    {
        if (randomRange(1, 1000) <= 35)
        {
            std::cout << "a new person entered the building\n";
            ++count;
        }
    }
    std::cout << count << '\n';
    
    return 0;
}

int randomRange(int start, int end)
{
    return (rand() % (end - start + 1)) + start;
}