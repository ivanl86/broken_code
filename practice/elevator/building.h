#include <cstdint>

#include "floors.h"
#include "elevator.h"
#include "utility.h"

#ifndef BUILDING_H
#define BUILDING_H

class Building {
public:
    Building();
    void add(const Person& p);
    void update();
private:
    Floors floors[FLOOR_QTY];
    bool callSet[FLOOR_QTY];
    Elevator elevator;
};

#endif  /* BUILDING_H */