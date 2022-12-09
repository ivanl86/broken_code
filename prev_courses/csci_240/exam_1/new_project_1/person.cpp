#include "person.h"

Person::Person(size_t id, size_t dst)
      : id{id}, dst{dst} {}

size_t Person::getID()
{ return id; }

size_t Person::getDst()
{ return dst; }