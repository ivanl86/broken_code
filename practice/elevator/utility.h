#include <cstdint>
#include <cstdlib>

#ifndef UTILITY_H
#define UTILITY_H

#define LOBBY 0
#define FLOOR_QTY 50
#define TOP_FLOOR (FLOOR_QTY - 1)
#define NEW_PERSON_PROBABILITY 0.035
#define EXIT_PROBABILITY 0.015

bool isProbable(double d) {
    uint64_t rng{rand() % 1000};
    return rng <= static_cast<uint64_t>(d * 1000);
}


#endif  /* UTILITY_H */
