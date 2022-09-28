#include <iostream>
#include <cstdlib>

#ifndef UTILITY_H
#define UTILITY_H

class Utility
{
public:
    size_t randRange(size_t start, size_t end);
    bool wantToPlay(std::string prompt);
    bool continueToPlay(size_t ticks);
private:
};

#endif  /* UTILITY_H */