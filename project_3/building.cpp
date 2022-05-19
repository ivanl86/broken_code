#include "building.h"

Building::Building()
{
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