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
