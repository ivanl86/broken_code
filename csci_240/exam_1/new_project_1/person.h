#include <cstdlib>

#ifndef PERSON_H
#define PERSON_H

class Person
{
public:
    Person(size_t id, size_t dst);
    size_t getID();
    size_t getDst();

private:
    size_t id;
    size_t dst;
};

#endif  /* PERSON_H */