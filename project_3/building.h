// iostream is only used for the operator<< function.
// Do not print anything directly to cout from this or any other class
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
// #include <stdexcept>
#include <array>

#include "uninfected.h"
#include "infected.h"
#include "person.h"

#include "lounger.h" // added
#include "hyper.h" // added
#include "aggressor.h" // added

#ifndef BUILDING_H
#define BUILDING_H

#define LOUNGER_QTY 6
#define HYPER_QTY 4
#define AGGRESSOR_QTY 2
#define ZOMBIE_QTY LOUNGER_QTY + HYPER_QTY + AGGRESSOR_QTY

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

private:
    std::vector<Infected*> zombies;
    Uninfected* specOp;
    Uninfected* scientist;
    bool hasAntidote;

    void initZombies();
    void initScientist();
    void initSpecOp();
    Position getRandomPosition();
    bool isInValidRange(const char &move);
    bool saveTheScientist();
    bool getInfected();
    void ending();
    size_t randomRange(const size_t &start, const size_t &end);
};

#endif