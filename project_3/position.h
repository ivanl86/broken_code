#include <stddef.h>

#ifndef POSITION_H
#define POSITION_H

#define MAX_X 10
#define MAX_Y 8

struct Position
{
    size_t x;
    size_t y;
    
    Position(size_t x, size_t y);
    Position(Position& other);
};

#endif