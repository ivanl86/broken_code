#include "lounger.h"

Lounger::Lounger(const Position &pos) : Infected(pos, 'L')
{
}

void Lounger::move(const char move)
{
    if (random(1, 100) <= 20)
    {
        switch (move)
        {
        case 'N':
            if (pos->y != 0)
                pos->y -= 1;
            else
                break;
        case 'S':
            if (pos->y != 9)
                pos->y += 1;
            break;
        case 'E':
            if (pos->x != 7)
                pos->x += 1;
            break;
        case 'W':
            if (pos->x != 0)
                pos->x -= 1;

        default:
            break;
        }
    }
}

Lounger::~Lounger()
{
}

int Lounger::random(const int &start, const int &end)
{
    return rand() % (end - start + 1) + start;
}