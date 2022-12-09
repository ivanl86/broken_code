#include <iostream>
#include <cstdlib>

#include "building.h"

#ifndef UTILITY_H
#define UTILITY_H

#define LOBBY 1
#define HIGHEST_FLOOR 50
#define MAX_CAPACITY 6

// enum directions{ idle, down, up };

class Utility
{
public:
    size_t randRange(size_t start, size_t end);
    bool wantToPlay(std::string prompt);
    bool continueToPlay(size_t ticks);
private:
};

#endif  /* UTILITY_H */