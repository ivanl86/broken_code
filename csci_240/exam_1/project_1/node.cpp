#include "node.h"

Node::Node(Person *person, Node *nextPerson)
    : person{person}, nextPerson{nextPerson} {}

Node::Node(Person *person)
    : Node(person, nullptr) {}