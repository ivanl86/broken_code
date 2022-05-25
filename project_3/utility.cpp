#include "utility.h"

Utility::Utility()
{}

Utility::~Utility()
{}

char Utility::getMove(const std::string &prompt)
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

bool Utility::wantToPlayOrNot(const std::string &prompt)
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

void Utility::endOfOperation(Building &bdg) const
{
    if (bdg.operationState() == ACCOMPLISHED)
        std::cout << "  Congratulations!\nMission Accomplished!\n";
    else if (bdg.operationState() == FAILED)
        std::cout << "You got infected from zombie attacks!\n\t  Mission Failed!\n";
}

void Utility::clearScreen()
{ system("CLS"); }

void Utility::clearInstream()
{
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
}