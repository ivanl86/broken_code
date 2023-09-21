#include "building.h"

#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
public:
    Controller();
    void start();

private:
    Building bdg;
    size_t nextId;
};

#endif  /* CONTROLLER_H */