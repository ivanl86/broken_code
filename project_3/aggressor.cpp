#include "aggressor.h"

Aggressor::Aggressor(const Position &pos) : Infected(pos, 'A')
{}

void Aggressor::move(const char move)
{
    std::string stumble{"NSEW"};
    switch (stumble[random(0, 3)])
    {
    case 'N':
        this->pos->x + 1;
    case 'S':
        this->pos->x - 1;
    case 'E':
        this->pos->y + 1;
    case 'W':
        this->pos->y - 1;
    }
}

Aggressor::~Aggressor()
{}