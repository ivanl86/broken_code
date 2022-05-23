#include "building.h"

Building::Building()
{
    srand(static_cast<size_t>(time(NULL)));
    initZombies();
    initScientist();
    initSpecOp();
    hasAntidote = false;
    gridCells = "   ";
}

std::ostream& operator<<(std::ostream &os, const Building &bdg)
{
    os << "Rescue mission in progress\n";
    for (size_t x = 0; x <= MAX_X; ++x)
    {
        os << "---------------------------------\n";
        for (size_t y = 0; y <= MAX_Y; ++y)
        {
            std::string gridCells{"   "};
            for (size_t l = LOUNGER_FISRT; l <= LOUNGER_LAST; ++l)
                if (gridCells.at(LEFT_CELL) != bdg.zombies.at(l)->getType() && (bdg.zombies.at(l)->getPosition().x == x && bdg.zombies.at(l)->getPosition().y == y))
                    gridCells.at(LEFT_CELL) = bdg.zombies.at(l)->getType();
            for (size_t h = HYPER_FISRT; h <= HYPER_LAST; ++h)
                if (gridCells.at(MIDDLE_CELL) != bdg.zombies.at(h)->getType() && (bdg.zombies.at(h)->getPosition().x == x && bdg.zombies.at(h)->getPosition().y == y))
                    gridCells.at(MIDDLE_CELL) = bdg.zombies.at(h)->getType();
            for (size_t a = AGGRESSOR_FISRT; a <= AGGRESSOR_LAST; ++a)
                if (gridCells.at(RIGHT_CELL) != bdg.zombies.at(a)->getType() && (bdg.zombies.at(a)->getPosition().x == x && bdg.zombies.at(a)->getPosition().y == y))
                    gridCells.at(RIGHT_CELL) = bdg.zombies.at(a)->getType();
            os << '|' << gridCells;
        }
        os << "|\n";
        for (size_t y = 0; y <= MAX_Y; ++y)
        {
            os << "| "
               << (bdg.specOp->getPosition().x == x && bdg.specOp->getPosition().y == y ? bdg.specOp->getType() : ' ')
               << (bdg.scientist->getPosition().x == x && bdg.scientist->getPosition().y == y ? bdg.scientist->getType() : ' ');
        }
        os << "|\n";
    }
    os << "---------------------------------\n";
    return os;
}

void Building::move(char move)
{
    if (!isValidMove(move))
        throw std::runtime_error("");
    if ((move == 'C') && !hasAntidote)
        hasAntidote = true;
    specOp->move(move);
    if (hasAntidote)
        scientist->move(move);
    for (size_t i = 0; i < TOTAL_ZOMBIES; ++i)
        zombies.at(i)->move();
}

Building::~Building()
{
    delete scientist;
    delete specOp;
}

void Building::initZombies()
{
    zombies.reserve(TOTAL_ZOMBIES);
    for (size_t i = 0; i < LOUNGER_QTY; ++i)
        zombies.emplace_back(new Lounger(getRandomPosition()));
    for (size_t i = 0; i < HYPER_QTY; ++i)
        zombies.emplace_back(new Hyper(getRandomPosition()));
    for (size_t i = 0; i < AGGRESSOR_QTY; ++i)
        zombies.emplace_back(new Aggressor(getRandomPosition()));
}

void Building::initScientist()
{ scientist = new Uninfected({randomRange(4, 5), randomRange(3, 4)}, 'S'); }

void Building::initSpecOp()
{ specOp = new Uninfected({0, 0}, 'O'); }

Position Building::getRandomPosition()
{
    Position pos(randomRange(0, MAX_X), randomRange(0, MAX_Y));
    while ((pos.x + pos.y) < 2)
        pos = {randomRange(0, MAX_X), randomRange(0, MAX_Y)};
    return pos;
}

bool Building::isValidMove(const char &move)
{
    return ((move == 'N' && specOp->getPosition().x > 0)
         || (move == 'S' && specOp->getPosition().x < MAX_X)
         || (move == 'E' && specOp->getPosition().y < MAX_Y)
         || (move == 'W' && specOp->getPosition().y > 0)
         || (move == 'C' && specOp->getPosition().x == scientist->getPosition().x && specOp->getPosition().y == scientist->getPosition().y)
         || (move == 'P'));
}

bool Building::saveTheScientist()
{ return (hasAntidote && (scientist->getPosition().x == 0 && scientist->getPosition().y == 0)); }

bool Building::getInfected()
{
    for (size_t i = 0; i < TOTAL_ZOMBIES; ++i)
        if ((zombies.at(i)->getPosition().x == specOp->getPosition().x) && (zombies.at(i)->getPosition().y == specOp->getPosition().y))
            return true;
    return false;
}

size_t Building::randomRange(const size_t &start, const size_t &end)
{ return rand() % (end - start + 1) + start; }