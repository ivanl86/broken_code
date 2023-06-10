#ifndef DICE_H
#define DICE_H

#include <stdint.h>

#define MAX_COUNT 8

// #include "die.hpp"

class Die; // forward declared dependency

class Dice
{
public:
    Dice(const uint16_t& count) noexcept;

    Dice(const uint16_t& sides, const uint16_t& count) noexcept;

    ~Dice() noexcept;

    uint16_t roll() noexcept;

    uint16_t getSum() const noexcept;

    // void addDie(const uint16_t& count);

    // void removeDie(const uint16_t& ocunt);

    void setCount(const uint16_t& ocunt) noexcept(false);

    uint16_t getCount() const noexcept;

private:
    uint16_t sum;
    uint16_t count;

    Die* dice;
} ;

#include "dice.tpp"

#endif  /* DICE_H */
