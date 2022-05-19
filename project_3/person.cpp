#include "person.h"

Person::Person(const Position& pos, char type) : type{type}
{ *this->pos = pos; }

Position Person::getPosition() const
{ return *this->pos; }

char Person::getType() const
{ return this->type; }

bool Person::operator==(const Person &other) const
{ return (other.pos->x == this->pos->x && other.pos->y == this->pos->y); }

bool Person::operator!=(const Person &other) const
{ return (this->pos->x != other.pos->x && this->pos->y != other.pos->y); }

Person::~Person() {}