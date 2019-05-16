// Author: Joshua Lipham

#pragma once

#include <iostream>
#include "Graphics.h"
#include "Random.h"

static const ColorName colors[13] = { WHITE, BLACK, RED, ORANGE, YELLOW, GREEN,
                        FOREST_GREEN, BLUE, CYAN, MIDNIGHT_BLUE, PURPLE,
                        MAGENTA, BROWN};

class Vehicle {
    private:

        Vehicle * Next;
        Vehicle * Prev;

        Random dice;

        int size;       // how big should this vehicle be
        int risky;
        float xPos;       // screen position in pixels
        int yPos;
        float xSpeed;     // current speed
        float pref_speed; // preferred speed
        int ySpeed;
        int id;
        float distance;

        int preferred_lane;
        int current_lane;

        int mile;
        bool active;
        int color;

    public:

        // constructors
        Vehicle();
        Vehicle(int siz, int x, int y, int xv, int yv,
                int preferred_lan, bool activ,
                ColorName c, Vehicle * nextCar, Vehicle * prevCar);

        // mutators
        void init_vehicle();
        void setPosition( float x, int y );
        void setSpeed( float pv, float xv, int yv );
        void setLane(int lane);
        void setMile(int mi);
        void setDistance(float dst);
        void move( void );
        void setID(int i);
        void setNext(Vehicle * ptr);
        void setPrev(Vehicle * ptr);
        void setSize(int sz);
        void setRisk(int risk);
        void setColor(int col);
        void setCurrentLane(int lan);

        // accessors
        int getSize();
        float getXPos();
        int getYPos();
        float getDistance();
        int getCurrentLane();
        int getPreferredLane();
        int getMile();
        int getID();
        float getXSpeed();
        ColorName getColor();

        Vehicle * getNext();
        Vehicle * getPrev();

        // mgmt
        void walkTraffic(void);

        // passing logic
        Vehicle * check_ahead();
        bool check_lane(int lane);
        bool pass_safety();
        void pass(int lane);
        void slow_down(float spd);
        void accelerate();

};
