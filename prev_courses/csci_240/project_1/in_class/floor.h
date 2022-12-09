#include "person.h"
#include "array_bag.h"
#include "array_queue.h"

#ifndef FLOOR_H
#define FLOOR_H

class Floor
{
public:
    bool update();
    void add(const Person &);
    Person get();
    void addElevQueue(const Person &);

private:
    ArrayBag<Person> occupants;
    ArrayQueue<Person> elevQueue;
};

#endif  /* FLOOR_H */