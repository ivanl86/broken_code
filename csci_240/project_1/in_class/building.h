#include "common.h"
#include "elevator.h"
#include "floor.h"

#ifndef BUILDING_H
#define BUILDING_H

class Building
{
public:
    Building();
    void update();
private:
    bool callSet[FLOOR_QTY];
    Floor floors[FLOOR_QTY];
    Elevator elevator;
};

#endif  /* BUILDING_H */