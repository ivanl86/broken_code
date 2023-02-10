#include "linkedqueue.h"
#include "priorityqueue.h"
#include "person.h"

#ifndef FLOORS_H
#define FLOORS_H

class Floors {
public:
    void queuingElevator();
    
private:
    LinkedQueue<Person> occupants;
    PriorityQueue<Person> elevatorQueue;
};

#endif  /* FLOORS_H */