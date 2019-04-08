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
    for (int i = 0; i < HIGHWAY_SECTIONS; i++) {
        int x_bot = 0; // bottom left corner of road
        int y_top = WINDOW_HEIGHT - (((4 * i) + 1) * width / 2); // bottom left corner of road
        int x_top = length;
        int y_bot = WINDOW_HEIGHT - (((4 * i) + 3) * width / 2);
        setColor(GREY);
        drawFilledBox(x_bot, y_bot, x_top, y_top);

        // draw lane divider
        for (int j = 1; j < lanes; j ++) {
            setColor(WHITE);
            int div_y_bot = y_bot + ((j * width) / lanes);
            int div_y_top = div_y_bot + DIV_WIDTH;
            for (int k = 0; k < (length / (DIV_SPACE + DIV_LENGTH)) + 1; k++){
                int div_x_bot = (k * (DIV_SPACE + DIV_LENGTH));
                int div_x_top = div_x_bot + DIV_LENGTH;
                drawFilledBox(div_x_bot, div_y_bot, div_x_top, div_y_top);
            }
        }
    }
}

void Highway::draw_cars(int xPos, int yPos) {
    int len = car.getSize();
    int car_x_bot = xPos;
    int car_y_bot = yPos;
    int car_x_top = xPos + len;
    int car_y_top = yPos + (MIN_WIDTH / 4);
    drawFilledBox(car_x_bot, car_y_bot, car_x_top, car_y_top);
}
