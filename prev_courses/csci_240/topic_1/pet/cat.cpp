#include "cat.h"

Cat::Cat(const std::string &name) : Pet("Cat", name) {}

std::string Cat::speak() { return name + " meow"; }