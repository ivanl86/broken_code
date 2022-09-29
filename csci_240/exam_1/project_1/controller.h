#include "building.h"
#include "elevator.h"
#include "floors.h"
#include "person.h"
#include "utility.h"

#ifndef CONTROLLER_H
#define CONTROLLER_H

#define LOBBY 1
#define HIGHEST_FLOOR 50
#define MAX_CAPACITY 6

// enum directions{ idle, down, up };

class Controller
{
public:
    Controller(size_t lobby, size_t highestFloor, size_t maxCapacity);
    ~Controller();
    bool newVisitor();
    void setCall();
    void unSetCall(size_t curFloor);
    void embarkElevator(size_t curFloor);
    void disembarkElevator(size_t dstFloor);
    void queueElevator(size_t curFloor);
    void exitBuilding(size_t curFloor);
    void newVisitorMsg();
    void visitorLeavingMsg();
    void exitBuildingMsg();

    size_t lobby;
    size_t highestFloor;
    size_t maxCapacity;

private:
    size_t visitorCount{};
    bool call[HIGHEST_FLOOR + 1] {};
    size_t curCount{};
    Building *bdg;
    Person *visitor;
    Utility uty;
};

#endif  /* CONTROLLER_H */