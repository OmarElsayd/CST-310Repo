#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>
#include <time.h>

void solidBox(GLdouble width, GLdouble height, GLdouble depth) {
      glPushMatrix();
      glScalef(width, height, depth);
      glutWireSphere(0.2, 5,10);
      glPopMatrix();
}

void solidBox2(GLdouble width, GLdouble height, GLdouble depth) {
      glPushMatrix();
      glScalef(width, height, depth);
      glutWireCube(1);
      glPopMatrix();
}

void display() {
        glClear(GL_COLOR_BUFFER_BIT);
        srand((unsigned)time(NULL));
        float color1 = (float) rand()/RAND_MAX;
        float color2 = (float) rand()/RAND_MAX;
        float color3 = (float) rand()/RAND_MAX;
        glPushMatrix();
        for (int i = -25; i < 25; i += 5){
                for (int j = -25; j < 25; j += 5){
                        for (int k = -25; k < 25; k += 5){
                                glPushMatrix();
                                glColor3f(color1, color2, color3);
                                glTranslatef(i, j, k);
                                solidBox(0.44, 0.90, 0.88);
                                color1 = ((float) rand()/RAND_MAX);
                                color2 = (float) rand()/RAND_MAX;
                                color3 = (float) rand()/RAND_MAX;
                                glPushMatrix();
                                glPushMatrix();
                                glColor3f(color1, color2, color3);
                                glTranslatef(i+3, j+3, k+3);
                                solidBox2(0.44, 0.90, 0.88);
                                color1 = ((float) rand()/RAND_MAX);
                                color2 = (float) rand()/RAND_MAX;
                                color3 = (float) rand()/RAND_MAX;
                                glPushMatrix();
                        }
                }
        }
        glPopMatrix();
        glFlush();
        glutSwapBuffers();
}

void timer(int v) {
        static GLfloat u = 0.0;
        u += 0.01;
        glLoadIdentity();
        gluLookAt(8*cos(u), 7*cos(u)-1, 4*cos(u/3)+2, .0, 1.0, .0, cos(u), 1, 0);
        glutPostRedisplay();
        glutTimerFunc(1000/60.0, timer, v);
}

void reshape(int w, int h) {
        glViewport(0, 0, w, h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60.0, GLfloat(w) / GLfloat(h), 0.5, 40.0);
        glMatrixMode(GL_MODELVIEW);
}

void init() {
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
}

int main(int argc, char** argv) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize(1500, 1500);
        glutCreateWindow("Project 8");
        glutReshapeFunc(reshape);
        glutTimerFunc(100, timer, 0);
        glutDisplayFunc(display);
        init();
        glutMainLoop();
}