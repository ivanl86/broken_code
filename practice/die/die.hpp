#ifndef DIE_H
#define DIE_H

#include <stdint.h>
#include <stdlib.h>

#define DEFAULT_SIZE 6

class Die
{
public:
    Die();

    Die(const uint16_t& sides);

    virtual uint16_t roll();

    virtual uint16_t getFace();

    void setSides(const uint16_t& sides);

    uint16_t getSides();

protected:
    uint16_t sides;
    uint16_t face;
};

#include "die.tpp"

#endif  /* DIE_H */