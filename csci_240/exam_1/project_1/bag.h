#include <stdexcept>

#include "node.h"
#include "person.h"

#ifndef BAG_H
#define BAG_H

class Bag
{
public:
    Bag();
    void embark(Person person);
    Person disembark();
    bool empty();
    void clear();

private:
    Node *head;
};

#endif  /* BAG_H */