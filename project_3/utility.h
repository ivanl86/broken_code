#include <iostream>
#include "building.h"

#ifndef UTILITY_H
#define UTILITY_H

#define WINDOWS true

class Utility
{
public:
    /** Utility constructor */
    Utility();

    /** Utility destructor */
    ~Utility();

    /** ask user input to make a move for the specOp
     * only accept 6 input: 'N', 'S', 'E', 'W', 'P' and 'C'
     * @parameter prompt is to ask for user input
     * @return one of the six chars */
    char getMove(const std::string &prompt);

    /** ask user if want to play the game
     * @return true if user wants to play and false otherwise */
    bool wantToPlayOrNot(const std::string &prompt);

    /** clear the screen each time printing the grid*/
    void clearScreen() const;

    /** clear the instream after each user input */
    void clearInstream() const;

    /** print ending message when the game ends
     * @parameter bdg is used to call the gameStates function
     * to check win and loss conditin
     * print ending message according to the gameStates */
    void endOfOperation(Building &bdg) const;

private:
    char choice;
    char move;
};

#endif