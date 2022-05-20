#include "person.h"

Person::Person(const Position& pos, char type) : type{type}
{
    //this->pos->x = pos.x;
    //this->pos->y = pos.y;
}

Position Person::getPosition() const
{ return *this->pos; }

char Person::getType() const
{ return this->type; }

bool Person::operator==(const Person &other) const
{ return (other.pos->x == this->pos->x && other.pos->y == this->pos->y); }

bool Person::operator!=(const Person &other) const
{ return (other.pos->x != this->pos->x && other.pos->y != this->pos->y); }

Person::~Person()
{}

void Person::setPosition(const Position &pos)
{ this->pos->x = pos.x; this->pos->y = pos.y; }

bool Person::isInValidRange(char move)
{
    if (move == 'A')
    {
        char charArray[4]{'N', 'S', 'E', 'W'};
        move = charArray[random(0, 3)];
    }
    
    return ((move == 'N' && (this->pos->x > 0))
         || (move == 'S' && (this->pos->x < MAX_X))
         || (move == 'E' && (this->pos->y < MAX_Y))
         || (move == 'W' && (this->pos->y > 0))
         || (move == 'P'));
}

size_t Person::random(const size_t &start, const size_t &end)
{
    return rand() % (end - start + 1) + start;
}

/*
         || (move == 'C' && (specOp.x == scientist.x && specOp.x == scientist.y) && (!hasAntidote))
         
*/