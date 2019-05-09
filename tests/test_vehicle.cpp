#include "Vehicle.h"
#include "catch.hpp"

TEST_CASE("tests Vehicle distance") {
    Vehicle car;
    int tests = 400;
    for (int i = 0; i < tests; i++) {
        car.move();
        REQUIRE(car.getDistance() == car.getXPos());
    }
}
