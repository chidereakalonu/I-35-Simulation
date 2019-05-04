#include "Highway.h"

Random dice;

Highway::Highway() {
    name = "I-35";
    lanes = MIN_LANES;
    width = MIN_WIDTH;
    length = MIN_LENGTH;
    traffic = dice.randint(50, 200);
    this->carList = nullptr;

    // populate the list
    for (int i = 0; i < traffic; i++) {
        Vehicle * ptr = this->carList;
        int init_lane = dice.randint(1,3);
        if (ptr == nullptr) {
            Vehicle * car = new Vehicle;
            this->carList = car;
            car->setPrev(nullptr);
            car->setNext(nullptr);
            car->setPosition((-50) * i - 50, car->getYPos());
            car->setDistance((-50) * i - 50);
        }
        else {
            while (ptr->getNext() != nullptr) {
                ptr = ptr->getNext();
            }
            Vehicle * car = new Vehicle();
            ptr->setNext( car );
            car->setPrev( ptr );
            car->setPosition((-50) * i - 50, car->getYPos());
            car->setDistance((-50) * i - 50);
            car->setLane(init_lane);
        }
    }
    // set up the vehicles
    Vehicle * car = this->carList;
    while (car != nullptr) {
        car->setLane(dice.randint(1,3));
        car->setColor(dice.randint(1,13));
        car->setSpeed(dice.randint(4,8), 0);
        car = car->getNext();
    }
}

Highway::Highway(int lane, int wid, int len, std::string nam, int trfc) {
    lanes = lane;
    width = wid;
    length = len;
    name = nam;
    traffic = trfc;
    this->carList = nullptr;

    for (int i = 0; i < traffic; i++) {
        Vehicle * ptr = this->carList;
        int init_lane = dice.randint(1,3);
        if (ptr == nullptr) {
            Vehicle * car = new Vehicle;
            this->carList = car;
            car->setPrev(nullptr);
            car->setNext(nullptr);
            car->setPosition((-50) * i - 50, car->getYPos());
            car->setDistance((-50) * i - 50);
        }
        else {
            while (ptr->getNext() != nullptr) {
                ptr = ptr->getNext();
            }
            Vehicle * car = new Vehicle();
            ptr->setNext( car );
            car->setPrev( ptr );
            car->setPosition((-50) * i - 50, car->getYPos());
            car->setDistance((-50) * i - 50);
            car->setLane(init_lane);
        }
    }
}

// accessors
Vehicle * Highway::getCarList() {
    return this->carList;
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
    Vehicle * car = carList;
    while ( car != nullptr) {
        int current_lane = car->getCurrentLane();
        int current_mile = car->getMile();
        if (car->getXPos() < 0 - car->getSize() ) {
            car->setMile(0);
            current_mile = car->getMile();
            // car->setPosition(0 - car->getSize(), car->getYPos());
        } else if (car->getXPos() > WINDOW_WIDTH) {
            car->setMile(current_mile + 1);
            car->setPosition(0 - car->getSize(), car->getYPos());
        }
        else {
            // set the yPos to the middle of the lane (2n - 1) / 6
            int yPos = mile[current_mile] + ( (2 * current_lane - 1) * width / 6 );
            car->setPosition(car->getXPos(), yPos);

        }
        if (current_mile >= HIGHWAY_SECTIONS) {
            car->setPosition(-100, -100);
            car->setDistance(-100);
        }

        int len = car->getSize();
        int car_x_bot = car->getXPos();
        int car_y_bot = car->getYPos() - (LANE_HEIGHT / 2 - 5);
        int car_x_top = car_x_bot + len;
        int car_y_top = car->getYPos() + (LANE_HEIGHT / 2 - 5);
        setColor(car->getColor());
        drawFilledBox(car_x_bot, car_y_bot, car_x_top, car_y_top);

        // move ptr to next in the list
        car = car->getNext();
    }

}
void Highway::animate() {
    sort_cars();
    move_traffic();

}
void Highway::move_traffic() {
    Vehicle * car = carList;
    while (car != nullptr) {
        car->move();
        car = car->getNext();
    }
    std::cout << "Does it work?" << std::endl;
}

void Highway::sort_cars() {
    Vehicle * list_end = nullptr;
    while(list_end != carList) {
        Vehicle *tmp, *car;
        car = carList;
        while (car->getNext() != list_end) {
            Vehicle *nxt = car->getNext();
            if (car->getDistance() > nxt->getDistance()) {
                car->setNext(nxt->getNext());
                nxt->setNext(car);
                if(car == carList) {
                    carList = nxt;
                    car = nxt;
                }
                else {
                    car = nxt;
                    tmp->setNext(nxt);
                }
            }
            tmp = car;
            car = car->getNext();
        }
        // update the list_end to the last sorted element:
        list_end = car;
    }
    Vehicle * car = carList;
    Vehicle *nxt, *tmp;
    while (car != nullptr) {
        if (car == carList) {
            nxt = car->getNext();
            nxt->setPrev(car);
            car->setPrev(nullptr);
        }
        else if (car->getNext() == nullptr) {
            car->setPrev(tmp);
        }
        else {
            nxt = car->getNext();
            nxt->setPrev(car);
            car->setPrev(tmp);
        }
        tmp = car;
        car = car->getNext();
    }


}

void Highway::check_proximity() {
    // search for cars to in front of car in same lane
    // search for cars to the left or right of the car
    // if safe to pass, call pass function
    // if unsafe to pass, slow down
}

void Highway::pass() {

}
