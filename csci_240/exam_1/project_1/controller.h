#include "building.h"
#include "elevator.h"
#include "floors.h"
#include "person.h"
#include "utility.h"

#ifndef CONTROLLER_H
#define CONTROLLER_H

// enum directions{ idle, down, up };

class Controller
{
public:
    Controller();
    ~Controller();
    void update();
    bool newVisitor();
    void setCall();
    void unSetCall();
    void embarkElevator();
    void disembarkElevator();
    void queueElevator();
    void exitBuilding();
    void newVisitorMsg();
    void visitorLeavingMsg();
    void visitorEnterFloorMsg();
    void exitBuildingMsg();
    void updateCurFloor();
    void updateCurDrt();
    void updateCurOp();
    void updateCounter();

private:
    size_t visitorCount;
    //bool call[HIGHEST_FLOOR + 1] {};
    size_t curCount;
    size_t curFloor;
    Building *bdg;
    Person *visitor;
    Utility uty;
    size_t transitCounter;
    size_t embarkCounter;
    size_t disembarkCounter;
    size_t ticks;
    Directions curDrt;
    Operations curOp;
};

#endif  /* CONTROLLER_H */