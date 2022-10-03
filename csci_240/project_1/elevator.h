#include "bag.h"

#ifndef ELEVATOR_H
#define ELEVATOR_H

#define LOBBY 1
#define TOP_FLOOR 50
#define FLOOR_INDX 51
#define MAX_CAPACITY 6
#define CALL_IDX 51

enum Flow{STILL, UP, DOWN};
enum State{IDLE, GOING_UP, GOING_DOWN, IN_TRANSIT, EMBARKING, DISEMBARKING};

class Elevator
{
public:
    Elevator();
    void updateCounter();
    void updateCurFloor();
    void updateFlow();
    void updateState();
    bool zeroCounter();

    void setCall(size_t idx);
    void unsetCall(size_t idx);

    size_t setDstFloor();
    void setEmbarkCounter();
    void setDisembarkCounter();
    void setGoUpCounter();
    void setGoDownCounter();

    State getState();
    Flow getFlow();
    size_t getEmbarkCounter();
    size_t getDisembarkCounter();
    size_t getGoUpCounter();
    size_t getGoDownCounter();

    Bag occupants;
    size_t curFloor;
    size_t pCount;
    bool calls[CALL_IDX];
    State state;
    Flow flow;
    State prvState;


private:
    size_t embarkCounter;
    size_t disembarkCounter;
    size_t goUpCounter;
    size_t goDownCounter;

};

#endif  /* ELEVATOR_H */