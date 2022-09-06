#include <string>

#ifndef PET_H
#define PET_H

class Pet
{
public:
    Pet(const std::string &, const std::string &);
    virtual std::string speak() = 0;
protected:
    std::string species;
    std::string name;
};

#endif