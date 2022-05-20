#include "lounger.h"

Lounger::Lounger(const Position &pos) : Infected(pos, 'L')
{}

void Lounger::move(const char move)
{
    if (random(1, 100) <= 20)
    {
        std::string stumble{"NSEW"};
        switch (stumble[random(0, 3)])
        {
        case 'N':
            this->pos->x + 1;
        case 'S':
            this->pos->x - 1;
        case 'E':
            this->pos->y + 1;
        case 'W':
            this->pos->y - 1;
        }
    }
}

Lounger::~Lounger()
{}