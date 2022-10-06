#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

//Function that builds a solid rectangle of specified width, height, and depth
void solidBox(GLdouble width, GLdouble height, GLdouble depth) {
  glPushMatrix();
  glScalef(width, height, depth);
  glutSolidCube(1.0);
  glPopMatrix();
}

//Display function that builds and displays all shapes in the scene
void display() {

  //Start by clearing the color buffer
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  
  // Section for wall, baseboard and bulletin board
  glPushMatrix();

  //Wall
  glColor3f(0.996f, 0.9f, 0.8f);
  glTranslatef(0.0, 9.5, -1.0);
  solidBox(25.0, 20.0, 1.5);
 
  //Baseboard
  glColor3f(0.0f, 0.0f, 0.0f);
  glTranslatef(0.0, -10.2, 0.0);
  solidBox(27.0, 0.15, 0.1);
  
  
  //End Wall
  glPopMatrix();
  
  //begin weird table
  glPushMatrix();

  glColor3f(0.444f, 0.444f, 0.444f);
  glTranslatef(-6.0, 0.58, -0.5);
  solidBox(2.0, 0.15, 1.5);

  glPopMatrix();
  //end tabletop

    //begin weird table
  glPushMatrix();

  glColor3f(0.444f, 0.444f, 0.444f);
  glTranslatef(-6, -0.26, -0.26);
  solidBox(0.1, 1.5, 1);

  glPopMatrix();
  
  //Begin Leftmost chair
  glPushMatrix();

  //Left arm of chair
  glColor3f(0.454f, 0.724f, 0.929f);
  glTranslatef(-4.5, 0.0, 0.0);
  solidBox(0.25, 1.5, 1.5);
  
  //Bottome of seat
  glColor3f(0.25f, 0.25f, 0.25f);
  glTranslatef(0.87, -0.25, 0.0);
  solidBox(1.5, 0.25, 1.5);
  
  glColor3f(1.0f, 1.0f, 1.0f);
  glTranslatef(0.0, 0.25, 0.0);
  solidBox(1.5, 0.25, 1.5);
  
  //Back of chair
  glColor3f(0.4f, 0.4f, 0.4f);
  glTranslatef(0.0, 0.6, -0.8);
  solidBox(1.5, 1.0, 0.25);
  
  //Right arm of chair
  glColor3f(0.3f, 0.3f, 0.3f);
  glTranslatef(0.87, -0.6, 0.8);
  solidBox(0.25, 1.5, 1.5);
  
  //End Leftmost chair
  glPopMatrix();
  
  //Begin Left-center chair
  glPushMatrix();
  
  //Left arm of chair
  glColor3f(0.3f, 0.3f, 0.3f);
  glTranslatef(-2.2, 0.0, 0.0);
  solidBox(0.35, 1.5, 1.5);
  
  //Bottome of seat
  glColor3f(0.25f, 0.25f, 0.25f);
  glTranslatef(2.9, -0.25, 0.3);
  solidBox(5.5, 0.25, 1.5);
  
  //Orange top seat
  glColor3f(1.0f, 1.0f, 1.0f);
  glTranslatef(0.0, 0.25, 0.0);
  solidBox(5.5, 0.25, 1.5);
  
  //Back of chair
  
  //Right arm of chair
  glColor3f(0.34f, 0.34f, 0.34f);
  glTranslatef(2.8, -0.2, 0.0);
  solidBox(0.35, 1.5, 0.3);
  
  //End left-center chair 
  glPopMatrix();
  glFlush();
}

//Reshape, set up projection for secene 
void reshape(GLint w, GLint h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(65.0, GLfloat(w)/GLfloat(h), 1.0, 20.0);
}

//Function to initialize the scene
void init() {
	//set background color
  glClearColor(0.5f,0.5f,0.5f,0.5f);
  glShadeModel(GL_FLAT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  //Camera angle - void gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
  gluLookAt(1,2,10, 0,3,0, 0,1,0);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(1000, 1000);
  glutCreateWindow("Chair");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  init();
  glutMainLoop();
}