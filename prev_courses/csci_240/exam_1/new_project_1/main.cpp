#include <iostream>
#include <ctime>

#include "controller.h"

int main(int argc, char const *argv[])
{
    size_t ticks{0};
    Utility uty;

    srand(time(NULL));

    if (uty.wantToPlay("Do you want to play Elevator Sim? (Y/N): "))
    {
        do
        {
            Controller ctr;

            do
            {
                try
                {

                }
                catch(const std::exception& e)
                { std::cerr << e.what() << '\n'; }

                ++ticks;
            } while (uty.continueToPlay(ticks));

        } while (uty.wantToPlay("Do you want to play again? (Y/N): "));
    }

    return 0;
}
