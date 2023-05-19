#ifndef QUARTER_HPP
#define QUARTER_HPP

#include "coin.hpp"

#define QUARTER_VALUE 0.25

class Quarter : public Coin
{
public:
    Quarter() : Coin(QUARTER_VALUE, "Quarter") {}
    ~Quarter() {}

private:

};

#endif  /* QUARTER_HPP */