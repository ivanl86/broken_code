#ifndef PENNY_HPP
#define PENNY_HPP

#include "coin.hpp"

#define PENNY_VALUE 0.01

class Penny : public Coin
{
public:
    Penny() : Coin(PENNY_VALUE, "Penny") {}
    ~Penny() {}

private:

};

#endif  /* PENNY_HPP */