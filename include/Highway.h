// Author: Davin Lawrence

#pragma once

#include "Graphics.h"
#include <string>
#include "Vehicle.h"

const int MIN_LANES = 3;
const int MIN_LENGTH = WINDOW_WIDTH;
const int HIGHWAY_SECTIONS = 4;
const int MIN_WIDTH = WINDOW_HEIGHT / (HIGHWAY_SECTIONS * 2);
const int DIV_LENGTH = 25;
const int DIV_SPACE = 5;
const int DIV_WIDTH = 3;
const int LANE_HEIGHT = MIN_WIDTH / MIN_LANES;

class Highway {
private:
    std::string name;	// name of this highway
    int lanes;		// number of lanes
    int width;		// width of each lane in pixels
    int length;		// length of each lane segment
    int traffic;    // number of cars on the road
    Vehicle * carList;    // location of the first node

    int mile[HIGHWAY_SECTIONS];    // array that stores the middle lane for each sect. of road



public:
    // constructors
	Highway();		// default constructor
    Highway(int lane, int wid, int len, std::string nam, int trfc);

    // accessors
    std::string get_name();
    Vehicle * getCarList();
    int get_lanes();
    int get_width();
    int get_length();

    // mgmt methods
	void draw();		// display the highway
    void draw_cars();   // draw the cars
    void move_traffic();
    bool check_ahead(Vehicle * car); // check for cars around the car
    bool check_lane(Vehicle * car, int lane); // check the lanes for vehicles
    bool pass_safety(Vehicle * car);
    void pass(Vehicle * car, int lane);
    void sort_cars(); // sort the cars based on distance

    void animate();
};
