#include <stddef.h>

#ifndef POSITION_H
#define POSITION_H

#define MAX_X 9
#define MAX_Y 7

struct Position
{
    size_t x;
    size_t y;
    
    Position(size_t x, size_t y);
    Position(const Position& other);
};

#endif