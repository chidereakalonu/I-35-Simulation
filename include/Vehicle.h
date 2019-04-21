#pragma once

#include <iostream>
#include "Graphics.h"

class Vehicle {
    private:
        Vehicle * Next;
        Vehicle * Prev;

        int size;       // how big should this vehicle be
        int xPos;       // screen position in pixels
        int yPos;
        int xSpeed;     // current speed
        int ySpeed;
        int id;

        int preferred_lane;
        int current_lane;

        int mile;
        bool active;
        ColorName color;

    public:

        // constructors
        Vehicle();
        Vehicle(int siz, int x, int y, int xv, int yv,
                int preferred_lan, bool activ,
                ColorName c, Vehicle * nextCar, Vehicle * prevCar);

        // mutators
        void setPosition( int x, int y );
        void setSpeed( int xv, int yv );
        void setLane(int lane);
        void setMile(int mi);
        void move( void );
        void setID(int i);
        void setNext(Vehicle * ptr);
        void setPrev(Vehicle * ptr);

        // accessors
        int getSize();
        int getXPos();
        int getYPos();
        int getCurrentLane();
        int getPreferredLane();
        int getMile();
        int getID();

        Vehicle * getNext( void );
        Vehicle * getPrevious( void );

        // mgmt

        void walkTraffic(void);

};
