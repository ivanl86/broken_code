#include "building.h"

Building::Building()
    : callSet{}, elevator{floors, callSet} {}

void Building::add(const Person& p) {
    floors[LOBBY].addElevatorQueue(p);
}

void Building::update() {
    for (size_t i{0}; i < FLOOR_QTY; ++i) {
        callSet[i] = floors[i].update();
    }
    
}