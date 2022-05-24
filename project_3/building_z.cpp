// who: Ivan Leung ileung2
// what: Building Z
// why: Project 3
// when: May/29/2022

#include <iostream>

#include "building.h"
#include "utility.h"

char getChar(const std::string &prompt);
bool wantToPlayOrNot(const std::string &prompt);
void clearScreen();
void clearInstream();

int main(int argc, char const *argv[])
{
    Utility utility;
    if (utility.wantToPlayOrNot("Do you want to play Building Z? (Y/N): "))
        do
        {
            Building bdg;
            std::cout << bdg << std::endl;
            do 
            {
                try
                {
                    bdg.move(utility.getMove("Your move [N,S,W,E,P,C]: "));
                    utility.clearInstream();
                }
                catch (const std::runtime_error e)
                { std::cerr << "Invalid move!\n"; }
                // utility.clearScreen();
                std::cout << bdg << std::endl;
            } while (bdg.operationState() == IN_PROGRERSS);
            utility.endOfOperation(bdg);
        } while (utility.wantToPlayOrNot("Do you want to play Building Z again? (Y/N): "));
    return 0;
}