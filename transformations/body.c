//Yago Fernandez Rego
// z switches angle
// x switches angle

#include <stdio.h>
#include <math.h>

#include <stdbool.h>
#include <stdbool.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

GLint ancho=400;
GLint alto=400;

GLfloat main0_angleX = 0.0f;
GLfloat main0_angleY = 0.0f;
GLfloat main0_angleZ = 0.0f;
GLfloat sub0_angleX = 0.0f;
GLfloat sub0_angleY = 0.0f;
GLfloat sub0_angleZ = 0.0f;

GLfloat main1_angleX = 0.0f;
GLfloat main1_angleY = 0.0f;
GLfloat main1_angleZ = 0.0f;
GLfloat sub1_angleX = 0.0f;
GLfloat sub1_angleY = 0.0f;
GLfloat sub1_angleZ = 0.0f;

GLfloat main2_angleX = 0.0f;
GLfloat main2_angleY = 0.0f;
GLfloat main2_angleZ = 0.0f;
GLfloat sub2_angleX = 0.0f;
GLfloat sub2_angleY = 0.0f;
GLfloat sub2_angleZ = 0.0f;

GLfloat main3_angleX = 0.0f;
GLfloat main3_angleY = 0.0f;
GLfloat main3_angleZ = 0.0f;
GLfloat sub3_angleX = 0.0f;
GLfloat sub3_angleY = 0.0f;
GLfloat sub3_angleZ = 0.0f;

int joint = 0;

GLboolean change_sub = GL_FALSE;

int perspective = 0;

void menu_1( int id){
    switch( id){
    case 0:
        printf("Opcion 1\n");
        break;
    case 1:
        exit(-1);
        break;
    }
}


void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

      glOrtho(-15, 15, -15, 15, -15, 15);

    glMatrixMode(GL_MODELVIEW);

    ancho = width;
    alto = height;
}


void display_joint(GLfloat x, GLfloat y, GLfloat z, int joint)
{
  GLfloat main_angleX = 0.0;
  GLfloat main_angleY = 0.0;
  GLfloat main_angleZ = 0.0;
  GLfloat sub_angleX = 0.0;
  GLfloat sub_angleY = 0.0;
  GLfloat sub_angleZ = 0.0;

  if (joint == 0) {
    main_angleX = main0_angleX;
    main_angleY = main0_angleY;
    main_angleZ = main0_angleZ;
    sub_angleX = sub0_angleX;
    sub_angleY = sub0_angleY;
    sub_angleZ = sub0_angleZ;
  }
  if (joint == 1) {
    main_angleX = main1_angleX;
    main_angleY = main1_angleY;
    main_angleZ = main1_angleZ;
    sub_angleX = sub1_angleX;
    sub_angleY = sub1_angleY;
    sub_angleZ = sub1_angleZ;
  }
  if (joint == 2) {
    main_angleX = main2_angleX;
    main_angleY = main2_angleY;
    main_angleZ = main2_angleZ;
    sub_angleX = sub2_angleX;
    sub_angleY = sub2_angleY;
    sub_angleZ = sub2_angleZ;
  }
  if (joint == 3) {
    main_angleX = main3_angleX;
    main_angleY = main3_angleY;
    main_angleZ = main3_angleZ;
    sub_angleX = sub3_angleX;
    sub_angleY = sub3_angleY;
    sub_angleZ = sub3_angleZ;
  }

    glTranslatef(x, y, z);

    glColor3f(1.0f, 0.0f, 1.0f);  // magenta
    glutSolidSphere(0.5f, 10, 10);

    glRotatef(main_angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(main_angleY, 0.0f, 1.0f, 0.0f);
    glRotatef(main_angleZ, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, -2.0f, 0.0f);
    glPushMatrix();
    glColor3f(1.0f, 0.5f, 0.0f);  // orange
    glScalef(1.0, 3.0,  1.0);
    glutSolidCube(1);
    glPopMatrix();

    glTranslatef(0.0f, -2.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 1.0f);  // magenta
    glutSolidSphere(0.5, 10, 10);

    glRotatef(sub_angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(sub_angleY, 0.0f, 1.0f, 0.0f);
    glRotatef(sub_angleZ, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f,-2.0f, 0.0f);
    glColor3f(1.0f, 0.5f, 0.0f);  // orange
    glScalef(1.0, 3.0,  1.0);
    glutSolidCube(1);

    glLoadIdentity();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix();
    glColor3f(0.75f, 0.75f, 0.75f);  // gray
    glScalef(1.0, 2.0,  0.1);
    glutSolidCube(4);
    glPopMatrix();

    display_joint(-2.0f, 4.0f, 0.0f, 0);
    display_joint(2.0f, 4.0f, 0.0f, 1);
    display_joint(-1.5f, -4.0f, 0.0f, 2);
    display_joint(1.5f, -4.0f, 0.0f, 3);

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

  GLfloat main_angleX = 0.0;
  GLfloat main_angleY = 0.0;
  GLfloat main_angleZ = 0.0;
  GLfloat sub_angleX = 0.0;
  GLfloat sub_angleY = 0.0;
  GLfloat sub_angleZ = 0.0;

  if (joint == 0) {
    main_angleX = main0_angleX;
    main_angleY = main0_angleY;
    main_angleZ = main0_angleZ;
    sub_angleX = sub0_angleX;
    sub_angleY = sub0_angleY;
    sub_angleZ = sub0_angleZ;
  }
  if (joint == 1) {
    main_angleX = main1_angleX;
    main_angleY = main1_angleY;
    main_angleZ = main1_angleZ;
    sub_angleX = sub1_angleX;
    sub_angleY = sub1_angleY;
    sub_angleZ = sub1_angleZ;
  }
  if (joint == 2) {
    main_angleX = main2_angleX;
    main_angleY = main2_angleY;
    main_angleZ = main2_angleZ;
    sub_angleX = sub2_angleX;
    sub_angleY = sub2_angleY;
    sub_angleZ = sub2_angleZ;
  }
  if (joint == 3) {
    main_angleX = main3_angleX;
    main_angleY = main3_angleY;
    main_angleZ = main3_angleZ;
    sub_angleX = sub3_angleX;
    sub_angleY = sub3_angleY;
    sub_angleZ = sub3_angleZ;
  }

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

  if (joint == 0) {
    main0_angleX = main_angleX;
    main0_angleY = main_angleY;
    main0_angleZ = main_angleZ;
    sub0_angleX = sub_angleX;
    sub0_angleY = sub_angleY;
    sub0_angleZ = sub_angleZ;
  }
  if (joint == 1) {
    main1_angleX = main_angleX;
    main1_angleY = main_angleY;
    main1_angleZ = main_angleZ;
    sub1_angleX = sub_angleX;
    sub1_angleY = sub_angleY;
    sub1_angleZ = sub_angleZ;
  }
  if (joint == 2) {
    main2_angleX = main_angleX;
    main2_angleY = main_angleY;
    main2_angleZ = main_angleZ;
    sub2_angleX = sub_angleX;
    sub2_angleY = sub_angleY;
    sub2_angleZ = sub_angleZ;
  }
  if (joint == 3) {
    main3_angleX = main_angleX;
    main3_angleY = main_angleY;
    main3_angleZ = main_angleZ;
    sub3_angleX = sub_angleX;
    sub3_angleY = sub_angleY;
    sub3_angleZ = sub_angleZ;
  }
}


void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    // x switches joint
    case 'x':
    case 'X':
      joint = (joint + 1) % 4;
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
    glutPostRedisplay();
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

    glutCreateMenu(menu_1);
    glutAddMenuEntry("Solido / alambre", 0);
    glutAddMenuEntry("Movemento automatico", 1);
    glutAddMenuEntry("Cambio velocidade", 2);
    glutAddMenuEntry("Salir", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();


    return 0;
}
