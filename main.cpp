#include <iostream>
#include <string>
#include <glew.h>
#include <GLFW/glfw3.h>
#include "GLUT/GL/glut.h"
#include "GLM/glm/matrix.hpp"
#include "GLM/glm/gtc/matrix_transform.hpp"
#include "cugl.h"

using namespace std;
using namespace cugl;

//define window width and height
int windowWidth = 800;
int windowHeight = 800;

//define the color blue
GLfloat blue[] = { 0.3, 0.3, 0.9, 1.0 };

//the idle function
void idle()
{
    /*
     *
     * IMPLEMENTATION CODE GOES HERE (EXECUTED EVERY FRAME)
     *
     */

    glutPostRedisplay();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(0, 0, -200);
    glRotated(90, 0, 1, 0);

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);
    glutSolidSphere(1, 20, 20); //displays a sphere
    glPopMatrix();

    glutSwapBuffers();
}

//handles input
void keyboard (unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27:
            exit(0);
            break;
    }
}

void reshape (int w, int h)
{
    windowWidth = w;
    windowHeight = h;
    glViewport(0, 0, windowWidth, windowHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40, double(w)/double(h), 1, 200);
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    cout << "COMP 376 Assignment 2 Problem 2 \n" << "ESC Quit";
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("COMP 376 Assignment 2 Problem 2");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glutMainLoop();
    return 0;
}