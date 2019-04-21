Highway Class
=============

The highway class acts as a management class for the traffic, as well as drawing
the lanes and sections of road.

Constants
---------

The highway class uses the following constants::

    MIN_LANES = 3;
    MIN_WIDTH = WINDOW_HEIGHT / 8;
    MIN_LENGTH = WINDOW_WIDTH;
    HIGHWAY_SECTIONS = 4;
    DIV_LENGTH = 25;
    DIV_SPACE = 5;
    DIV_WIDTH = 3;
    LANE_HEIGHT = MIN_WIDTH / MIN_LANES;


The constants with the :code:`DIV` prefix are for setting the lane dividers between
the lanes. The :code:`MIN_WIDTH` and :code:`MIN_LENGTH` constants use constants
from the Graphics library provided. :code:`LANE_HEIGHT` is used to calculate the
placement of the vehicle in the correct lane when drawn.

Constructors
------------

The highway class provides for two constructors: a default and an explicit
constructor.

The Default constructor sets the features of the Highway object to the constants
listed above and sets the name of the object to "I-35".

The explicit constructor expects 4 parameters::

    Highway::Highway(int lane, int wid, int len, std::string nam) {
        lanes = lane;
        width = wid;
        length = len;
        name = nam;
    }

Accessors
---------

There are accessor functions available for each of the features set in the
constructors::

    get_name();
    get_lanes();
    get_width();
    get_length();
    getTraffic();

:code:`get_name()` returns the name of the highway simulator. At time of writing
this is not used.

:code:`get_lanes()` returns the number of lanes per section.

:code:`get_width()` returns the width of each section.

:code:`get_length()` returns the length of each highway section.

:code:`getTraffic()` is used to return the linked list of cars. In particular,
it points to the very first car in the list in order to kick off the linked list
walk.

Draw Method
-----------

The draw method is used to draw the four sections of highway. It must be invoked
in order to have the base highway available on the screen.

Drawing Cars
------------

The :code:`draw_cars()` method is responsible for drawing every single car that
is spawned in the simulator. It begins by walking through the car linked list::

    if (car->getXPos() < 0 - car->getSize() ) {
        car->setMile(0);
        current_mile = car->getMile();
    }
    else if (car->getXPos() > WINDOW_WIDTH) {
        car->setMile(current_mile + 1);
        car->setPosition(0 - car->getSize(), car->getYPos());
    }
    else {
        int yPos = mile[current_mile] + ( (2 * current_lane - 1) * width / 6 );
        car->setPosition(car->getXPos(), yPos);
    }
    if (current_mile >= HIGHWAY_SECTIONS) car->setPosition(-100, -100);

If the X-Position of the car is less than 0, the algorithm assumes that the car
is queued up to begin and makes sure that the mile is set to 0, so it begins
at the top of the simulation. Otherwise, if the car goes off of the side of the
screen, the algorithm assumes it is time to move it to the next section and
sets the mile + 1. If the car is on the road, the algorithm will simply check
which lane the car is supposed to be in and put it there. A more complicated
lane switching algorithm should be inserted here in the future.

Finally, when the car goes off of the side of the screen on the final mile, the
position is set to (-100, -100). This will trigger the first if statement and
repeat the entire process. The rest of the drawing housekeeping can be seen
here::

    int len = car->getSize();
    int car_x_bot = car->getXPos();
    int car_y_bot = car->getYPos() - (LANE_HEIGHT / 2 - 5);
    int car_x_top = car_x_bot + len;
    int car_y_top = car->getYPos() + (LANE_HEIGHT / 2 - 5);
    setColor(RED);
    drawFilledBox(car_x_bot, car_y_bot, car_x_top, car_y_top);

    // move ptr to next in the list
    car = car->getNext();
