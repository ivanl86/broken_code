#include "uninfected.h"

Uninfected::Uninfected(const Position &pos, char type) : Person(pos, type)
{}

void Uninfected::move(const char move)
{
    if (!(isValidMove()))
        throw std::runtime_error("");
    
    switch (move)
    {
    case 'N':
        pos->x - 1;
    case 'S':
        pos->x + 1;
    case 'E':
        pos->y + 1;
    case 'W':
        pos->y - 1;
    case 'P':
        break;
    case 'C':
        if (!hasAntidote)
            hasAntidote = true;
        break;
    }
}

Uninfected::~Uninfected()
{}
