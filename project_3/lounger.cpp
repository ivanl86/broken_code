#include "lounger.h"

Lounger::Lounger(const Position &pos) : Infected(pos, 'L')
{}

void Lounger::move(const char move)
{
    if (random(1,100) <= 20)
    {
        do
        {
            int c{random(1, 5)};
            switch (c)
            {
            case 1: // N
                if (this->pos->y < (MAX_Y - 1))
                    this->pos->y + 1;
            case 2: // S
                if (this->pos->y > 0)
                    this->pos->y - 1;
            case 3: // E
                if (this->pos->x > 0)
                    this->pos->x - 1;
            case 4: // W
                if (this->pos->x < (MAX_X - 1))
                    this->pos->x + 1;
            }
        } while (true);
    }
}

Lounger::~Lounger()
{}