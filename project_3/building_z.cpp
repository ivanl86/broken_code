// who: Ivan Leung ileung2
// what: Building Z
// why: Project 3
// when: May/29/2022

#include <iostream>

#include "building.h"
#include "utility.h"

int main(int argc, char const *argv[])
{
    srand(static_cast<size_t>(time(NULL)));
    Utility utility;
    utility.welcome();
    if (utility.startRescueOrNot("Do you want to start the rescue operation in Building Z? (Y/N): "))
        do
        {
            utility.clearScreen();
            Building bdg;
            std::cout << bdg << std::endl;
            do 
            {
                try
                {
                    bdg.move(utility.getMove("Your move [N,S,W,E,P,C]: "));
                    utility.clearInstream();
                }
                catch (const std::invalid_argument e)
                { std::cerr << "Invalid move!\n"; }
                utility.clearScreen();
                std::cout << bdg << std::endl;
            } while (bdg.operationState() == IN_PROGRERSS);
            utility.endOfOperation(bdg);
        } while (utility.startRescueOrNot("Do you want to start the rescue operation in Building Z again? (Y/N): "));
    return 0;
}