#include "dog.h"

Dog::Dog(const std::string &name) : Pet("Dog", name) {}

std::string Dog::speak() { return name + " woof"; }