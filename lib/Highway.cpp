#include "Highway.h"

Highway::Highway() {
    name = "I-35";
    lanes = MIN_LANES;
    width = MIN_WIDTH;
    length = MIN_LENGTH;
    traffic = 1;
    for (int i = 0; i < traffic; i++) {
        Vehicle * car = new Vehicle;
        // if (i == 0) {
        //     car->setPrev( nullptr );
        // }
        car->setNext( this->carList );
        this->carList = car;
        std::cout << "Made a new one!" << std::endl;
    }
}

Highway::Highway(int lane, int wid, int len, std::string nam, int trfc) {
    lanes = lane;
    width = wid;
    length = len;
    name = nam;
    traffic = trfc;
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
        mile[i] = y_bot;

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

void Highway::draw_cars() {
    std::cout << "Draw?!" << std::endl;
    Vehicle * car = carList;
    while ( car != nullptr) {
        int current_lane = car->getCurrentLane();
        int current_mile = car->getMile();
        if (car->getXPos() < 0 - car->getSize() ) {
            car->setMile(0);
            current_mile = car->getMile();
            car->setPosition(0 - car->getSize(), car->getYPos());
        } else if (car->getXPos() > WINDOW_WIDTH) {
            car->setMile(current_mile + 1);
            car->setPosition(0 - car->getSize(), car->getYPos());
        }
        else {
            // set the yPos to the middle of the lane (2n - 1) / 6
            int yPos = mile[current_mile] + ( (2 * current_lane - 1) * width / 6 );
            std::cout << width << std::endl;
            car->setPosition(car->getXPos(), yPos);
        }
        if (current_mile >= HIGHWAY_SECTIONS) car->setPosition(-100, -100);

        int len = car->getSize();
        int car_x_bot = car->getXPos();
        int car_y_bot = car->getYPos() - (LANE_HEIGHT / 2 - 5);
        int car_x_top = car_x_bot + len;
        int car_y_top = car->getYPos() + (LANE_HEIGHT / 2 - 5);
        setColor(RED);
        drawFilledBox(car_x_bot, car_y_bot, car_x_top, car_y_top);

        // move ptr to next in the list
        car = car->getNext();
    }

}

void Highway::move_traffic() {
    Vehicle * car = carList;
    while (car != nullptr) {
        car->move();
        std::cout << "Move?!" << std::endl;
        car = car->getNext();
    }
}
