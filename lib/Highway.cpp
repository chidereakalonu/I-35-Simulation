#include "Highway.h"

Highway::Highway() {
    name = "I-35";
    lanes = MIN_LANES;
    width = MIN_WIDTH;
    length = MIN_LENGTH;
}

Highway::Highway(int lane, int wid, int len, std::string nam) {
    lanes = lane;
    width = wid;
    length = len;
    name = nam;
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
    for (int i = 0; i <  HIGHWAY_SECTIONS; i++) {
        int x_bot = 0; // bottom left corner of road
        int y_bot = WINDOW_HEIGHT - (((4 * i) + 1) * width / 2); // bottom left corner of road
        int x_top = MIN_LENGTH;
        int y_top = WINDOW_HEIGHT - (((4 * i) + 3) * width / 2);
        setColor(GREY);
        drawFilledBox(x_bot, y_bot, x_top, y_top);
            std::cout << MIN_LANES << MIN_LENGTH << MIN_WIDTH << std::endl;
    }
}
