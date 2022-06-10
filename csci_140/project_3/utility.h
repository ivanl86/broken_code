#include <iostream>

#include "building.h"

#ifndef UTILITY_H
#define UTILITY_H

#define WINDOWS true /** set to true if using Windows operating system and false otherwise*/

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

    /** print a welcome message */
    void welcome() const;

    /** ask user if want to play the game
     * @return true if user wants to play and false otherwise */
    bool startRescueOrNot(const std::string &prompt) const;

    /** clear the screen each time printing the grid*/
    void clearScreen() const;

    /** clear the instream after each user input */
    void clearInstream() const;

    /** print ending message when the game ends
     * @parameter bdg is used to call the gameStates function
     * to check game conditions to determine win or loss
     * print ending message according to the gameStates */
    void endOfOperation(Building &bdg) const;

private:
    char choice;
    char move;
};

#endif