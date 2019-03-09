#include "Highway.h"
#include "catch.hpp"

TEST_CASE("Testing default constructor", "Highway") {
    Highway dflt;
    std::string name = dflt.get_name();
    int lanes = dflt.get_lanes();
    int width = dflt.get_width();
    int length = dflt.get_length();

    REQUIRE(name == "whatever he chooses as a default");
    REQUIRE(lanes == MIN_LANES);
    REQUIRE(width == MIN_WIDTH);
    REQUIRE(length == MIN_LENGTH);

}

TEST_CASE("Testing Constructor", "Highway") {
    Highway xplct(4, 500, 1000, "Name");
    std::string name = xplct.get_name();
    int lanes = xplct.get_lanes();
    int width = xplct.get_width();
    int length = xplct.get_length();

    REQUIRE(name == "Name");
    REQUIRE(lanes == 4);
    REQUIRE(width == 500);
    REQUIRE(length == 1000);
}
