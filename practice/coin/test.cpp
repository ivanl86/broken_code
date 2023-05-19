#include <iostream>
#include <ctime>
#include <memory>

#include "dollar.hpp"
#include "half.hpp"
#include "coin.hpp"
#include "quarter.hpp"
#include "dime.hpp"
#include "nickel.hpp"
#include "penny.hpp"

#define TOTAL_TOSS 1000

int main(int argc, char const *argv[])
{
    std::shared_ptr<Coin> dollar{std::make_shared<Dollar>()};
    std::shared_ptr<Coin> half{std::make_shared<Half>()};
    std::unique_ptr<Coin> quarter{std::make_unique<Quarter>()};
    std::unique_ptr<Coin> dime{std::make_unique<Dime>()};
    Coin* nickel{new Nickel()};
    Coin* penny{new Penny()};

    size_t totalQuarterHeads{0};
    uint64_t totalDimeHeads{0};
    uint64_t totalNickelHeads{0};
    uint64_t totalPennyHeads{0};

    std::cout << *quarter << "\n";
    quarter->flip();
    std::cout << *quarter << "\n";

    // Coin* dollarPtr{dollar.get()};
    if (dynamic_cast<Dollar*>(dollar.get()) != nullptr)
        std::cout << dynamic_cast<Dollar*>(dollar.get())->makeNoise() << "\n";
    if (dynamic_cast<Dollar*>(half.get()) != nullptr)
        std::cout << dynamic_cast<Dollar*>(half.get())->makeNoise() << "\n";

    if (dynamic_cast<Quarter*>(quarter.get()) != nullptr)
        std::cout << "It is a " << quarter->getName() << "\n";
    if (dynamic_cast<Penny*>(nickel) == nullptr)
        std::cout << "It is not a penny\n";

    for (size_t i{0}; i < TOTAL_TOSS; ++i)
    {
        quarter->flip();
        dime->flip();
        nickel->flip();
        penny->flip();
        if (quarter->isHeads())
            ++totalQuarterHeads;
        if (dime->isHeads())
            ++totalDimeHeads;
        if (nickel->isHeads())
            ++totalNickelHeads;
        if (penny->isHeads())
            ++totalPennyHeads;
    }

    std::cout << quarter->getValue() << "\n";
    std::cout << dime->getValue() << "\n";
    if (*quarter < *dime)
        std::cout << "true\n";
    else
        std::cout << "false\n";

    std::cout << "Total Heads of " << quarter->getName() << ": " << totalQuarterHeads << "\n";
    std::cout << "Total Heads of " << dime->getName() << ": " << totalDimeHeads << "\n";
    std::cout << "Total Heads of " << nickel->getName() << ": " << totalNickelHeads << "\n";
    std::cout << "Total Heads of " << penny->getName() << ": " << totalPennyHeads << "\n";

    delete nickel;
    delete penny;
    return 0;
}

