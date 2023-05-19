#ifndef HALF_HPP
#define HALF_HPP

#include "coin.hpp"

#define HALF_VALUE 0.50

class Half : public Coin
{
public:
    Half() : Coin(HALF_VALUE, "Half") {}
    ~Half() {}

private:

};

#endif  /* HALF_HPP */