#pragma once
#include "Graphics.h"
#include <string>

const int MIN_LANES = 3;
const int MIN_WIDTH = WINDOW_HEIGHT / 8;
const int MIN_LENGTH = WINDOW_WIDTH;
const int HIGHWAY_SECTIONS = 4;
const int DIV_LENGTH = 25;
const int DIV_SPACE = 5;
const int DIV_WIDTH = 3;

class Highway {
private:
    std::string name;	// name of this highway
    int lanes;		// number of lanes
    int width;		// width of each lane in pixels
    int length;		// length of each lane segment
public:
    // constructors
	Highway();		// default constructor
    Highway(int lane, int wid, int len, std::string nam);

    // accessors
    std::string get_name();
    int get_lanes();
    int get_width();
    int get_length();

    // mgmt methods
	void draw();		// display the highway
};
