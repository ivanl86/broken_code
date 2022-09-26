#include "utility.h"

size_t Utility::randRange(size_t start, size_t end)
{ return (rand() % (end - start + 1)) + start; }