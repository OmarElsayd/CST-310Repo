    
// This program is a modification and extension of an early program in Edward
// Angel's book, Interactive Computer Graphics: A top-down approach using
// OpenGL.  It plots the 3-D Sierpinski Tetrahedron using colors in a nice
// way.

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cstdlib>

// A simple three-dimensional point class to make life easy.  It allows you
// to reference points with x and y coordinates instead of array indices) and
// encapsulates a midpoint function.
struct Point {
  GLfloat x, y, z;  // The x, y, and z coordinates of the point
  Point(GLfloat x, GLfloat y, GLfloat z): x(x), y(y), z(z) {} // Constructor
  Point midpoint(Point p) {return Point((x+p.x)/2, (y+p.y)/2, (z+p.z)/2);}  // Midpoint
};

// Handles reshape requests by setting the the viewport to exactly match the
// pixel coordinates, so we can draw in the whole window.  Then sets up a
// simple perspective viewing volume to ensure that the pyramid will never
// be distorted when the window is reshaped.  The particular settings chosen
// ensure that the vertical extent of the pyramid will always be visible.
void reshape(GLint w, GLint h) {  
  glViewport(0, 0, w, h); // Set the viewport to the entire window
  glMatrixMode(GL_PROJECTION);  // Set up a projection
  glLoadIdentity();  // Initialize the projection
  gluPerspective(100.0, GLfloat(w)/GLfloat(h), 10.0, 1500.0); // Set the viewing volume
}

// Handles display requests.  All it has to do is clear the viewport because
// the real drawing is done in the idle callback.
void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the screen
}

// Draws the "next 500 points".  The function contains locally the definitions
// of the vertices and the current point as static objects so that their values
// are retained between calls.
void generateMorePoints() {

  // The tetrahedron has four vertices.  We also have to keep track of the
  // current point during the plotting.
  static Point vertices[4] = {  // The vertices of the tetrahedron
    Point(-250, -225, -200),  // Lower left front
    Point(-150, -225, -700),  // Lower right front
    Point(250, -225, -275), // Lower right back
    Point(0, 450, -500) // Upper middle
  };
  static Point lastPoint = vertices[0]; // Start with one of the vertices

  // Here is the code to draw the "next 500 points".  The closer the point is
  // to the camera, the brighter we make it.  The coloring technique is a
  // quick hack which (unprofessionally) depends on the fact that the range
  // of z-coordinates in the tetrahedron run from -200 to -700.  By adding
  // 700 to any z-value and then dividing by 500, we get values in the range
  // 0 to 1 - just perfect for coloring.
  glBegin(GL_POINTS); // Start drawing points
  for (int i = 0; i <= 500; i++) {  // Loop 500 times
    lastPoint = lastPoint.midpoint(vertices[rand() % 4]); // Pick a random vertex
    GLfloat intensity = (700 + lastPoint.z) / 500.0;  // Compute the intensity
    glColor3f(intensity, intensity, 0.25);  // Set the color
    glVertex3f(lastPoint.x, lastPoint.y, lastPoint.z);  // Draw the point
  }
  glEnd();  // Done drawing points
  glFlush();  // Finish rendering
}

// Performs application-specific initialization.  In this program we want to
// do depth buffering, which has to be explicitly enabled in OpenGL.
void init() {
  glEnable(GL_DEPTH_TEST);  // Enable depth buffering
}

// Initializes GLUT, the display mode, and main window; registers callbacks;
// does application initialization; enters the main event loop.
int main(int argc, char** argv) { 
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Sierpinski Tetrahedron");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutIdleFunc(generateMorePoints);
  init();
  glutMainLoop();
}

 