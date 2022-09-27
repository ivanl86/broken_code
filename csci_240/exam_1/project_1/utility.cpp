#include "utility.h"

size_t Utility::randRange(size_t start, size_t end)
{ return (rand() % (end - start + 1)) + start; }

bool Utility::wantToPlay(std::string prompt)
{
    char choice;
    std::cout << prompt;
    do
    {
        std::cin >> choice;
        if (choice == 'y' || choice == 'n')
            break;
    } while (true);
    
    
    
}