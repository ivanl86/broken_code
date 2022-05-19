#include <stddef.h>

#ifndef POSITION_H
#define POSITION_H

#define ROW_QTY 10
#define COL_QTY 8

struct Position
{
    size_t x;
    size_t y;
    
    Position(size_t x, size_t y) :x{x}, y{y} {}
    Position(Position& other) : x{other.x}, y{other.y} {}
};

#endif