#include "uninfected.h"

Uninfected::Uninfected(const Position &pos, char type) : Person(pos, type)
{}

void Uninfected::move(char move)
{
    switch (move)
    {
    case 'N':
        this->pos->x + 1;
    case 'S':
        this->pos->x - 1;
    case 'E':
        this->pos->y + 1;
    case 'W':
        this->pos->y - 1;
    case 'C':
    case 'P':
        break;
    }
}

Uninfected::~Uninfected()
{}