#ifndef DICE_HPP
#define DICE_HPP

#include <memory>

#include "die.hpp"
#include "d6.hpp"

class D6;

namespace dice
{
    class Dice
    {
    public:
        Dice(uint16_t count);

        ~Dice();

        uint16_t roll();

        uint16_t getCount() const;

        uint16_t getSum() const;

    private:
        uint16_t count;
        uint16_t sum;

        std::unique_ptr<die::D6[]> dice;
    };

#include "dice.tpp"
}

#endif  /* DICE_H */