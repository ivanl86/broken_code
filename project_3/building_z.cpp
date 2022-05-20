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

int main(int argc, char const *argv[])
{
    char g;
    std::cout << "It runs!!!";
    Building bdg;
    bdg.move(g);
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