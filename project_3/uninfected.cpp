#include "uninfected.h"

Uninfected::Uninfected(const Position &pos, char type) : Person(pos, type)
{}

void Uninfected::move(char move)
{
    switch (move)
    {
    case 'N':
        //setPosition({this->pos->x - 1, this->pos->y});
        this->pos->x -= 1;
        break;
    case 'S':
        //setPosition({this->pos->x + 1, this->pos->y});
        this->pos->x += 1;
        break;
    case 'E':
        //setPosition({this->pos->x, this->pos->y + 1});
        this->pos->y += 1;
        break;
    case 'W':
        //setPosition({this->pos->x, this->pos->y - 1});
        this->pos->y -= 1;
        break;
    case 'C':
    case 'P':
        break;
    }
}

Uninfected::~Uninfected()
{}