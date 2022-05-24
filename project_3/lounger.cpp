#include "lounger.h"

Lounger::Lounger(const Position &pos) : Infected(pos, 'L')
{}

void Lounger::move(const char move)
{
    if (random(1, 100) <= 20)
    {
        do
        {
            randomStumble = random(0,3);
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
}

Lounger::~Lounger()
{}