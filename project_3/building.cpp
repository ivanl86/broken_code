#include "building.h"

Building::Building()
{
    srand(static_cast<size_t>(time(NULL)));
    initGuards();
    initScientist();
    initSpecOp();
    hasAntidote = false;
}

std::ostream& operator<<(std::ostream &os, const Building &bdg)
{
    os << bdg;
    return os;
}

void Building::move(char move)
{
    hasAntidote = true;
    if (hasAntidote)
    {
        //scientist->getPosition().x = specOp->getPosition().x;
        //scientist->getPosition().y = specOp->getPosition().y;
    }
}

Building::~Building()
{
    delete scientist;
    delete specOp;
}

void Building::initGuards()
{
    guards.resize(MAX_GUARD);
    for (size_t i = 0; i < 6; ++i)
        guards.at(i) = new Lounger(getRandomPosition());
    for (size_t i = 6; i < 10; ++i)
        guards.at(i) = new Hyper(getRandomPosition());
    for (size_t i = 10; i < MAX_GUARD; ++i)
        guards.at(i) = new Aggressor(getRandomPosition());;
}

void Building::initScientist()
{ scientist = new Uninfected({randomRange(4, 5), randomRange(3, 4)}, 'A'); }

void Building::initSpecOp()
{ specOp = new Uninfected({0, 0}, 'O'); }

Position Building::getRandomPosition()
{
    Position pos(randomRange(0, MAX_X), randomRange(0, MAX_Y));
    while ((pos.x + pos.y) <= 2)
        pos = {randomRange(0, MAX_X), randomRange(0, MAX_Y)};

    return pos;
}

bool Building::isInValidRange(char move)
{
    if (specOp->getPosition().x == scientist->getPosition().x);
    return true;
}

size_t Building::randomRange(const size_t &start, const size_t &end)
{
    return rand() % (end - start + 1) + start;
}