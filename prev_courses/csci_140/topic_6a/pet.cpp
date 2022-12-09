

#include <stdexcept>

#include "pet.h"

 // set breed
//Pet::Pet(const std::string &breed) : Pet(breed, "", "") {}

 // set breed and name
Pet::Pet(const std::string &type, const std::string &breed) : Pet(type, breed, "") {}

 // set breed, name, and type
Pet::Pet(const std::string &type, const std::string &breed, const std::string &name) : type{type}, breed{breed}, name{name} {}


// std::string Pet::speak() const { return ""; }

std::string Pet::getType() const { return type; }

std::string Pet::getName() const { return name; }

std::string Pet::getBreed() const { return breed; }

void Pet::setType(const std::string &type) { this->type = type; }

void Pet::setName(const std::string &name) { this->name = name; }

void Pet::setBreed(const std::string &name)
{
    if(breed.empty())
        throw std::invalid_argument("Breed cannot be empty!");
    this->breed = breed;
}

void Pet::operator=(const Pet &p)
{
    type = p.type;
    breed = p.breed;
    name = p.name;
}

std::ostream& operator<<(std::ostream& os, const Pet& p)
{
    os << p.getName() << " the " << p.getType() << " is a " << p.getBreed() << " and says " << p.speak();
    return os;
}


/*
Pet::Pet(const std::string &type, const std::string &breed, const std::string &name) : type{type}, breed{breed}, name{name}
{
    setBreed(breed);
}
*/