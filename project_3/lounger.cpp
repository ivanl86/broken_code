#include "lounger.h"

Lounger::Lounger(const Position &pos) : Infected(pos, 'L')
{}

void Lounger::move(const char move)
{
    if (isInValidRange(move) && (random(1, 100) <= 20))
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

Lounger::~Lounger()
{}