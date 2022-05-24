#include "aggressor.h"

Aggressor::Aggressor(const Position &pos) : Infected(pos, 'A')
{}

Aggressor::Aggressor(const Position &pos, Uninfected *specOp) : Infected(pos, 'A'), victim{specOp}
{}

void Aggressor::move(const char move)
{ (isVictimInRange() ? pursueVictim() : randomMove()); }

Aggressor::~Aggressor()
{}

bool Aggressor::isVictimInRange()
{ return (abs((victim->getPosition().x + victim->getPosition().y) - (this->pos->x + this->pos->y)) <= IN_RANGE); }

void Aggressor::randomMove()
{
    do
    {
        randomStumble = random(0, 3);
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

void Aggressor::pursueVictim()
{/*
    if (victim->getPosition().x == this->pos->x)
        (victim->getPosition().y > this->pos->y ? moveEast() : moveWest());
    if (victim->getPosition().y == this->pos->y)
        (victim->getPosition().x > this->pos->x ? moveSouth() : moveNorth());
    if (victim->getPosition().y - this->pos->y == 1)
    {
        if (victim->getPosition().x > this->pos->x)
            (random(0, 1) ? moveSouth() : moveEast());
        if (victim->getPosition().x < this->pos->x)
            (random(0, 1) ? moveNorth() : moveEast());
    }
    if (victim->getPosition().y - this->pos->y == -1)
    {
        if (victim->getPosition().x > this->pos->x)
            (random(0, 1) ? moveSouth() : moveWest());
        if (victim->getPosition().x < this->pos->x)
            (random(0, 1) ? moveNorth() : moveWest());
    }*/
}