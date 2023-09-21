#include <cstdlib>

#ifndef PERSON_H
#define PERSON_H

struct Person
{
    size_t id;
    size_t dst;

    Person() = default;
    Person(size_t id, size_t dst) : id{id}, dst{dst} {}

    bool operator==(const Person &other) {return id == other.id; }
};

#endif  /* PERSON_H */