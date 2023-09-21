#include "uninfected.h"

Uninfected::Uninfected(const Position &pos, char type) : Person(pos, type)
{}

void Uninfected::move(char move)
{
    switch (move)
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
    case 'P':
    case 'C':
        break;
    }
}

Uninfected::~Uninfected()
{}