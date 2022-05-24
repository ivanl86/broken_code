#include "hyper.h"

Hyper::Hyper(const Position &pos) : Infected(pos, 'H')
{}

void Hyper::move(const char move)
{
    do
    {
        randomStumble = random(0, 3);
    } while (!isValidStumble(stumble[randomStumble]));

    switch (stumble[randomStumble])
    {
    case 'N':
        moveNorth();
        break;
    case 'S':
        moveSouth();
        break;
    case 'E':
        moveEast();
        break;
    case 'W':
        moveWest();
        break;
    }
}

Hyper::~Hyper()
{}