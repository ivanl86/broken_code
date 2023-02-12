#include "floors.h"
#include "utility.h"

#ifndef BUILDING_H
#define BUILDING_H

class Building {
public:

private:
    Floors floors[FLOOR_QTY];
    bool callSet[FLOOR_QTY];
};

#endif  /* BUILDING_H */