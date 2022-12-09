#include "floors.h"
#include "elevator.h"
#include "person.h"

#ifndef BUILDING_H
#define BUILDING_H

#define FLOOR_QTY 50

class Building
{
public:
    Building();
    Floors *floors;
    Elevator *elevator;
private:
};

#endif  /* BUILDING_H */