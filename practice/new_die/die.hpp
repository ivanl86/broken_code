#ifndef DIE_HPP
#define DIE_HPP

#include <stdint.h>
#include <stdlib.h>
#include <random>

namespace die
{
    class Die
    {
    public:
        Die(uint16_t sides);

        ~Die();

        uint16_t roll();

        uint16_t getFaceValue() const;

        uint16_t getTotalSides() const;

    private:
        uint16_t totalSides;
        uint16_t faceValue;

        uint16_t rand(int start, int end);
    };

#include "die.tpp"
}

#endif /* DIE_HPP */