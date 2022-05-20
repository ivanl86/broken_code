#include "hyper.h"

Hyper::Hyper(const Position &pos) : Infected(pos, 'H')
{}

void Hyper::move(const char move)
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

Hyper::~Hyper()
{}