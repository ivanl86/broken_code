
#include <cstdlib>
#include <stdexcept>
#include <sstream>

#include "dungeon.h"
#include "position.h"

Dungeon::Dungeon()
{ init(); }

void Dungeon::init()
{
    user = {0, 0};
    initPercept();
    initArtifacts();
    hasGold = false;
    state = IN_PLAY;
}

void Dungeon::initPercept()
{
    for (size_t row = 0; row < ROW_QTY; ++row)
        for (size_t col = 0; col < COL_QTY; ++col)
            percept[row][col] = "     ";    
}

void Dungeon::initArtifacts()
{
    Position p;
    initDungeon();
    initPits();
    p = getRandomPosition();
    artifacts[p.x][p.y] = ALDRAC;
    p = getRandomPosition();
    artifacts[p.x][p.y] = GOLD;
}

void Dungeon::initPits()
{
    Position p;
    for (size_t i = 0; i < PIT_QTY; ++i)
    {
        p = getRandomPosition();
        artifacts[p.x][p.y] = PIT;
    }
        
}

void Dungeon::update()
{
    // set game state (win loss in-play)
    // update percepts
    updatePercepts();
    updateState();
}

void Dungeon::initDungeon()
{
    for (size_t row = 0; row < ROW_QTY; ++row)
        for (size_t col = 0; col < COL_QTY; ++col)
            artifacts[row][col] = EMPTY;
}

void Dungeon::updateState()
{
    if ((artifacts[user.x][user.y] == EMPTY) || (artifacts[user.x][user.y] == GOLD))
        state = IN_PLAY;
    else if (artifacts[user.x][user.y] != EMPTY)
        state = LOSS;
    if (hasGold && user.x == 0 && user.y == 0)
        state = WIN;
}

void Dungeon::updatePercepts()
{
    Position p{user};
    Artifact a[4]{};
    std::string *userPercept{&percept[user.x][user.y]};
    if (isValidMove({p.x - 1, p.y}))
        a[0] = artifacts[p.x - 1][p.y];
    if (isValidMove({p.x + 1, p.y}))
        a[1] = artifacts[p.x + 1][p.y];
    if (isValidMove({p.x, p.y - 1}))
        a[2] = artifacts[p.x][p.y - 1];
    if (isValidMove({p.x, p.y + 1}))
        a[3] = artifacts[p.x][p.y + 1];
    for (size_t i = 0; i < sizeof(a); ++i)
    {
        if (a[i] == ALDRAC)
            userPercept[0] = 'S';
        if (a[i] == GOLD)
            userPercept[2] = 'G';
        if (a[i] == PIT)
            userPercept[4] = 'B';
    }
}

Position Dungeon::getRandomPosition() const
{
    int count{0};
    int px;
    int py;
    do
    {
        px = randomRange(0, ROW_QTY);
        py = randomRange(0, COL_QTY);
    } while (artifacts[px][py] !=  0 ||  px + py <= 1);

    return {px, py};
}

int Dungeon::randomRange(int start, int end) const
{
    return rand() % (end - start) + start;
}

bool Dungeon::isValidMove(const Position &dest) const
{
    return (abs(user.x - dest.x) + abs(user.y - dest.y)) < 2
        // && (user.x == user.x || user.y == dest.y)
        && dest.x >= 0 && dest.y >= 0
        && dest.x <= ROW_QTY && dest.y <= COL_QTY;
}

void Dungeon::move(const Position &dest)
{
    if (!isValidMove(dest))
        throw std::invalid_argument("Bad move!");
    user = dest;
    update();
}

void Dungeon::pickup()
{
    if (artifacts[user.x][user.y] != GOLD)
        throw std::invalid_argument("Bad move!");
    hasGold = true;
}

std::string getDivider()
{
    std::stringstream ss;
    for (size_t i = 0; i < COL_QTY; ++i)
        ss << "------";
    ss << '-';
    return ss.str();
}

std::string Dungeon::toString()
{
    std::stringstream ss;
    for (size_t row = 0; row < ROW_QTY; ++row)
    {
        ss << getDivider() << std::endl;
        for (size_t col = 0; col < COL_QTY; ++col)
            ss << '|' << percept[row][col];

        ss << "|\n";

        for (size_t col = 0; col < COL_QTY; ++col)
            ss << ((user.x == row && user.y == col) ? "| u " : "|   ");

        ss << "|\n";
    }
    ss << getDivider() << std::endl;
    ss << ((!hasGold) ? "You are carrying the gold!\n" : "\n");
    return ss.str();
}