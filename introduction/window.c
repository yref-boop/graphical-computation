#include <GL/glut.h>

#define WIDTH 500
#define HEIGTH 500
#define ORIGIN_X 50
#define ORIGIN_Y 50

void init()
{
    glClearColor(0,0,0,0); // set black as default color
}

void display()
{
    // basic config
    glClear(GL_COLOR_BUFFER_BIT); // clear framebuffer
    glMatrixMode(GL_MODELVIEW);   // activate object modification
    glLoadIdentity();             // initialize modifications matrix

    // draw

    glutSwapBuffers(); // change buffer
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION); // enable camera modification
    glLoadIdentity(); // initialize proyection matrix
    glOrtho(-1, 1, 0, 1, -1, 1);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // load mouse & keyboard
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // initialize double framebuffer
    glutInitWindowSize(WIDTH, HEIGTH); // set window size
    glutInitWindowPosition(ORIGIN_X, ORIGIN_Y); // set topleft window position
    glutCreateWindow("Hello World");
    init();
    glutDisplayFunc(display); // activate display function
    glutReshapeFunc(reshape); // activate reshape function
    glutMainLoop(); // start main loop
    return 0;
}
