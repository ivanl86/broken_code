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
    ~Controller();
    void newVisitor();
    void setCall(size_t curFloor);
    void unSetCall();
    void embarkElevator(size_t curFloor);
    void disembarkElevator(size_t dstFloor);
    void queueElevator(size_t curFloor);

private:
    size_t visitorCount;
    bool goUp;
    bool call[HIGHEST_FLOOR + 1] {};
    Building *bdg;
    Person *visitor;
    Utility uty;
};

#endif  /* CONTROLLER_H */