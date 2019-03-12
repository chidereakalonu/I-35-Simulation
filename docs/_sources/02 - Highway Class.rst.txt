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

The constants with the :code:`DIV` prefix are for setting the lane dividers between
the lanes. The :code:`MIN_WIDTH` and :code:`MIN_LENGTH` constants use constants
from the Graphics library provided.

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

Draw Method
-----------

The draw method is used to draw the four sections of highway. It must be invoked
in order to have the base highway available on the screen.
