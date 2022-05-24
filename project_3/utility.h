#include <iostream>
#include "building.h"

#ifndef UTILITY_H
#define UTILITY_H

class Utility
{
public:
    Utility();
    ~Utility();
    char getMove(const std::string &prompt);
    bool wantToPlayOrNot(const std::string &prompt);
    void clearScreen();
    void clearInstream();
    void endOfOperation(Building &) const;

private:
    char choice;
    char move;
};

#endif