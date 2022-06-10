#include "person.h"

Person::Person(const Position &pos, char type) : type{type}
{
    *this->pos = pos;
}

Position Person::getPosition() const
{ return *pos; }

char Person::getType() const
{ return type; }

bool Person::operator==(const Person& other) const
{ return (pos == other.pos) ? true : false; }

bool Person::operator!=(const Person& other) const
{ return (pos != other.pos) ? true : false; }

void Person::move(char move)
{}

Person::~Person()
{}

bool Person::isValidMove()
{
    if ((pos->x + pos->y < 2) && (pos->x > 0) && (pos->y > 0)
     && (pos->x < ROW_QTY) && (pos->y < COL_QTY))
        return true;
    else
        return false;
}

int random(const int &start, const int &end)
{
    return rand() % (end -start + 1) + start;
}