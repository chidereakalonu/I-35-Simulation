Vehicle Class
=============

The vehicle class handles the creation and movement of each vehicle being driven
down the highway. Vehicles are generated using the random class described below
to have different characteristics to ensure a less predictable highway
simulation.

Randomizer
----------

The random Class provides a few methods to initialize and set up the vehicles.
To use the randomizer simply :code:`#include "Random.h"` and create an instance
of the class: `Random dice`. This will seed the random function when the class
is instanced, ensuring a different loadout of vehicles every time. We have
borrowed the :code:`randint()` function from python::

    randint(MIN, MAX);

Where :code:`MIN` is the beginning of the range and :code:`MAX` is the end of
the range.
