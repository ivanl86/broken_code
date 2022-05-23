
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "dungeon.h"

int main(int argc, char const *argv[])
{
    Dungeon dungeon;

    std::cout << dungeon.toString() << std::endl;
    
    return 0;
}
