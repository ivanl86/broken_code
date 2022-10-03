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
            Controller elevatorSim;

            do
            {
                try
                {
                    elevatorSim.update();
//                    if (elevatorSim.newVisitor())
//                    {
//                        elevatorSim.newVisitorMsg();
//                        ++visitorCount;
//                    }
//
//                    elevatorSim.setCall();
//
//                    if (curFloor == LOBBY)
//                        elevatorSim.exitBuilding();
//                    if (elevatorSim.disembarkElevator() || elevatorSim.embarkElevator())
//                    {
//                        curDrt = STILL;
//                    }

                }
                catch(const std::exception& e)
                { std::cerr << e.what() << '\n'; }


//                if (ticks % 4 == 0)
//                {
//                    uty.updateCurFloor(curFloor, curDrt);
//                    ticks = 0;
//                }
//                
//                
//                uty.updateDirections(curDrt, curFloor);
//
//                ++ticks;
                ++totalTicks;
                //std::cout << totalTicks << " ticks\n";

            } while (uty.continueToPlay(totalTicks));
            // std::cout << "Total of " << visitorCount << " visitors has visited the building!\n";
        } while (uty.wantToPlay("Do you want to play again? (Y/N): "));
    }

    return 0;
}
