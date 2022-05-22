// who: Ivan Leung ileung2
// what: Building Z
// why: Project 3
// when: May/29/2022

#include <iostream>

#include "building.h"
#include "position.h"
#include "person.h"
#include "infected.h"
#include "lounger.h"
#include "hyper.h"
#include "aggressor.h"
#include "uninfected.h"

char getChar(const std::string &prompt);
bool wantToPlayOrNot(const std::string &prompt);
void clearScreen();
void clearInstream();

int main(int argc, char const *argv[])
{
    if (wantToPlayOrNot("Do you want to play Building Z? (Y/N): "))
    {
        do
        {
            Building bdg;
            std::cout << bdg;
            do 
            {
                
                try
                {
                    bdg.move(getChar("Your move [N,S,W,E,P,C]: "));
                    
                    clearInstream();
                }
                catch (const std::runtime_error e)
                {
                    std::cerr << "Invalid move!\n";
                }
                
                // clearScreen();
                std::cout << bdg;
            } while (true);
            // game over message here
        } while (wantToPlayOrNot("Do you want to play Building Z again? (Y/N): "));
    }

    
    return 0;
}

char getChar(const std::string &prompt)
{
    char move;
    do
    {
        std::cout << prompt; // "Your move [N,S,W,E,P,C]: "
        std::cin >> move;
        move = toupper(move);
        if (move == 'N' || move == 'S' || move == 'W' || move == 'E' || move == 'P' || move == 'C')
            return move;
        std::cout << "Invalid Input!\n\n";
    } while (true);
}

bool wantToPlayOrNot(const std::string &prompt)
{
    char choice;
    do
    {
        std::cout << prompt; // "Do you want to play Building Z? (Y/N): "
        std::cin >> choice;
        choice = toupper(choice);
        if (choice == 'Y')
            return true;
        if (choice == 'N')
            return false;
        std::cout << "Invalid Input!\n\n";
    } while (true);
}

void clearScreen()
{ system("CLS"); }

void clearInstream()
{
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
}