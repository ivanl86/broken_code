// who: <your name and Mt SAC username goes here>
// what: <the function of this program>
// why: <the name of the lab>
// when: <the due date of this lab.>
#include <vector>
#include <string>

#ifndef ODIUMS_MANSION_H
#define  ODIUMS_MANSION_H

// If you are on a Microsoft Windows PC, set this to true
//  otherwise, leave it as false
#define WINDOWS true

enum gridSize{MIN_GRID_SIZE = 0, MAX_GRID_SIZE = 8, MIN_ROW = 0, MIN_COL = 0, MAX_ROW = 7, MAX_COL = 7};
enum position{EMPTY = 0, USER_POSITION = 1, GOLD_CHEST_POSITION = 10, ALDRACS_CHAMBER = 20, PIT_POSITION = 30, MAX_PIT = 12};
enum sensation{GLIMMER = 100, STENCH = 200, BREEZE = 300};
enum safeZone{SAFE_ZONE = 2};

class Dungeon
{
private:
    int currRow{0};
    int currCol{0};
    int previousRow{0};
    int previousCol{0};
    bool foundGold{false};
    std::vector<std::vector<int>> grid;
    std::vector<std::vector<std::string>> printedMap;
public:
    void setUserStartingPosition();
    int userStartingPosition();
    int getUserCurrPosition();
    void clearPreviousUserPosition();
    void setGoldPostion();
    void setAldracPosition();
    void setPitPosition();
    void initializeObjectsPosition(Dungeon);

    bool moveRight();
    bool moveLeft();
    bool moveUp();
    bool moveDown();
    bool pickUpGold();
    bool ifFoundGold();
    void printGrid();
    
};

int random(int, int);
void welcomeMessage();
void header();
bool wantToPlay(std::string);
char getChar(std::string);
void play();
bool enterMove(Dungeon);
bool endGame(Dungeon);
bool escaped();
bool killedByAldrac();
bool fallIntoAPit();
void clearScreen();
void clearInstream();

#endif
