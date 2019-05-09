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
        int xPos;       // screen position in pixels
        int yPos;
        int xSpeed;     // current speed
        int pref_speed; // preferred speed
        int ySpeed;
        int id;
        int distance;

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
        void setPosition( int x, int y );
        void setSpeed( int pv, int xv, int yv );
        void setLane(int lane);
        void setMile(int mi);
        void setDistance(int dst);
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
        int getXPos();
        int getYPos();
        int getDistance();
        int getCurrentLane();
        int getPreferredLane();
        int getMile();
        int getID();
        int getXSpeed();
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
        void slow_down(int spd);
        void accelerate();

};
