//Yago Fernandez Rego

#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdbool.h>

GLint width   = 400;
GLint height  = 400;

GLfloat rotationAngleX  = 0.0f;
GLfloat general_turn    = 0.0f;
GLfloat extension       = 0.0f;
GLfloat extension_turn  = 0.0f;

int mouseX          = 0;
bool turn           = true;
int angle           = 0;
int timerActive     = 1;
int perspective     = true;
int rotation_speed  = 16;
float extra         = 0.0f;

void reshape(int local_width, int local_height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  perspective ?
    gluPerspective(60.0f, (GLfloat)width/(GLfloat)height, 1.0f, 30.0f):
    glOrtho(-15, 15, -15, 15, 1, 30);

  glMatrixMode(GL_MODELVIEW);

  width = local_width;
  height = local_height;
}

void draw_cylinder(float radius, float height, int segments) {

  float angle = 2.0 * M_PI / segments;

  glBegin(GL_TRIANGLE_FAN);
  for (int i = 0; i <= segments; i++) {
    float x = radius * cos(i * angle);
    float y = radius * sin(i * angle);
    glVertex3f(x, y, 0.0);
  }
  glEnd();

  glBegin(GL_QUADS);
  for (int i = 0; i < segments; i++) {
    float x1 = radius * cos(i * angle);
    float y1 = radius * sin(i * angle);
    float x2 = radius * cos((i + 1) * angle);
    float y2 = radius * sin((i + 1) * angle);

    glVertex3f(x1, y1, 0.0);
    glVertex3f(x2, y2, 0.0);
    glVertex3f(x2, y2, height);
    glVertex3f(x1, y1, height);
  }

  glEnd();
}

void draw_cone(float radius, float height, int segments) {
  glTranslatef(0.0, 0.0, 1.0);

  float angle = 2.0 * M_PI / segments;

  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(0.0, 0.0, height);
  for (int i = 0; i <= segments; i++) {
    float x = radius * cos(i * angle);
    float y = radius * sin(i * angle);
    glVertex3f(x, y, 0.0);
  }
  glEnd();
}

void draw_base()
{
  glPushMatrix();
  draw_cylinder(4.0, 1.0, 64);
  glPopMatrix();

  glColor3f(0.0, 0.2, 0.8);
  draw_cone(3.8, 2.0, 64);
}

void draw_extension(){
  glColor3f(0.5, 0.5, 0.5);
  glTranslatef(1.0, 0.0, 2);
  glRotatef(extension, 0.0, 1.0, 0.0);
  glTranslatef(1.0, 0.0, 0.0);

  glPushMatrix();
  glScalef(4.0, 1.0, 1.0);

  glutSolidCube(1);
  glPopMatrix();

  glTranslatef(-1.0, 0.0, 0.0);
  glRotatef(-extension, 0.0, 1.0, 0.0);
}

void draw_top_base(){
  glColor3f(0.0, 1.0, 0.0);
  glTranslatef(3.0 + extension/90, 0.0, 2.0 - extension/25);
  glRotatef(180.0f, 1.0, 0.0, 0.0);

  glRotatef(extension_turn, 0.0, 0.0, 1.0);

  glPushMatrix();
  glTranslatef(0.0, 0.0, 1.0);

  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(0.0, 0.0, 0.0);
  for (int i = 0; i <= 64; i++) {
    float angle = 2.0 * M_PI * i / 64;
    float x = 2.0 * cos(angle);
    float y = 2.0 * sin(angle);
    glVertex3f(x, y, 0.0);
  }
  glEnd();
  glPopMatrix();

  draw_cone(2.0, 1.0, 64);
}

void draw_cube(float x, float y,  float z)
{
  glPushMatrix();
  glTranslatef(x, y , z);
  glutSolidCube(1);
  glPopMatrix();
}

void draw_ride()
{
  draw_extension();

  draw_top_base();

  glColor3f(1.0, 1.2, 0.0);
  draw_cube(1.0, 1.0, -0.5);
  draw_cube(1.0, -1.0, -0.5);
  draw_cube(-1.0, 1.0, -0.5);
  draw_cube(-1.0, -1.0, -0.5);
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  glColor3f(0.5, 0.5, 0.5);
  glTranslatef(0.0, 0.0, -20.0);

  glRotatef(rotationAngleX, 1.0, 0.0, 0.0);
  glRotatef(general_turn, 0.0, 1.0, 0.0);
  glRotatef(-90.0f, 1.0, 0.0, 0.0);

  draw_base();
  draw_ride();

  glFlush();
  glutSwapBuffers();

}

void timer(int value){
  if (timerActive == 1){

    if (angle == 0) { general_turn -= 0.5f + extra; }
    else { general_turn += 0.5f + extra; }

    extension_turn -= 1.0f + extra;

    if (turn) {
      if (extension > -45.0f) { extension -= 1.0f; }
      else{ turn = false; }
    }
    else {
      if (extension < 0.0f) { extension += 1.0f; }
      else { turn = true; }
    }
    glutPostRedisplay();
  }
  glutTimerFunc(rotation_speed, timer, value);
}


void keyboard(unsigned char key, int x, int y)
{
  switch (key)
  {
    // esc
    case 27:
    exit(0);
    break;

    // perspective
    case 'p':
    case 'P':
    perspective = true;
    reshape(width, height);
    break;

    // orthogonal
    case 'o':
    case 'O':
    perspective = false;
    reshape(width, height);
    break;

    // rotate
    case 'r':
    if (angle == 0) angle = 1;
    else angle = 0;
    break;

    case 's':
    if (timerActive == 1) timerActive = 0;
    else timerActive = 1;
    break;
  }
  glutPostRedisplay();
}



void mouseMotion(int x, int y) {
  int deltaX = x - mouseX;
  if (deltaX < 0) {
    if (extension < 0.0f){
      extension += 1.0f;
    }
    else{
      extension = extension;
    }

  } else if (deltaX > 0) {
    if (extension > -45.0f){
      extension -= 1.0f;
    }
    else{
      extension = extension;
    }
  }
  mouseX = x;
  glutPostRedisplay();
}

void mouseClick(int button, int state, int x, int y) {
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && (glutGetModifiers() == GLUT_ACTIVE_ALT)) {
    rotationAngleX += 45.0;
    glutPostRedisplay();
  }
}

void menu_1(int id){
  switch(id){
    case 0:
    printf("Main option 1\n");
    break;

    case 1:
    exit(-1);
    break;
  }
}

void menu_speed(int id){
  switch(id){
    case 0:
    extra = 0.0f;
    rotation_speed=16;
    break;

    case 1:
    extra = 0.5f;
    rotation_speed=1;
    break;
  }
}


int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(width, height);
  glutCreateWindow("exam");

  glClearColor(0, 0, 0, 0);
  glEnable(GL_DEPTH_TEST);
  width   = 400;
  height  = 400;

  int submenu_speed = glutCreateMenu(menu_speed);
  glutAddMenuEntry("Low", 0);
  glutAddMenuEntry("Medium", 1);

  glutCreateMenu(menu_1);
  glutAddSubMenu("Speed", submenu_speed);
  glutAddMenuEntry("Exit", 1);

  glutAttachMenu(GLUT_RIGHT_BUTTON);

  glutTimerFunc(0, timer, 0);

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutPassiveMotionFunc(mouseMotion);
  glutMouseFunc(mouseClick);
  glutMainLoop();

  return 0;
}
