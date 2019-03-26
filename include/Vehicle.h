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
        Vehicle();
        void setPosition( int x, int y );
        void setSpeed( int xv, int yv );

        void move( void );
};
