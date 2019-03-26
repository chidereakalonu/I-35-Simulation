#include <iostream>
#include "Graphics.h"

#pragma once

class Vehicle {
    private:
        int size;       // how big should this vehicle be
        int xPos;       // screen position in pixels
        int yPos;       
        int xSpeed;     // current speed
        int ySpeed;

        int lane;
        int preferred_lane;
        bool active;
        ColorName color;

    public:

        // constructors
        Vehicle();
        Vehicle(int siz, int x, int y, int xv, int yv, 
                int lan, int preferred_lan, bool activ, ColorName c);

        // mutators
        void setPosition( int x, int y );
        void setSpeed( int xv, int yv );

        void move( void );
};
