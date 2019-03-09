#include "highway.h"
#include "catch.hpp"

TEST_CASE("Testing default constructor", "Highway") {
    Highway default;
    std::string name = default.get_name();
    int lanes = default.get_lanes();
    int width = default.get_width();
    int length = default.get_length();

    REQUIRE(name == "whatever he chooses as a default");
    REQUIRE(lanes == 3);
    REQUIRE(width == 400);
    REQUIRE(length == 400);

}
// 
// TEST_CASE("Testing Constructor", "Highway") {
//     Highway explicit;
// }
