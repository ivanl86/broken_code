#include "lounger.h"

Lounger::Lounger(const Position &pos) : Infected(pos, 'L')
{
}

void Lounger::move(const char move)
{
    if (!(isValidMove()))
        
        switch (move)
        {
        case 'A':
            if (random(1, 100) <= 20)
            {
                /* code */
            }
            
        }

}

Lounger::~Lounger()
{
}