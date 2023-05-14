#include <iostream>
#include <iomanip>
#include <ctime>

#include "d6.hpp"
#include "dice.hpp"

#define ONE 1
#define TEN 10
#define HUNDRED 100
#define THOUSAND 1000

int main(int argc, char const *argv[])
{
    const uint64_t totalDice{3};
    uint64_t multipler{THOUSAND};
    uint64_t totalRoll{HUNDRED * multipler};
    uint64_t results[SIX_SIDES] {};
    uint64_t twoD6_results[SIX_SIDES * totalDice - (totalDice - 1)] {};
    die::D6 d6;
    dice::Dice twoD6(totalDice);

    // srand(static_cast<uint64_t>(time(nullptr)));

    std::cout << std::fixed << std::setprecision(2);
    for (uint64_t i{0}; i < totalRoll; ++i)
    {
        ++results[d6.roll() - 1];
        ++twoD6_results[twoD6.roll() - totalDice];
    }

    std::cout << "Results for rolling a " << d6.getTotalSides() << " sided die " << totalRoll << " times\n";
    for (uint64_t i{0}; i < 6; ++i)
    {
        std::cout << std::setw(2) << i + 1 << "\t" << std::setw(6) << static_cast<float>(results[i]) / multipler << "%\n";
    }
    std::cout << "\nResults for rolling " << twoD6.getCount() << " six sided die " << totalRoll << " times\n";
    for (uint64_t i{0}; i < (SIX_SIDES * totalDice - (totalDice - 1)); ++i)
    {
        std::cout << std::setw(2) << i + totalDice << "\t" << std::setw(6) << static_cast<float>(twoD6_results[i]) / multipler << "%\n";
    }

    return 0;
}
