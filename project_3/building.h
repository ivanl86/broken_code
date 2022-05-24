// iostream is only used for the operator<< function.
// Do not print anything directly to cout from this or any other class
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <array>

#include "uninfected.h"
#include "infected.h"
#include "person.h"

#include "lounger.h" // added
#include "hyper.h" // added
#include "aggressor.h" // added

#ifndef BUILDING_H
#define BUILDING_H

enum zombieQtys {LOUNGER_QTY = 6, HYPER_QTY = 4, AGGRESSOR_QTY = 2, TOTAL_ZOMBIES = LOUNGER_QTY + HYPER_QTY + AGGRESSOR_QTY};
enum zombieIndexes {LOUNGER_FISRT = 0, LOUNGER_LAST = 5, HYPER_FISRT = 6, HYPER_LAST = 9, AGGRESSOR_FISRT = 10, AGGRESSOR_LAST = 11};
enum gridCells {LEFT_CELL = 0, MIDDLE_CELL = 1, RIGHT_CELL =2};
enum operationStates {IN_PROGRERSS, ACCOMPLISHED, FAILED};

// this class does not provide UI nor does it contain main. 
class Building
{
    /** stream insertion operator overload */
    friend std::ostream& operator<<(std::ostream&, const Building&);  
    
public:
    /** Building constructor. Initializes the Building */ 
    Building();

    /** move the position of the spec-op
     @ parameter move the direction in which the spec-op must move: must be a valid move
     @ throws invalid_argument exception if move is invalid */ 
    void move(char move);

    /** Building destructor. Deletes all heap based objects (including guards) */
    ~Building();

    operationStates operationState();

private:
    std::vector<Infected*> zombies;
    Uninfected* specOp;
    Uninfected* scientist;
    bool hasAntidote;

    void initZombies();
    void initScientist();
    void initSpecOp();
    Position getRandomPosition();
    bool isValidMove(const char &move);

    bool saveTheScientist();
    bool getInfected();      
    size_t randomRange(const size_t &start, const size_t &end);

    std::string printHorizontalDivider() const;
    std::string printVerticalDivider();
};

#endif