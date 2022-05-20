#include "infected.h"

Infected::Infected(const Position &pos, char type) : Person (pos, type)
{}

Infected::~Infected() {pos == pos;}

size_t Infected::random(const size_t &start, const size_t &end)
{ return rand() % (end - start + 1) + start; }