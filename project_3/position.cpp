#include "position.h"

Position::Position(size_t x, size_t y) : x{x}, y{y}
{}

Position::Position(const Position& other) : x{other.x}, y{other.y}
{}