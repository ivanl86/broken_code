#ifndef DIME_HPP
#define DIME_HPP

#include "coin.hpp"

#define DIME_VALUE 0.10

class Dime : public Coin
{
public:
    Dime() : Coin(DIME_VALUE, "Dime") {}
    ~Dime() {}

private:
    /* data */
};

#endif  /* DIME_HPP */