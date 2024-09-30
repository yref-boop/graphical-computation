//Yago Fernandez Rego
// z switches angle

#include <stdio.h>
#include <math.h>

#include <stdbool.h>
#include <stdbool.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

GLint ancho=400;
GLint alto=400;

GLfloat main_angleX = 0.0f;
GLfloat main_angleY = 0.0f;
GLfloat main_angleZ = 0.0f;

GLfloat sub_angleX = 0.0f;
GLfloat sub_angleY = 0.0f;
GLfloat sub_angleZ = 0.0f;

GLboolean change_sub = GL_FALSE;

int perspective = 0;

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-5, 5, -5, 5, -5, 5);

    glMatrixMode(GL_MODELVIEW);

    ancho = width;
    alto = height;
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();


    glColor3f(1.0f, 0.0f, 1.0f);  // magenta
    glutSolidSphere(0.5f, 10, 10);

    glLoadIdentity();

    glRotatef(main_angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(main_angleY, 0.0f, 1.0f, 0.0f);
    glRotatef(main_angleZ, 0.0f, 0.0f, 1.0f);
    glTranslatef(-1.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 0.5f, 0.0f);  // orange
    glutSolidCube(1);

    glTranslatef(-1.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 1.0f);  // magenta
    glutSolidSphere(0.5f, 10, 10);


    glRotatef(sub_angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(sub_angleY, 0.0f, 1.0f, 0.0f);
    glRotatef(sub_angleZ, 0.0f, 0.0f, 1.0f);
    glTranslatef(-1.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 0.5f, 0.0f);  // orange
    glutSolidCube(1);

    glLoadIdentity();

    glFlush();
    glutSwapBuffers();
}

void init()
{
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
    ancho = 400;
    alto = 400;
}

void idle()
{
    display();
}


void update_angles (int increase, char dimension) {

  switch (dimension)
  {
    case 'X':
      if (increase)
        if (change_sub == GL_TRUE)
          sub_angleX += 1;
        else
          main_angleX += 1;
      else
        if (change_sub == GL_TRUE)
          sub_angleX -= 1;
        else
          main_angleX -= 1;
      break;

    case 'Y':
      if (increase)
        if (change_sub == GL_TRUE)
          sub_angleY += 1;
        else
          main_angleY += 1;
      else
        if (change_sub == GL_TRUE)
          sub_angleY -= 1;
        else
          main_angleY -= 1;
      break;

      case 'Z':
      if (increase)
        if (change_sub == GL_TRUE)
          sub_angleZ += 1;
        else
          main_angleZ += 1;
      else
        if (change_sub == GL_TRUE)
          sub_angleZ -= 1;
        else
          main_angleZ -= 1;
      break;
  }
}


void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {

    // z switches rotation
    case 'z':
    case 'Z':
      if (change_sub == GL_TRUE)
        change_sub = GL_FALSE;
      else
        change_sub = GL_TRUE;
    case 'q':
    case 'Q':
      update_angles(true, 'X');
      break;
    case 'a':
    case 'A':
      update_angles(false, 'X');
      break;
    case 'w':
    case 'W':
      update_angles(true, 'Y');
      break;
    case 's':
    case 'S':
      update_angles(false, 'Y');
      break;
    case 'e':
    case 'E':
      update_angles(true, 'Z');
      break;
    case 'd':
    case 'D':
      update_angles(false, 'Z');
      break;
    case 27: // esc
      exit(0);
      break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(ancho, alto);
    glutCreateWindow("joint");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
