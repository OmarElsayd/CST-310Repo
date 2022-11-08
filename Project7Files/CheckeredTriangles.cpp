#include <stdlib.h> 
#include <math.h> 
#include <stdio.h> 
#include <SOIL/SOIL.h>
#ifdef __APPLE_CC__
#include <GLUT/glut.h> //glut library 
#else
#include <GL/glut.h> //glut library 
#endif
#include <cstdlib>
#define ESC 27


float lx=0.0f, ly=0.0f, lz=-1.0f; //variables for x, y, and z axis
float x=0.0f, y=1.0f, z=5.0f;
float angle = 0.0f;


#define red {0xff, 0x00, 0x00}  //colors of the triangles 
#define yellow {0xff, 0xff, 0x00}
#define magenta {0xff, 0, 0xff}
GLubyte texture[][3] = {
    red, yellow,
    yellow, red,
};


struct rot_state { //function for rotation movement of the triangles
    bool rotating;    // animation/movement happening
    float x,y,z;      // current rotation values
    int current_axis; // 0 for x, 1 for y, 2 for z
} app_state;


void init(void){  
    // Setting up initial app state
    app_state.rotating = false; //no movement yet
    app_state.x = app_state.y = app_state.z = 0.0f;
    app_state.current_axis = 0; //current axis should lie on the x axis

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
}


void action(void)
{
    // animate the rotation
    float increment = 1.0f;
    switch (app_state.current_axis)
    {
    case 0: //this case is for the x axis
        app_state.z += increment;  
        break;
    case 1:
        app_state.y += increment; //this case is for the y axis 
        break;
    case 2:
        app_state.x += increment;  //this case is for the z axis 
        break;
    default:
        break;
    }

    glutPostRedisplay();
}



// fixes up camera and remaps texture when window reshaped.
void reshape(int width, int height) {
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(80, GLfloat(width)/height, 1, 40);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(x, y, z, x+lx, 1.0f,  z+lz, 0.0f, 1.0f, 0.0f); //camera 
  glEnable(GL_TEXTURE_2D);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glTexImage2D(GL_TEXTURE_2D,
               0,                    // level 0
               3,                    // use only R, G, and B components
               2, 2,                 // texture has 2x2 texels
               0,                    // no border
               GL_RGB,               // texels are in RGB format
               GL_UNSIGNED_BYTE,     // color components are unsigned bytes
               texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

// Draws three textured triangles.  Each triangle uses the same texture,
// but the mappings of texture coordinates to vertex coordinates is
// different in each triangle.
void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  
    glRotatef(app_state.x, 1, 0, 0);
    glRotatef(app_state.y, 0, 1, 0);
    glRotatef(app_state.z, 0, 0, 1);
  glBegin(GL_TRIANGLES);
    glTexCoord2f(0.5, 1.0);    glVertex2f(-3, 3); //triangle 1
    glTexCoord2f(0.0, 0.0);    glVertex2f(-3, 0);
    glTexCoord2f(1.0, 0.0);    glVertex2f(0, 0);

    glTexCoord2f(4, 8);        glVertex2f(3, 3); //triangle 2
    glTexCoord2f(0.0, 0.0);    glVertex2f(0, 0);
    glTexCoord2f(8, 0.0);      glVertex2f(3, 0);

    glTexCoord2f(5, 5);        glVertex2f(0, 0); //triangle 3
    glTexCoord2f(0.0, 0.0);    glVertex2f(-1.5, -3);
    glTexCoord2f(4, 0.0);      glVertex2f(1.5, -3);
  glEnd();
  glFlush();
}

void changeSize(int w, int h) {

    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if (h == 0)
        h = 1;
    float ratio = w * 1.0 / h;

    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);

    // Reset Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set the correct perspective.
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);

    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) {

 
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(x, y, z, x+lx, y+ly,  z+lz, 0.0f, 1.0f, 0.0f); //camera
  glEnable(GL_TEXTURE_2D);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  glTexImage2D(GL_TEXTURE_2D,
               0,                    // level 0
               3,                    // use only R, G, and B components
               2, 2,                 // texture has 2x2 texels
               0,                    // no border
               GL_RGB,               // texels are in RGB format
               GL_UNSIGNED_BYTE,     // color components are unsigned bytes
               texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    // Set the camera
    gluLookAt( x, y, z,
        x+lx, y+ly, z+lz,
        0.0f, 1.0f, 0.0f);

    display();

    glutSwapBuffers();
}


void processNormalKeys(unsigned char key, int x, int y) { //function for moving camera and view with keys

	float fraction = 0.01f;
	float fraction2 = 0.1f;
	switch (key) {
        	case 27 :
            		exit(0);
        	break;
        	case 'd':  //use the D key to move the view down 
            		y = y - fraction;
            		ly = ly - fraction;
        	break;
        	case 'r':  //use the R key to move the view to the right
            		x = x - fraction;
            		lx = lx - fraction;
        	break;
        	case 'l': //use the L key to move the view to the left
            		x = x + fraction;
            		lx = lx + fraction;
        	break;
        	case 'u':  //use the U key to move the view up
            		y = y + fraction;
            		ly = ly + fraction;
        	break;
        	case '-': // use key - to zoom out of the image
            		x -= lx * fraction2;
            		z -= lz * fraction2;
        	break;
        	case '=': //use the + key to zoom in on the image
            		x += lx * fraction2;
            		z += lz * fraction2;
        	break;
    		case 'p': //use the key P to pause the rotation of the triangles
        		app_state.rotating ^= 1;
        		glutIdleFunc(app_state.rotating ? action : NULL);
        	break;
         	case 'c': //press the key C to continue the rotation
        		app_state.rotating ^= 1;
        		glutIdleFunc(app_state.rotating ? action : NULL);
        	break;
    	}
    glutPostRedisplay();
}


// Initializes GLUT and enters the main loop.
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(520, 390);  //window size
  glutCreateWindow("Textured Triangles"); //window title
  glutDisplayFunc(renderScene);
  glutReshapeFunc(changeSize);
  glutIdleFunc(renderScene);
  glutKeyboardFunc(processNormalKeys); //initiates the keyboard function 
  glEnable(GL_DEPTH_TEST);
  glutMainLoop();
}
