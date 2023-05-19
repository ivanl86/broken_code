#ifndef DOLLAR_HPP
#define DOLLAR_HPP

#include "coin.hpp"

#define DOLLAR_VALUE 1.00

class Dollar : public Coin
{
public:
    Dollar() : Coin(DOLLAR_VALUE, "Dollar") {}
    ~Dollar() {}

    std::string makeNoise()
    {
        return "Clink";
    }

private:

};

#endif  /* DOLLAR_HPP */