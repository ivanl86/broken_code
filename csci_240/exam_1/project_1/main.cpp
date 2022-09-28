#include <iostream>
#include <ctime>

#include "controller.h"

int main(int argc, char const *argv[])
{
    size_t ticks{0};
    size_t visitorCount{0};
    Utility uty;

    srand(time(NULL));

    if (uty.wantToPlay("Do you want to play Elevator Sim? (Y/N): "))
    {
        do
        {
            do
            {
                Controller elevatorSim;

                if (uty.randRange(1, 1000) <= 35)
                {
                    elevatorSim.newVisitor();
                    //elevatorSim.setCall();
                    std::cout << "A new visitor has arrived!\n";
                    ++visitorCount;
                }

                ++ticks;
                std::cout << ticks << " ticks\n";

            } while (uty.continueToPlay(ticks));
            std::cout << "Total of " << visitorCount << " visitors has arrived!\n";
        } while (uty.wantToPlay("Do you want to play again? (Y/N): "));
    }

    return 0;
}
