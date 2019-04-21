#include "Vehicle.h"

// constructors
Vehicle::Vehicle(void) {
    size = 35;
    xPos = -100;
    yPos = -100;
    xSpeed = 2;
    ySpeed = 0;
    lane = 1;
    preferred_lane = 1;
    current_lane = 3;
    active = true;
    color = BLUE;
    mile = 1;


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
    current_lane = preferred_lan;
    active = activ;
    color = c;
    mile = 0;
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

int Vehicle::getCurrentLane() {
    return current_lane;
}

int Vehicle::getMile() {
    return mile;
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

void Vehicle::setLane(int lane) {
    if (lane != current_lane) {
        current_lane = lane;
    }
}

void Vehicle::setMile(int mi) {
    mile = mi;
}
