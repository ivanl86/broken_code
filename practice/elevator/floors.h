#include "arraybag.h"
#include "linkedqueue.h"
#include "person.h"
#include "utility.h"

#ifndef FLOORS_H
#define FLOORS_H

class Floors {
public:
    bool update();
    void addElevatorQueue(const Person& p);
    Person removeElevatorQueue(); 
    void addOccupant(const Person& p);
    Person removeOccupant(const Person& p);
private:
    ArrayBag<Person> occupants;
    LinkedQueue<Person> elevatorQueue;
};

#endif  /* FLOORS_H */