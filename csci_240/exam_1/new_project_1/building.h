#include "floors.h"
#include "elevator.h"
#include "person.h"

#ifndef BUILDING_H
#define BUILDING_H

#define LOBBY 1
#define TOP_FLOOR 50
#define FLOOR_IDX 51

class Building
{
public:
    Building();

    Floors floors[FLOOR_IDX];
    Elevator elevator;
    size_t pplCount;

private:
};

#endif  /* BUILDING_H */