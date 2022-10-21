#include "floor.h"
#include "common.h"

#ifndef ELEVATOR_H
#define ELEVATOR_H

enum States {IDLE, DELIVER, PICKUP};
enum Directions {STILL, UP, DOWN};

class Elevator
{
public:
    Elevator(Floor[], bool[]);
    void update();

private:
    States currentState;
    Directions currentDir;
    bool *callset;
    Floor *floors;
    size_t currentFloor;

    void idle();
    void deliver();
    void pickup();
    bool noneWaiting();
    bool noneLobbyWaiting();
};

#endif  /* ELEVATOR_H */