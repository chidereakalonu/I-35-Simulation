#pragma once
#include "Graphics.h"
#include <string>

const int MIN_LANES = 3;
const int MIN_WIDTH = WINDOW_HEIGHT / 8;
const int MIN_LENGTH = WINDOW_WIDTH;

class Highway {
private:
    std::string name;	// name of this highway
    int lanes;		// number of lanes
    int width;		// width of each lane in pixels
    int length;		// length of each lane segment
public:
    // constructors
	Highway();		// default constructor
    Highway(int lane, int wid, int len, std::string name);

    // accessors
    void get_name();
    void get_lanes();
    void get_width();
    void get_length();

    // mgmt methods
	void draw();		// display the highway
};
