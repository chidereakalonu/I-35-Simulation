Introduction
============

This is a I-35 highway simulation. The purpose is to simulate traffic on the I-35
corridor through Austin. Each section of road represents one mile -- the top
section is the first mile, the next the second, and so on.

This is an educational repository meant to teach the participants about classes,
linked lists, and simple computer graphics.

The project is broken into a few different parts. The Vehicle class handles
the properties of each car on the road. Each vehicle acts as a node in a
doubly linked list. The Highway class acts a management class for the vehicles,
as well as the management of the linked list of Vehicles.

Requirements
------------

To run on your machine, the I-35 simulator requires you to have a basic GNU
toolset installed on your machine. On Debian-Based linux distributions, this is
provided with the :code:`build-essentials` package. On Mac, this is provided
with the developer tools installation. You will also need the Freeglut libraries
installed on your machine to compile and run. This is included in the developer
tools for Mac, but on Linux, you will need to install the freeglut library
separately.

For Windows, you will need to download and install `the GNU compiler
<http://www.co-pylit.org/courses/cosc1337/lectures/02-Course-Tools/04-installing-mingw.html>`_,
as well as installing the `make toolset
<http://www.co-pylit.org/courses/cosc1337/lectures/02-Course-Tools/03-installing-make.html>`_.

Installation
------------

To install, simply clone the repository and run :code:`make`. ::

    git clone https://github.com/ACC-COSC1337-002-SP19/i35-sim-princess-rainbow-sparkles.git
    make

The following make targets are available:

* :code:`make` - Compiles the repository to an executable
* :code:`make run` - Compiles and launches the executable immediately
* :code:`make clean` - Remove all objects and executables
* :code:`make debug` - Displays the local make variables defined
* :code:`make debug-all` - Displays all make variables defined
* :code:`make help` - Displays a help message showing these make targets.
* :code:`make ignore` - Scans the repo and adds certain files to the .gitignore file
* :code:`make html` - runs sphinx to generate html docs from the :code:`rst/` directory
