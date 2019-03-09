#include "Highway.h"

void Highway::Highway(void) {
    std::string name = "I-35";
    int lanes = MIN_LANES;
    int width = MIN_WIDTH;
    int length = MIN_LENGTH;
}

void Highway::Highway(int lane, int wid, int len, std::string name) {
    int lanes = lane;
    int width = wid;
    int length = len;
    std::string name = name;
}

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
