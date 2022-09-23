#include "person.h"
#include "node.h"

#ifndef FLOORS_H
#define FLOORS_H

class Floors
{
public:
    Floors();
    void arrive(Person person);
    Person depart();
    bool empty();
private:
    Node *floor;
};

#endif  /* FLOORS_H */