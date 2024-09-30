#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define WIDTH 400
#define HEIGTH 400
#define ORIGIN_X 100
#define ORIGIN_Y 100

void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear depth buffer
    glLoadIdentity();

    // white triangle
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_TRIANGLES);
      glVertex3f(-1.0f ,-1.0f ,-1.0f ); //V1
      glVertex3f(1.0f ,-1.0f , -1.0f ); //V2
      glVertex3f(0.0f ,1.0f , -1.0f ); //V3
    glEnd();

    // red dots
    glColor3f(1.0f, 0.0f, 0.0f);

    glPointSize(5.0f); // increase the point size
    glBegin(GL_POINTS);
      glVertex3f(0.0f, 0.0f, -2.0f); // point inside the triangle
      glVertex3f(2.0f, 1.0f, -2.0f); // point outside the triangle
    glEnd();

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 4.0, -2.0, 4.0, -2.0, 4.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // init depth
    glutInitWindowSize(WIDTH, HEIGTH);
    glutInitWindowPosition(ORIGIN_X, ORIGIN_Y);
    glutCreateWindow("Hello World");
    glEnable(GL_DEPTH_TEST); // enable depth after creating the window
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
