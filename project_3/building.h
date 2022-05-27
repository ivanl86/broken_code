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

#define O 'O' /** O represents specOp in the game */
#define S 'S' /** S represents scientist in the game */

#ifndef BUILDING_H
#define BUILDING_H

enum zombieQtys {LOUNGER_QTY = 6, HYPER_QTY = 4, AGGRESSOR_QTY = 2, TOTAL_ZOMBIES = LOUNGER_QTY + HYPER_QTY + AGGRESSOR_QTY};
enum cell {LEFT_CORNER = 0, MIDDLE_SPACE = 1, RIGHT_CORNER =2};
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

    /** track the current state of the game
     @ return enum operationStates */
    operationStates operationState() const;

private:
    std::vector<Infected*> zombies;
    Uninfected* specOp;
    Uninfected* scientist;
    bool hasAntidote;

    /** initialize vector of zombies objects */
    void initZombies();

    /** initialize scientest object */
    void initScientist();

    /** initialize specOp object */
    void initSpecOp();

    /** generate random position to randomlize the starting positin of the scientist and the zombies objects*/
    Position getRandomPosition();

    /** check if user input is valid to move the specOp*/
    bool isValidMove(const char &move);

    /** return true if scientist is at the position {0, 0} and false otherwise*/
    bool saveTheScientist() const;

    /** return true if specOp is in the same cell as the zombies and false otherwise*/
    bool getInfected() const;

    /** random number generator
     * @ return a number between start to end inclusive */
    size_t randomRange(const size_t &start, const size_t &end);

    /** Return a horizontal line. Used in the ostream function*/
    std::string HorizontalWall() const;

    /** Return a vertical line. Used in the ostream function*/
    char VerticalWall() const;
};

#endif