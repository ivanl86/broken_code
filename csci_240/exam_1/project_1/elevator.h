#include "bag.h"
#include "person.h"

#ifndef ELEVATOR_H
#define ELEVATOR_H

#define LOBBY 1
#define HIGHEST_FLOOR 50
#define MAX_CAPACITY 6

enum Directions{ STILL, UP, DOWN };
enum Operations{ IDLE, IN_TRANSIT, EMBARKING, DISEMBARKING };

class Elevator
{
public:
    Elevator();
    void set(Person *person);
    void unset(Person *person);
    void increCapacity();
    void decreCapacity();
    size_t getCurCapacity();
    void clearCapacity();

    Bag *occupants;
    bool call[HIGHEST_FLOOR + 1];
    size_t curCount;
    size_t curFloor;

private:
};

#endif  /* ELEVATOR_H */