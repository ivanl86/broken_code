#include "building.h"

Building::Building()
{
    srand(static_cast<size_t>(time(NULL)));
    initSpecOp();
    initScientist();
    initZombies();
    hasAntidote = false;
}

std::ostream& operator<<(std::ostream &os, const Building &bdg)
{
    os << "Rescue mission in progress\n";
    for (size_t x = 0; x <= MAX_X; ++x)
    {
        os << bdg.printHorizontalDivider() << std::endl;
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
            os << bdg.printVerticalDivider() << gridCells;
        }
        os << bdg.printVerticalDivider() << std::endl;
        for (size_t y = 0; y <= MAX_Y; ++y)
        {
            os << bdg.printVerticalDivider() << ' '
               << (bdg.specOp->getPosition().x == x && bdg.specOp->getPosition().y == y ? bdg.specOp->getType() : ' ')
               << (bdg.scientist->getPosition().x == x && bdg.scientist->getPosition().y == y ? bdg.scientist->getType() : ' ');
        }
        os << bdg.printVerticalDivider() << std::endl;;
    }
    os << bdg.printHorizontalDivider() << std::endl;
    return os;
}

void Building::move(char move)
{
    if (!isValidMove(move))
        throw std::runtime_error("");
    if ((move == 'C') && !hasAntidote)
        hasAntidote = true;
    for (size_t i = 0; i < TOTAL_ZOMBIES; ++i)
        zombies.at(i)->move();
    specOp->move(move);
    if (hasAntidote)
        scientist->move(move);
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
        zombies.emplace_back(new Aggressor(getRandomPosition(), specOp));
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
         || (move == 'C' && *specOp == *scientist)
         || (move == 'P'));
}

operationStates Building::operationState()
{
    if (saveTheScientist())
        return ACCOMPLISHED;
    if (getInfected())
        return FAILED;
    return IN_PROGRERSS;
}

bool Building::saveTheScientist()
{ return (hasAntidote && (scientist->getPosition().x == 0 && scientist->getPosition().y == 0)); }

bool Building::getInfected()
{
    for (size_t i = 0; i < TOTAL_ZOMBIES; ++i)
        if ((*zombies.at(i) == *specOp))
            return true;
    return false;
}

size_t Building::randomRange(const size_t &start, const size_t &end)
{ return rand() % (end - start + 1) + start; }

std::string Building::printHorizontalDivider() const
{
    std::stringstream strStream{};
    for (size_t i = 0; i <= MAX_Y; ++i)
        strStream << "----";
    strStream << '-';
    return strStream.str();
}

char Building::printVerticalDivider() const
{
    return '|';
}