#include "uninfected.h"

Uninfected::Uninfected(const Position &pos, char type) : Person(pos, type)
{}

void Uninfected::move(const char move)
{
    switch (move)
    {
    case 'N':
        if (pos->y != 0)
            pos->y -= 1;
        else
            throw std::runtime_error("");
    case 'S':
        if (pos->y != 9)
            pos->y += 1;
        else
            throw std::runtime_error("");
    case 'E':
        if (pos->x != 7)
            pos->x += 1;
        else
            throw std::runtime_error("");
    case 'W':
        if (pos->x != 0)
            pos->x -= 1;
        else
            throw std::runtime_error("");
    case 'P':
        break;
    case 'C':
        if (!carry)
            carry = true;
        break;
    }
}

Uninfected::~Uninfected()
{}