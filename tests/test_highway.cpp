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
    const int cars = 50;
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

TEST_CASE("Test Car Sorting", "Highway") {
    const int cars = 200;
    Highway sort(3, 500, 1000, "Name", cars);
    Vehicle * car = sort.getCarList();
    Random dice;
    while (car != nullptr) {
        int dist = dice.randint(1, 100);
        car->setDistance(dist);
        car = car->getNext();
    }
    sort.sort_cars();
    car = sort.getCarList();
    while (car->getNext() != nullptr) {
        Vehicle * nxt = car->getNext();
        REQUIRE(((car->getDistance() == nxt->getDistance()) || (car->getDistance() < nxt->getDistance())));
        car = nxt;
    }
    while (car->getPrev() != nullptr) {
        Vehicle * prv = car->getPrev();
        REQUIRE(((car->getDistance() == prv->getDistance()) || (car->getDistance() > prv->getDistance())));
        car = prv;
    }
}
