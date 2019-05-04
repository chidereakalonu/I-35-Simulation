#include <iostream>
#include "Graphics.h"
#include "Highway.h"
#include "Random.h"

Highway thirtyfive;

void drawScene(void) {
    glClearColor(0,0.3,0,1);
    clearWindow();          // clear the last scene
    thirtyfive.draw();
    thirtyfive.draw_cars();
    glutSwapBuffers();      // double buffering control
}

void animate() {

    thirtyfive.animate();
    glutPostRedisplay();
    pause_ms(16);

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
    //glutSwapBuffers();              // double buffering control
}
