#include "uninfected.h"

Uninfected::Uninfected(const Position &pos, char type) : Person(pos, type)
{}

void Uninfected::move(char move)
{
    switch (move)
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
    case 'C':
    case 'P':
        break;
    }
}

Uninfected::~Uninfected()
{}