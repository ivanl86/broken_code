#include "hyper.h"

Hyper::Hyper(const Position &pos) : Infected(pos, 'H')
{}

void Hyper::move(const char move)
{
    std::string stumble{"NSEW"};
    size_t randomStumble;
    do
    {
        randomStumble = random(0, 3);
    } while (!isValidStumble(stumble[randomStumble]));

    switch (stumble[randomStumble])
    {
    case 'N':
        --this->pos->x;
        break;
    case 'S':
        ++this->pos->x;
        break;
    case 'E':
        ++this->pos->y;
        break;
    case 'W':
        --this->pos->y;
        break;
    }
}

Hyper::~Hyper()
{}