#include <GL/glut.h>

void displayMe(void) 
{
    glClear(GL_COLOR_BUFFER_BIT);       // clear the screen
    glBegin(GL_POLYGON);            // draw a polygon
        glVertex3f(0.5, 0.5, 0.0);      // top right
        glVertex3f(0.5, -0.5, -0.5);        // bottom right
        glVertex3f(-0.5, -0.5, -0.5);       // bottom left
        glVertex3f(-0.5, 0.5, 0.5);     // top left
    glEnd();            // done drawing the polygon
    glFlush();        // finish rendering
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);        // initialize the toolkit
    glutInitDisplayMode(GLUT_SINGLE);   // set display mode
    glutInitWindowSize(400, 300);   // set window size
    glutInitWindowPosition(100, 100);   // set window position on screen
    glutCreateWindow("Hello world!");   // open the screen window
    glutDisplayFunc(displayMe);    // register redraw function
    glutMainLoop();       // go into a perpetual loop
    return 0;
}