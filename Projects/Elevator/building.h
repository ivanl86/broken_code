#include "floors.h"
#include "elevator.h"

#ifndef BUILDING_H
#define BUILDING_H

class Building
{
public:
    Building();

    Floors floors[FLOOR_INDX];
    Elevator elevator;
private:

};

#endif  /* BUILDING_H */