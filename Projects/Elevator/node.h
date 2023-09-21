#include "person.h"

#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Person person;
    Node *nextPerson;

    Node(Person person, Node *nextPerson);
    Node(Person person);
private:

};

#endif  /* NODE_H */