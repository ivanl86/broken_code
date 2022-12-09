
#include "dog.h"

#ifndef DOG_H
#define DOG_H

// set breed
Dog::Dog(const std::string &breed) : Pet(breed, "") {}

// set breed and name
Dog::Dog(const std::string &breed, const std::string &name) : Pet("Dog", breed, name) {}

std::string Dog::speak() const
{
    return "woof";
}

#endif