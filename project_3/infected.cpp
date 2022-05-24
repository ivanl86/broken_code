#include "infected.h"

Infected::Infected(const Position &pos, char type) : Person (pos, type)
{}

Infected::~Infected() {pos == pos;}

size_t Infected::random(const size_t &start, const size_t &end)
{ return rand() % (end - start + 1) + start; }

bool Infected::isValidStumble(const char &stumble)
{
    return ((stumble == 'N' && this->pos->x > 0)
         || (stumble == 'S' && this->pos->x < MAX_X)
         || (stumble == 'E' && this->pos->y < MAX_Y)
         || (stumble == 'W' && this->pos->y > 0));
}

void Infected::moveNorth()
{ --this->pos->x; }

void Infected::moveSouth()
{ ++this->pos->x; }

void Infected::moveEast()
{ ++this->pos->y; }

void Infected::moveWest()
{ --this->pos->y; }