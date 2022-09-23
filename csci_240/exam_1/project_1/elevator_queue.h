#include <stdexcept>

#include "node.h"
#include "person.h"

#ifndef ELEVATOR_QUEUE_H
#define ELEVATOR_QUEUE_H

class ElevatorQueue
{
public:
    ElevatorQueue();
    void enqueue(Person person);
    Person dequeue();
    bool empty();
private:
    Node *frontPtr;
    Node *backPtr;
};

#endif  /* ELEVATOR_QUEUE_H */