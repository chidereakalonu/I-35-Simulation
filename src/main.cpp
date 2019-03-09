#include <iostream>
#include "Graphics.h"
#include "Highway.h"
int main() {
    std::cout << "Hello, World!";

    graphicsSetup(argc, argv);      // initialize the graphics system
    glutDisplayFunc(drawScene);     // tell GLUT what function draws the scene
    glutIdleFunc(animate);          // Move objects when animating
    glutKeyboardFunc(handleKey);    // set up the "q" key to quit
    glutMainLoop();                 // GLUT will control the action

    return 0;
}
