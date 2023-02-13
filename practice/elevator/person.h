#include <cstdint>

#ifndef PERSON_H
#define PERSON_H

class Person {
public:
    Person() = default;
    Person(uint64_t id, uint64_t dest)
        : id{id}, dest{dest} {}

    uint64_t id;
    uint64_t dest;
};

#endif  /* PERSON_H */