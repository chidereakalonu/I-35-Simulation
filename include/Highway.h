#pragma once

#include <string>

class Highway {
    public:
	std::string name;	// name of this highway
        int lanes;		// number of lanes 
        int width;		// width of each lane in pixels
        int length;		// length of each lane segment

	Highway();		// default constructor
	void draw();		// display the highway
};
