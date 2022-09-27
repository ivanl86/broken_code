#include "building.h"
#include "elevator.h"
#include "floors.h"
#include "person.h"
#include "utility.h"

#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
public:
    Controller();
    void newVisitor();
    void setCall();
    void unSetCall();
    void embarkElevator(size_t currentFloor);
    void disembarkElevator(size_t dstFloor);
    void queueElevator(size_t currentFloor);

private:
    size_t tick;
    bool goUp;
    Building *bdg;
    Person *visitor;
    Utility uty;
};

#endif  /* CONTROLLER_H */