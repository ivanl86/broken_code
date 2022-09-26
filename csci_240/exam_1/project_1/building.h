#include "floors.h"
#include "elevator.h"
#include "person.h"
#include "utility.h"

#ifndef BUILDING_H
#define BUILDING_H

class Building
{
public:
    Building();
    Floors *floor;
    Elevator *elevator;
private:
};

#endif  /* BUILDING_H */