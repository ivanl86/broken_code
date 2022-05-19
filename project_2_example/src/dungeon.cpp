
#include <cstdlib>
#include <stdexcept>

#include "dungeon.h"
#include "position.h"

void Dungeon::init()
{
    user = {0, 0};
    initPercept();
    initArtifacts();
    hasGold = false;
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
    initPits();
    p = getRandomPosition();
    artifacts[p.x][p.y] = ALDRAC;
    p = getRandomPosition();
    artifacts[p.x][p.y] = GOLD;
}

void Dungeon::initPits()
{
    Position p{getRandomPosition()};
    for (size_t i = 0; i < PIT_QTY; ++i)
        artifacts[p.x][p.y] = PIT;
}

Position Dungeon::getRandomPosition()
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

int Dungeon::randomRange(int start, int end)
{
    return rand() % (end - start) + start;
}

bool Dungeon::isValidMove(const Position &dest)
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
    else
        user = dest;
}

void Dungeon::pickup()
{
    if (artifacts[user.x][user.y] != GOLD)
        throw std::invalid_argument("Bad move!");
    hasGold = true;
}