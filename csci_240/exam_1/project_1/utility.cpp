#include "utility.h"

size_t Utility::randRange(size_t start, size_t end)
{ return (rand() % (end - start + 1)) + start; }

bool Utility::wantToPlay(std::string prompt)
{
    char choice;
    
    do
    {
        std::cout << prompt;
        std::cin >> choice;
        
        if (tolower(choice) == 'y')
            return true;
        if (tolower(choice) == 'n')
            return false;
        std::cout << "Invalid Input! Please try again";
    } while (true);
    
    
    
}

bool Utility::continueToPlay(size_t ticks)
{
    if (ticks % 1000 == 0)
        return wantToPlay("Do you want to keep playing? (Y/N): ");
    else 
        return true;
}

void Utility::updateCurFloor(size_t &curFloor, directions drt)
{
    if (drt == up)
        ++curFloor;
    if (drt == down)
        --curFloor;
}

void Utility::updateDirections(directions &drt, size_t curFloor)
{
    if (curFloor >= HIGHEST_FLOOR)
        drt = down;
    if (curFloor <= LOBBY)
        drt = up;
    
    
}