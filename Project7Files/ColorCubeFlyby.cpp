//CST-310 Omar, Haley, and Adrian
//Project 7 - part 2 Flying Cubes

#include <GL/glut.h>
#include <cmath>

// Colors
GLfloat WHITE[] = {1, 1, 1};
// GLfloat RED[] = {1, 0, 0};

GLfloat GREEN[] = {0, 1, 0};
// GLfloat MAGENTA[] = {1, 0, 1};

// A camera.  It moves horizontally in a circle centered at the origin of
// radius 10.  It moves vertically straight up and down.
class Camera {
  double theta;      // determines the x and z positions
  double y;          // the current y position
  double dTheta;     // increment in theta for swinging the camera around
  double dy;         // increment in y for moving the camera up/down
public:
  Camera(): theta(0), y(3), dTheta(0.04), dy(0.2) {}
  double getX() {return 4 *cos(theta);}
  double getY() {return 2 * y;}
  double getZ() {return 2*sin(theta);}
  void moveRight() {theta += dTheta;}
  void moveLeft() {theta -= dTheta;}
  void moveUp() {y += dy;}
  void moveDown() {if (y > dy) y -= dy;}
};

GLfloat HH_color[8][3] = {
  {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 1.0},
  {1.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {1.0, 1.0, 0.0}, {1.0, 1.0, 1.0}};

class Square { //square class
  double radius;
  // GLfloat* color;
  double maximumHeight;
  double x;
  double y;
  double z;
  int direction;
public:
  Square(double r, double h, double x, double z):
      radius(r), maximumHeight(h), direction(-1),
      y(h), x(x), z(z) {
  }

  void update() {
    y += direction * 0.05;
    if (y > maximumHeight) {
      y = maximumHeight; direction = -1;
    } else if (y < radius) {
      y = radius; direction = 1;
    }
    glPushMatrix();
    glColor3fv(HH_color[2]);
    // glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
    glTranslated(x, y, z);
    // glColorPointer(3, GL_FLOAT, 0, color);
    //glutSolidSphere(radius, 30, 30);
    glutSolidCube(1);
    glPopMatrix();
  }
  
  void changeColor(GLfloat* color[8][3]){
  const int NUM_FACES = 6;
  GLint faces[NUM_FACES][4] = {
    {1, 5, 7, 3}, {5, 4, 6, 7}, {4, 0, 2, 6},
    {3, 7, 6, 2}, {0, 1, 3, 2}, {0, 4, 5, 1}};
  for (int i = 0; i < NUM_FACES; i++) {
    for (int j = 0; j < 4; j++) {
      glColor3fv((GLfloat*)&color[faces[i][j]]);
    }
  }
  }
};


class Checkerboard { //plane1
  int displayListId;
  int width;
  int depth;
public:
  Checkerboard(int width, int depth): width(width), depth(depth) {}
  double centerx() {return width / 2;}
  double centerz() {return depth / 2;}
  void create() {
    displayListId = glGenLists(1);
    glNewList(displayListId, GL_COMPILE);
    glBegin(GL_QUADS);
    glNormal3d(0, 1, 0);
    for (int x = 0; x < width - 1; x++) {
      for (int z = 0; z < depth - 1; z++) {
        glColor3f(1,0,0);
        glVertex3d(x, 0, z);
        glVertex3d(x+1, 0, z);
        glVertex3d(x+1, 0, z+1);
        glVertex3d(x, 0, z+1);
      }
    }
    glEnd();
    glEndList();
  }
  void draw() {
    glCallList(displayListId);
  }
};



class Checkerboard2 { //plane 2
  int displayListId;
  int width;
  int depth;
public:
  Checkerboard2(int width, int depth): width(width), depth(depth) {}
  double centerx() {return width / 2;}
  double centerz() {return depth / 2;}
  void create() {
    displayListId = glGenLists(1);
    glNewList(displayListId, GL_COMPILE);
    //GLfloat lightPosition[] = {6, 5, 5, 1};
    //glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glBegin(GL_QUADS);
    glNormal3d(0, 1, 0);
    for (int x = 0; x < width - 1; x++) {
      for (int z = 0; z < depth - 1; z++) {
        //glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,
        //             (x + z) % 2 == 0 ? RED : RED);
        glColor3f(1,0,0);
        glVertex3d(x, 10, z);
        glVertex3d(x+1, 10, z);
        glVertex3d(x+1, 10, z+1);
        glVertex3d(x, 10, z+1);
      }
    }
    glEnd();
    glEndList();
  }
  void draw() {
    glCallList(displayListId);
  }
};

namespace Cube { //main rainbow gradient cube

  const int NUM_VERTICES = 8;
  const int NUM_FACES = 6;

  GLint vertices[NUM_VERTICES][3] = {
    {4, 4, 4}, {4, 4, 5}, {4, 5, 4}, {4, 5, 5},
    {5, 4, 4}, {5, 4, 5}, {5, 5, 4}, {5, 5, 5}};

  GLint faces[NUM_FACES][4] = {
    {1, 5, 7, 3}, {5, 4, 6, 7}, {4, 0, 2, 6},
    {3, 7, 6, 2}, {0, 1, 3, 2}, {0, 4, 5, 1}};

  GLfloat vertexColors[NUM_VERTICES][3] = {
    {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 1.0},
    {1.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {1.0, 1.0, 0.0}, {1.0, 1.0, 1.0}};

  void draw() {
    glBegin(GL_QUADS);
    for (int i = 0; i < NUM_FACES; i++) {
      for (int j = 0; j < 4; j++) {
        glColor3fv((GLfloat*)&vertexColors[faces[i][j]]);
        glVertex3iv((GLint*)&vertices[faces[i][j]]);
      }
    }
    glEnd();
  }
}



// Global variables: a camera, two planes and some squares.
Checkerboard checkerboard(8, 8); //plane1
Checkerboard2 checkerboard2(8, 8); //plane2
Camera camera;
Square squares[] = {
  Square(1, 10, 6, 1), //left square
  Square(1, 10, 1, 7) //right square
};

// Application-specific initialization: Set up global lighting parameters
// and create display lists.
void init() {
  glEnable(GL_DEPTH_TEST);
  //glLightfv(GL_LIGHT0, GL_DIFFUSE, WHITE);
  //glLightfv(GL_LIGHT0, GL_SPECULAR, WHITE);
  glMaterialfv(GL_FRONT, GL_SPECULAR, WHITE);
  glMaterialf(GL_FRONT, GL_SHININESS, 30);
  //glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  checkerboard.create();
  checkerboard2.create();
}

// Draws one frame, the planes and then the squares, from the current camera
// position.
void display() {
  static GLfloat u = 0.0;
  u += 0.01;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  //gluLookAt(camera.getX()*cos(u), camera.getY()*cos(u/3)+5, camera.getZ()*cos(u/3)-1,
  //          4.5, -1.0, 4,
  //         0.0, 1.0, 0.0);
  gluLookAt(8*cos(u), 7*cos(u/3)+2, 4*cos(u)-1, 4.5, 4.5, 4.5, cos(u), 1, 0);
  checkerboard.draw();
  checkerboard2.draw();
  Cube::draw();
  for (int i = 0; i < sizeof squares / sizeof(Square); i++) {
    squares[i].update();
  }
  glFlush();
  glutSwapBuffers();
}


// On reshape, constructs a camera that perfectly fits the window.
void reshape(GLint w, GLint h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(40.0, GLfloat(w) / GLfloat(h), 1.0, 150.0);
  glMatrixMode(GL_MODELVIEW);
}

// Requests to draw the next frame.
//void timer(int v) {
//  glutPostRedisplay();
//  glutTimerFunc(1000/60, timer, v);
//}

void timer(int v) {
  static GLfloat u = 0.0;
  u += 0.01;
  glLoadIdentity();
  gluLookAt(8*cos(u), 7*cos(u)-1, 4*cos(u/3)+2, 4.5, 4.5, 4.5, cos(u), 1, 0);
  glutPostRedisplay();
  glutTimerFunc(1000/60.0, timer, v);
}




// Moves the camera according to the key pressed, then ask to refresh the
// display.
void special(int key, int, int) {
  switch (key) {
    case GLUT_KEY_LEFT: camera.moveLeft(); break;
    case GLUT_KEY_RIGHT: camera.moveRight(); break;
    case GLUT_KEY_UP: camera.moveUp(); break;
    case GLUT_KEY_DOWN: camera.moveDown(); break;
  }
  glutPostRedisplay();
}

// Initializes GLUT and enters the main loop.
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Bouncing Balls");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutSpecialFunc(special);
  glutTimerFunc(100, timer, 0);
  init();
  glutMainLoop();
}
