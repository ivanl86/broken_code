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

    void arrival();

private:
    Building bdg;
    Utility uty;
    size_t pplCount;
    size_t ticks;

};

#endif  /* CONTROLLER_H */