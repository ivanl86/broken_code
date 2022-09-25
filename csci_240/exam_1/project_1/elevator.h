#include "bag.h"
#include "person.h"

#ifndef ELEVATOR_H
#define ELEVATOR_H

#define LOBBY 1
#define HIGHEST_FLOOR 50
#define MAX_CAPACITY 6

class Elevator
{
public:
    Elevator();
    void set(Person person);
    void unset(Person person);

private:
    bool call[HIGHEST_FLOOR + 1];
    Bag *elevator;
    size_t currentCapacity;
};

#endif  /* ELEVATOR_H */