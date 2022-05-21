#include "lounger.h"

Lounger::Lounger(const Position &pos) : Infected(pos, 'L')
{}

void Lounger::move(const char move)
{
    if (random(1, 100) <= 20)
    {
        std::string stumble{"NSEW"};
        size_t randomNum;
        do
        {
            randomNum = random(0,3);
        } while (!isValidStumble(stumble[randomNum]));
        
        switch (stumble[random(0, 3)])
        {
        case 'N':
            this->pos->x -= 1;
            break;
        case 'S':
            this->pos->x += 1;
            break;
        case 'E':
            this->pos->y += 1;
            break;
        case 'W':
            this->pos->y -= 1;
            break;
        }
    }
}

Lounger::~Lounger()
{}