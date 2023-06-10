#include <iostream>
#include <ctime>
#include <windows.h>

#include "die.hpp"
#include "dice.hpp"

int main(int argc, char const *argv[])
{
    srand(GetTickCount() * GetCurrentProcessId());

    Dice dice(4, 2);
    Die die(4);
    uint64_t d1results[6]{};
    uint64_t d2results[11]{};
    uint64_t d3results[16]{};
    uint64_t sum{0};

    for (uint64_t i{0}; i < 1000; ++i)
    {
        ++d1results[die.roll() - 1];
        ++d2results[dice.roll() - 2];
    }

    std::cout << "\n";

    for (uint64_t i{0}; i < 6; ++i)
    {
        std::cout << i + 1 << ": " << ((float) d1results[i] / 10) << "%\n";
        sum += d1results[i];

    }
    std::cout << "\n";

    for (uint64_t i{0}; i < 11; ++i)
    {
        std::cout << i + 2 << ": " << ((float) d2results[i] / 10) << "%\n";
    }
    std::cout << "\n";

    dice.setCount(3);

    for (uint64_t i{0}; i < 1000; ++i)
    {
        ++d3results[dice.roll() - 3];
    }

    for (uint64_t i{0}; i < 16; ++i)
    {
        std::cout << i + 3 << ": " << ((float) d3results[i] / 10) << "%\n";
    }
    std::cout << "\n";

    return 0;
}
