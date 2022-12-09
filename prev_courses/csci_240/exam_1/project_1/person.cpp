#include "person.h"

Person::Person(size_t id, unsigned int dst)
      : id{id}, dst{dst} {}

size_t Person::getID()
{ return id; }

size_t Person::getDst()
{ return dst; }