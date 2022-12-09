#include "building.h"
#include "utility.h"

#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
public:
    Controller();
    void play();
    void setCall();
    void arrival();
    void departure();
    void enterFloor();
    void enterQueue(size_t f);
    void enterElevator();
    void printElevatorState();
    void printCurFloor();

    Building bdg;
    Utility uty;
    size_t ticks;
    size_t arrivalCount;
    size_t prvFloor;

private:

};

#endif  /* CONTROLLER_H */