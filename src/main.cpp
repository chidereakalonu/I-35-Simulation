#include <iostream>
#include "Graphics.h"
#include "Highway.h"

void drawScene() {
    glClearColor(0, 0.33, 0.0, 1.0);
    clearWindow();          // clear the last scene
    glColor3d(0.0, 0.2, 0.0);
    glutSwapBuffers();      // double buffer
}

void animate() {

}

void handleKey(unsigned char key, int x, int y) {
    switch (key){
      case 'q':
        exit(0);
        break;
    }
}

int main(int argc, char **argv) {
    graphicsSetup(argc, argv);      // initialize the graphics system
    glutDisplayFunc(drawScene);     // tell GLUT what function draws the scene
    glutIdleFunc(animate);          // Move objects when animating
    glutKeyboardFunc(handleKey);    // set up the "q" key to quit
    glutMainLoop();                 // GLUT will control the action

    return 0;
}
