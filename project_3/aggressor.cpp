#include "aggressor.h"

Aggressor::Aggressor(const Position &pos) : Infected(pos, 'A')
{}

void Aggressor::move(const char move)
{
    if (isInValidRange(move))
    {
        switch (random(1, 4))
        {
        case 1: // N
            this->pos->x - 1;
        case 2: // S
            this->pos->x + 1;
        case 3: // E
            this->pos->y + 1;
        case 4: // W
            this->pos->y - 1;
        }
    }
}

Aggressor::~Aggressor()
{}