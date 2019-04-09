#include "Vehicle.h"

// constructors
Vehicle::Vehicle(void) {
    size = 35;
    xPos = 0;
    yPos = 125;
    xSpeed = 2;
    ySpeed = 0;
    lane = 1;
    preferred_lane = 1;
    active = true;
    color = BLUE;
}

Vehicle::Vehicle(int siz, int x, int y, int xv, int yv,
        int lan, int preferred_lan, bool activ, ColorName c) {
    size = siz;
    xPos = x;
    yPos = y;
    xSpeed = xv;
    ySpeed = yv;
    lane = lan;
    preferred_lane = preferred_lan;
    active = activ;
    color = c;
}

// accessors
int Vehicle::getSize() {
    return size;
}

int Vehicle::getXPos() {
    return xPos;
}

int Vehicle::getYPos() {
    return yPos;
}

// mutator methods
void Vehicle::setPosition(int x, int y) {
    xPos = x;
    yPos = y;
}

void Vehicle::setSpeed(int xv, int yv) {
    xSpeed = xv;
    ySpeed = yv;
}

void Vehicle::move(void) {
    xPos += xSpeed;
    yPos += ySpeed;
}
