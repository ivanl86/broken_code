#include "building.h"

Building::Building()
{
    guards = new std::vector<Infected*>;
    //guards = std::make_unique<std::vector<Infected*>>();
    specOp = new Uninfected;
    scientist = new Uninfected;
}

void Building::move(char move)
{}

Building::~Building()
{
    delete[] guards;
    delete specOp;
    delete scientist;
}

std::ostream& operator<<(std::ostream &os, const Building &bd)
{}