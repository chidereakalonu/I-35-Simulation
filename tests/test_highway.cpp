#include "highway.h"
#include "catch.hpp"

TEST_CASE("Testing default constructor", "Highway") {
    Highway default;
    std::string name = default.get_name();
    int lanes = default.get_lanes();
    int width = default.get_width();
    int length = default.get_length();

    REQUIRE(name == "whatever he chooses as a default");
    REQUIRE(lanes == MIN_LANES);
    REQUIRE(width == MIN_WIDTH);
    REQUIRE(length == MIN_LENGTH);

}

TEST_CASE("Testing Constructor", "Highway") {
    Highway explicit(4, 500, 1000, "Name");
    std::string name = default.get_name();
    int lanes = default.get_lanes();
    int width = default.get_width();
    int length = default.get_length();

    REQUIRE(name == "Name");
    REQUIRE(lanes == 4);
    REQUIRE(width == 500);
    REQUIRE(length == 1000);
}
