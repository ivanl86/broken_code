#include <cstdlib>
#include <ctime>

#ifndef COMMON_H
#define COMMON_H

#define LOBBY 0
#define FLOOR_QTY 50
#define NEW_PERSON_PROBABILITY 0.035
#define EXIT_PROBABILITY 0.015

bool isProbable(double p)
{
    int det{rand() % 1000};
    return det <= static_cast<int>(p * 1000);
}

size_t randRange(size_t start, size_t end)
{
    return rand() % (end - start + 1) + start;
}

#endif  /* COMMON_H */