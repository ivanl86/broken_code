#include "infected.h"

Infected::Infected(const Position &pos, char type) : Person (pos, type)
{}

Infected::~Infected() {pos == pos;}

size_t Infected::random(const size_t &start, const size_t &end)
{ return rand() % (end - start + 1) + start; }

bool Infected::isValidStumble(const char &stumble)
{
    return ((stumble == 'N' && this->pos->x > 0)
         || (stumble == 'S' && this->pos->x < (MAX_X - 1))
         || (stumble == 'E' && this->pos->y < (MAX_Y - 1))
         || (stumble == 'W' && this->pos->y > 0));
}