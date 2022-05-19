#include "infected.h"

Infected::Infected(const Position &pos, char type) : Person (pos, type)
{}

Infected::~Infected() {}
/*
int random(const int &start, const int &end)
{ return rand() % (end - start + 1) + start; }*/