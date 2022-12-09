#include <stdexcept>

#include "person.h"
#include "node.h"
#include "bag.h"
#include "queue.h"

#ifndef FLOORS_H
#define FLOORS_H

class Floors
{
public:
    Floors();

    Bag occupants;
    Queue queue;

private:
};

#endif  /* FLOORS_H */