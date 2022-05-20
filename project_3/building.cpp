#include "building.h"

Building::Building()
{
    srand(static_cast<size_t>(time(NULL)));
    initZombies();
    initScientist();
    initSpecOp();
    hasAntidote = false;
}

std::ostream& operator<<(std::ostream &os, const Building &bdg)
{
    os << "Rescue mission in progress\n";
    return os;
}

void Building::move(char move)
{
    if (!isInValidRange(move))
        throw std::runtime_error("");
    if ((move == 'C') && !hasAntidote)
        hasAntidote = true;
    specOp->move(move);
    if (hasAntidote)
        scientist->move(move);
    for (size_t i = 0; i < MAX_ZOMBIE_QTY; i++)
        zombies.at(i)->move();
}

Building::~Building()
{
    delete scientist;
    delete specOp;
}

void Building::initZombies()
{
    zombies.reserve(MAX_ZOMBIE_QTY);
    for (size_t i = 0; i < MAX_LOUNGER_QTY; ++i)
        zombies.emplace_back(new Lounger(getRandomPosition()));
    for (size_t i = 0; i < MAX_HYPER_QTY; ++i)
        zombies.emplace_back(new Hyper(getRandomPosition()));
    for (size_t i = 0; i < MAX_AGGRESSOR_QTY; ++i)
        zombies.emplace_back(new Aggressor(getRandomPosition()));
}

void Building::initScientist()
{ scientist = new Uninfected({randomRange(4, 5), randomRange(3, 4)}, 'A'); }

void Building::initSpecOp()
{ specOp = new Uninfected({0, 0}, 'O'); }

Position Building::getRandomPosition()
{
    Position pos(randomRange(0, MAX_X), randomRange(0, MAX_Y));
    while ((pos.x + pos.y) < 2)
        pos = {randomRange(0, MAX_X), randomRange(0, MAX_Y)};
    return pos;
}

bool Building::isInValidRange(char move)
{
    return ((move == 'N' && specOp->getPosition().x > 0)
         || (move == 'S' && specOp->getPosition().x < (MAX_X - 1))
         || (move == 'E' && specOp->getPosition().y < (MAX_Y - 1))
         || (move == 'W' && specOp->getPosition().x > 0)
         || (move == 'C' && specOp->getPosition().x == scientist->getPosition().x && specOp->getPosition().y == scientist->getPosition().y)
         || (move == 'P'));
}

size_t Building::randomRange(const size_t &start, const size_t &end)
{
    return rand() % (end - start + 1) + start;
}