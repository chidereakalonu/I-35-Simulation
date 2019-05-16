// Author: Joshua Lipham
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

void Vehicle::init_vehicle() {
    this->setLane(dice.randint(1,3));
    this->setColor(dice.randint(0,12));
    this->setSpeed(dice.randfloat(4.0,11.0), 0, 0);
    this->setSize(dice.randint(25, 30));
    this->setRisk(dice.randint(1, 10));
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

void Vehicle::setSize(int sz) {
    size = sz;
}

void Vehicle::setRisk(int risk) {
    risky = risk;
}
// accessors
int Vehicle::getSize() {
    return size;
}

float Vehicle::getXPos() {
    return xPos;
}

int Vehicle::getYPos() {
    return yPos;
}

float Vehicle::getDistance() {
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
float Vehicle::getXSpeed() {
    return xSpeed;
}

ColorName Vehicle::getColor() {
    return colors[color];
}

// mutator methodss
void Vehicle::setPosition(float x, int y) {
    xPos = x;
    yPos = y;
}

void Vehicle::setSpeed(float pv, float xv, int yv) {
    if (pv != 0) {
        pref_speed = pv;
    }
    if (xv == 0) {
        xSpeed = pv;
    } else {
    xSpeed = xv;
    }
    ySpeed = yv;
}

void Vehicle::setDistance(float dst) {
    distance = dst;
}

void Vehicle::move(void) {
    distance += xSpeed;
    xPos += xSpeed;
    yPos += ySpeed;
    this->accelerate();
    Vehicle * nxt = check_ahead();
    if (nxt != nullptr) {
        if (nxt->getDistance() - this->getDistance() <= size * (2 + (risky / 5))) {
            // std::cout << "NEED TO PASS" << std::endl;
            // if they are stuck together, deglue
            if (nxt->getDistance() - this->getDistance() <= size ) {
                float speed = nxt->getXSpeed() - 5;
                this->slow_down(speed);
            }
            else if (this->pass_safety() == false) {
                float speed = nxt->getXSpeed();
                this->slow_down(speed);
            }
            else if (this->pass_safety() == true) {
                this->accelerate();
            }
        }
        else {
            this->accelerate();
        }
    }
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

// Passing Logic
Vehicle * Vehicle::check_ahead() {
    bool found = false;
    Vehicle * ptr = this;
    Vehicle * nxt;
    while (found != true) {
        while (ptr->getNext() != nullptr) {
            nxt = ptr->getNext();
            if (nxt->getCurrentLane() == this->getCurrentLane()) {
                found = true;
                break;
            }
            ptr = ptr->getNext();
        }
        break;
    }
    if (found) {
        return nxt;
    }
    else return nullptr;
}

// TODO: move this to the vehicle class
bool Vehicle::check_lane(int lane) {
    bool forward_found = false;
    bool back_found = false;
    Vehicle * ptr = this;
    Vehicle * nxt;
    Vehicle * prv;
    while (ptr->getNext() != nullptr) {
        nxt = ptr->getNext();
        if (nxt->getCurrentLane() == lane) {
            forward_found = true;
            break;
        }
        ptr = ptr->getNext();
    }
    while (ptr->getPrev() != nullptr) {
        prv = ptr->getPrev();
        if (prv->getCurrentLane() == lane) {
            back_found = true;
            break;
        }
        ptr = ptr->getPrev();
    }
    if ((back_found) && (forward_found)) {
        if ((nxt->getDistance() - this->getDistance() >= size * (2 + (risky / 5))) &&
            (this->getDistance() - prv->getDistance() >= size * (2 + (risky / 5)))) {
                return true;
             }
    }
    else {
        return false;
    }
}

bool Vehicle::pass_safety() {
    if ((this->getCurrentLane() == 1) || (this->getCurrentLane() == 3)) {
        if (this->check_lane(2)) {
            pass(2);
            return true;
        }
    }
    else if (this->getCurrentLane() == 2) {
        if (this->check_lane(3)) {
            pass(3);
            return true;
        }
        else if (this->check_lane(1)) {
            pass(1);
            return true;
        }
    }
    else {
        return false;
    }
}

void Vehicle::pass(int lane) {
    this->setLane(lane);
}
void Vehicle::slow_down(float spd) {
    this->setSpeed(0, spd, 0);
}
void Vehicle::accelerate() {
    this->setSpeed(0, pref_speed, 0);
}
