#include "person.h"

Person::Person(size_t id, unsigned int dst)
      : ID{id}, floorDst{dst} {}

size_t Person::getID()
{ return ID; }

unsigned int Person::getDst()
{ return floorDst; }