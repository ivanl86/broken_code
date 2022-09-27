#include <iostream>

#include "controller.h"

int main(int argc, char const *argv[])
{
    size_t tick{0};
    Controller elevatorSim;
    Utility uty;
    while (true)
    {
        if (uty.randRange(1, 1000) <= 35)
        {
            elevatorSim.newVisitor();
            elevatorSim.setCall();
        }
    }
    
    return 0;
}
