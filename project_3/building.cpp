#include "building.h"

Building::Building()
{}

std::ostream& operator<<(std::ostream &os, const Building &bdg)
{
    os << bdg;
    return os;
}

void Building::move(char move)
{}

Building::~Building()
{}