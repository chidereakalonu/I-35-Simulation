#include "Highway.h"

Highway::Highway() {
    std::string name = "I-35";
    int lanes = MIN_LANES;
    int width = MIN_WIDTH;
    int length = MIN_LENGTH;
}

Highway::Highway(int lane, int wid, int len, std::string nam) {
    int lanes = lane;
    int width = wid;
    int length = len;
    std::string name = nam;
}

// accessors
std::string Highway::get_name() {
    return name;
}

int Highway::get_lanes() {
    return lanes;
}

int Highway::get_width() {
    return width;
}

int Highway::get_length() {
    return length;
}

// mgmt functions

void Highway::draw(){

    
}
