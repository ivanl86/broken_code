#include <stdexcept>

#include "node.h"
#include "person.h"

#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
public:
    Queue();
    void enqueue(Person *person);
    Person *dequeue();
    bool empty();
private:
    Node *frontPtr;
    Node *backPtr;
};

#endif  /* QUEUE_H */