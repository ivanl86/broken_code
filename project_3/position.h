#include <stddef.h>

struct Position
{
    size_t x;
    size_t y;
    
    Position(size_t x, size_t y) :x{x}, y{y} {}
    Position(Position& other) :x{other.x}, y{other.y} {}
};