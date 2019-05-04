#include "Highway.h"
#include "catch.hpp"

TEST_CASE("Testing default constructor", "Highway") {
    Highway dflt;
    std::string name = dflt.get_name();
    int lanes = dflt.get_lanes();
    int width = dflt.get_width();
    int length = dflt.get_length();

    REQUIRE(name == "I-35");
    REQUIRE(lanes == MIN_LANES);
    REQUIRE(width == MIN_WIDTH);
    REQUIRE(length == MIN_LENGTH);

}

TEST_CASE("Testing Constructor", "Highway") {
    const int cars = 200;
    Vehicle * car_ptrs[cars];
    Highway xplct(3, 500, 1000, "Name", cars);
    std::string name = xplct.get_name();
    int lanes = xplct.get_lanes();
    int width = xplct.get_width();
    int length = xplct.get_length();

    REQUIRE(name == "Name");
    REQUIRE(lanes == 3);
    REQUIRE(width == 500);
    REQUIRE(length == 1000);

    Vehicle * car = xplct.getCarList();
    int count = 0;
    while (car != nullptr) {
        if (count == 0) {
            REQUIRE(car->getPrev() == nullptr);
        }
        else if (count == cars - 1) {
            REQUIRE(car->getNext() == nullptr);
        }
        else {
            REQUIRE(car->getNext() != nullptr);
            REQUIRE(car->getPrev() != nullptr);
        }
        car_ptrs[count] = car;
        count++;
        car = car->getNext();

    }
    REQUIRE(count == cars);

    for (int i = 0; i < cars; i++) {
        if (i == 0) {
            REQUIRE(car_ptrs[i]->getNext() == car_ptrs[i + 1]);
        }
        else if (i == cars - 1) {
            REQUIRE(car_ptrs[i]->getPrev() == car_ptrs[i - 1]);
        }
        else {
            REQUIRE(car_ptrs[i]->getNext() == car_ptrs[i + 1]);
            REQUIRE(car_ptrs[i]->getPrev() == car_ptrs[i - 1]);
        }
    }
}

TEST_CASE("TEST CAR SWAP") {
    const int cars = 10;
    Vehicle * car_ptrs[cars];
    Highway swp(3, 500, 1000, "Name", cars);

    Vehicle * car = swp.getCarList();
    for (int i = 0; i < cars; i++) {
        car_ptrs[i] = car;
        car = car->getNext();
    }
    std::cout << std::endl;
    for (int i = 0; i < cars - 1; i=i+2) {
        Vehicle * a = car_ptrs[i];
        Vehicle * b = car_ptrs[i + 1];
        if (i == 0) {
            swp.swap_car_loc(a, b);
            REQUIRE(a->getNext() == car_ptrs[i+2]);
            REQUIRE(a->getPrev() == car_ptrs[i]);
            REQUIRE(b->getNext() == car_ptrs[i+1]);
            REQUIRE(b->getPrev() == nullptr);
        }
        else if (i == cars - 2) {
            swp.swap_car_loc(a, b);
            REQUIRE(a->getNext() == nullptr);
            REQUIRE(a->getPrev() == car_ptrs[i]);
            REQUIRE(b->getNext() == car_ptrs[i+1]);
            REQUIRE(b->getPrev() == car_ptrs[i-1]);
        }
        else {
            swp.swap_car_loc(a, b);
            REQUIRE(a->getNext() == car_ptrs[i+2]);
            REQUIRE(a->getPrev() == car_ptrs[i]);
            REQUIRE(b->getNext() == car_ptrs[i+1]);
            REQUIRE(b->getPrev() == car_ptrs[i-1]);
        }
    }

}
