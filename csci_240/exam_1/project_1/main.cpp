#include <iostream>
#include <ctime>

#include "controller.h"

int main(int argc, char const *argv[])
{
    size_t ticks{0};
    size_t totalTicks{0};
    size_t visitorCount{0};
    Utility uty;

    srand(time(NULL));

    if (uty.wantToPlay("Do you want to play Elevator Sim? (Y/N): "))
    {
        do
        {
            Controller elevatorSim(LOBBY, HIGHEST_FLOOR, MAX_CAPACITY);
            size_t curFloor{0};
            directions curDrt{idle};

            do
            {
                try
                {
                    if (elevatorSim.newVisitor())
                    {
                        elevatorSim.newVisitorMsg();
                        ++visitorCount;
                    }

                    if (curFloor == LOBBY)
                        elevatorSim.exitBuilding(curFloor);

                    elevatorSim.disembarkElevator(curFloor);
                    elevatorSim.embarkElevator(curFloor);

                    elevatorSim.setCall();
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }

                uty.updateCurFloor(curFloor, curDrt);
                uty.updateDirections(curDrt, curFloor);

                ++totalTicks;
                //std::cout << totalTicks << " ticks\n";

            } while (uty.continueToPlay(totalTicks));
            std::cout << "Total of " << visitorCount << " visitors has visited the building!\n";
        } while (uty.wantToPlay("Do you want to play again? (Y/N): "));
    }

    return 0;
}
