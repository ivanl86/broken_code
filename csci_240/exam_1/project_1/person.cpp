#include "person.h"

Person::Person(size_t id, unsigned int dst)
      : id{id}, floorDst{dst} {}

size_t Person::getID()
{ return id; }

unsigned int Person::getDst()
{ return floorDst; }