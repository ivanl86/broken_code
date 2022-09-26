#include <stdexcept>

#include "person.h"
#include "node.h"
#include "bag.h"
#include "queue.h"

#define LOBBY 1
#define HIGHEST_FLOOR 50

#ifndef FLOORS_H
#define FLOORS_H

class Floors
{
public:
    Floors();
    Bag *floor;
    Queue *elevatorQueue;
private:
};

#endif  /* FLOORS_H */