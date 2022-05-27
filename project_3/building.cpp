#include "building.h"

#define O 'O'
#define S 'S'

Building::Building()
{
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
        os << bdg.HorizontalWall() << std::endl;
        for (size_t y = 0; y <= MAX_Y; ++y)
        {
            std::string cell{"   "};
            for (Infected *z : bdg.zombies)
            {
                if (z->getType() == L && cell.at(LEFT_CORNER) != L && z->getPosition().x == x && z->getPosition().y == y)
                    cell.at(LEFT_CORNER) = z->getType();
                if (z->getType() == H && cell.at(MIDDLE_SPACE) != H && z->getPosition().x == x && z->getPosition().y == y)
                    cell.at(MIDDLE_SPACE) = z->getType();
                if (z->getType() == A && cell.at(RIGHT_CORNER) != A && z->getPosition().x == x && z->getPosition().y == y)
                    cell.at(RIGHT_CORNER) = z->getType();
            }
            os << bdg.VerticalWall() << cell;
        }
        os << bdg.VerticalWall() << std::endl;
        for (size_t y = 0; y <= MAX_Y; ++y)
        {
            os << bdg.VerticalWall() << ' '
               << (bdg.specOp->getPosition().x == x && bdg.specOp->getPosition().y == y ? bdg.specOp->getType() : ' ')
               << (bdg.scientist->getPosition().x == x && bdg.scientist->getPosition().y == y ? bdg.scientist->getType() : ' ');
        }
        os << bdg.VerticalWall() << std::endl;;
    }
    os << bdg.HorizontalWall() << std::endl;
    return os;
}

void Building::move(char move)
{
    if (!isValidMove(move))
        throw std::invalid_argument("Invalid move!\n");
    if ((move == 'C') && !hasAntidote)
        hasAntidote = true;
    for (Infected *z : zombies)
        z->move();
    specOp->move(move);
    if (hasAntidote)
        scientist->move(move);
}

Building::~Building()
{
    for (Infected *z : zombies)
        delete z;
    zombies.clear();
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
{ scientist = new Uninfected({randomRange(4, 5), randomRange(3, 4)}, S); }

void Building::initSpecOp()
{ specOp = new Uninfected({0, 0}, O); }

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

operationStates Building::operationState() const
{
    if (saveTheScientist())
        return ACCOMPLISHED;
    if (getInfected())
        return FAILED;
    return IN_PROGRERSS;
}

bool Building::saveTheScientist() const
{ return (hasAntidote && (scientist->getPosition().x == 0 && scientist->getPosition().y == 0)); }

bool Building::getInfected() const
{
    for (Infected *z : zombies)
        if ((*z == *specOp))
            return true;
    return false;
}

size_t Building::randomRange(const size_t &start, const size_t &end)
{ return rand() % (end - start + 1) + start; }

std::string Building::HorizontalWall() const
{
    std::stringstream strStream{};
    for (size_t i = 0; i <= MAX_Y; ++i)
        strStream << "----";
    strStream << '-';
    return strStream.str();
}

char Building::VerticalWall() const
{
    return '|';
}