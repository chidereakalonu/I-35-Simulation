#include "Vehicle.h"

// constructors
Vehicle::Vehicle(void) {
    size = 10;
    xPos = 0;
    yPos = 100;
    xSpeed = 2;
    ySpeed = 0;
    lane = 1;
    preferred_lane = 1;
    active = true;
    color = BLUE;
}

Vehicle::Vehicle(int size, int x, int y, int xv, int yv, 
        int lane, int preferred_lane, bool active, ColorName c) {
    size = size;
    xPos = x;
    yPos = y;
    xSpeed = xv;
    ySpeed = yv;
    lane = lane;
    preferred_lane = preferred_lane;
    active = active;
    color = c;
}

// mutator methods
void Vehicle::setPosition(int x, int y) {
    xPos = x;
    yPos = y;
}

void Vehicle::setSpeed(int xv, int yv) {
    xSpeed = xv;
    ySpeed = xy;
}

void move(void) {
    xPos += xSpeed;
    yPos += ySpeed;
}
