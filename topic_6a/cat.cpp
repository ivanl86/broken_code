
#include "cat.h"

#ifndef CAT_H
#define CAT_H

// set breed
Cat::Cat(const std::string &breed) : Pet(breed, "") {}

// set breed and name
Cat::Cat(const std::string &breed, const std::string &name) : Pet("Cat", breed, name) {}

std::string Cat::speak() const
{
    return "hiss";
}

#endif