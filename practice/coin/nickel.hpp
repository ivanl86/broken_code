#ifndef NICKEL_HPP
#define NICKEL_HPP

#include "coin.hpp"

#define NICKEL_VALUE 0.05

class Nickel : public Coin
{
public:
    Nickel() : Coin(NICKEL_VALUE, "Nickel") {}
    ~Nickel() {}

private:

};

#endif  /* NICKEL_HPP */