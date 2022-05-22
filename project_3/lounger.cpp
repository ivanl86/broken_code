#include "lounger.h"

Lounger::Lounger(const Position &pos) : Infected(pos, 'L')
{}

void Lounger::move(const char move)
{
    if (random(1, 100) <= 20)
    {
        std::string stumble{"NSEW"};
        size_t randomStumble;
        do
        {
            randomStumble = random(0,3);
        } while (!isValidStumble(stumble[randomStumble]));

        switch (stumble[randomStumble])
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
        }
    }
}

Lounger::~Lounger()
{}