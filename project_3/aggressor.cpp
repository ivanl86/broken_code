#include "aggressor.h"

Aggressor::Aggressor(const Position &pos) : Infected(pos, 'A')
{}

void Aggressor::move(const char move)
{
    std::string stumble{"NSEW"};
    size_t randomNum;
    do
    {
        randomNum = random(0, 3);
    } while (!isValidStumble(stumble[randomNum]));

    switch (stumble[random(0, 3)])
    {
    case 'N':
        this->pos->x -= 1;
        break;
    case 'S':
        this->pos->x += 1;
        break;
    case 'E':
        this->pos->y += 1;
        break;
    case 'W':
        this->pos->y -= 1;
        break;
    }
}

Aggressor::~Aggressor()
{}