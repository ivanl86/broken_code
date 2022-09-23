#include <cstdlib>

#ifndef PERSON_H
#define PERSON_H

class Person
{
public:
    Person(size_t ID, unsigned int floorDst);
    size_t getID();
    unsigned int getDst();
private:
    size_t ID;
    unsigned int floorDst;
};

#endif  /* PERSON_H */