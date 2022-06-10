

#ifndef POSITION_H
#define POSITION_H

struct Position
{
    int x;
    int y;

    Position() {}
    Position(int x, int y) : x{x}, y{y} {}
    Position(const Position &p) : x{p.x}, y{p.y} {}

    bool operator==(const Position &p) { return p.x == x && p.y == y; }
    bool operator!=(const Position &p) { return !(p.x == x && p.y == y); }
};

#endif