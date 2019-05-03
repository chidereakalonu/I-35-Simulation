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
    int cars = 200;
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
        count++;
        car = car->getNext();

    }
    REQUIRE(count == cars);
}
