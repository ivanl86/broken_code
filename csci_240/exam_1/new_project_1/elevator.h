#include "bag.h"
#include "person.h"

#ifndef ELEVATOR_H
#define ELEVATOR_H

#define LOBBY 1
#define TOP_FLOOR 50
#define FLOOR_IDX 51
#define MAX_CAPACITY 6

enum Drt{ STILL, DOWN, UP };
enum State{ IDLE, IN_TRANSIT, EMBARKING, DISEMBARKING };

class Elevator
{
public:
    Elevator();

    Bag occupants;
    bool call[FLOOR_IDX];
    size_t count;
    Drt drt;
    State state;

private:
};

#endif  /* ELEVATOR_H */