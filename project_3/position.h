#include <stddef.h>

#ifndef POSITION_H
#define POSITION_H

#define MAX_X 9 /** the maximum value of the x */
#define MAX_Y 7 /** the maximum value of the y */

struct Position
{
    size_t x;
    size_t y;
    
    Position(size_t x, size_t y);
    Position(const Position& other);
};

#endif