#include "Vehicle.h"

// constructors
Vehicle::Vehicle(void) {
    size = 25;
    distance = -100;
    xPos = -100;
    yPos = -100;
    xSpeed = 10;
    ySpeed = 0;
    preferred_lane = 3;
    current_lane = 3;
    active = true;
    color = 0;
    mile = 1;

    this->Next = nullptr;
    this->Prev = nullptr;
}

Vehicle::Vehicle(int siz, int x, int y, int xv, int yv,
        int preferred_lan, bool activ,
        ColorName c, Vehicle * nextCar, Vehicle * prevCar) {
    size = siz;
    xPos = x;
    yPos = y;
    xSpeed = xv;
    ySpeed = yv;
    preferred_lane = preferred_lan;
    current_lane = preferred_lan;
    active = activ;
    color = c;
    mile = 0;
    this->Next = nextCar;
    this->Prev = prevCar;
}

// Linked List Code
Vehicle * Vehicle::getNext() {
    return this->Next;
}

Vehicle * Vehicle::getPrev() {
    return this->Prev;
}

void Vehicle::setNext( Vehicle * ptr) {
    this->Next = ptr;
}

void Vehicle::setPrev( Vehicle * ptr ) {
    this->Prev = ptr;
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

int Vehicle::getDistance() {
    return distance;
}

int Vehicle::getCurrentLane() {
    return current_lane;
}

int Vehicle::getMile() {
    return mile;
}

int Vehicle::getID() {
    return id;
}

ColorName Vehicle::getColor() {
    return colors[color];
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

void Vehicle::setDistance(int dst) {
    distance = dst;
}

void Vehicle::move(void) {
    distance += xSpeed;
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

void Vehicle::setID( int i ) {
    id = i;
}

void Vehicle::setColor(int col) {
    color = col;
}
