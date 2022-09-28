#include "floors.h"

Floors::Floors() : occupants{new Bag[HIGHEST_FLOOR + 1]},
                   elevatorQueue{new Queue[HIGHEST_FLOOR + 1]} {}