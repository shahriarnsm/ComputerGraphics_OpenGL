#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 100; i++) {
        float angle = 2 * 3.1416 * i / 100;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2d(x - cx, y - cy);
    }
    glEnd();

    // glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    circle(7, 7, 3, 3);
    
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(6, 6, 0, 0);
    glEnd();

    glFlush();
}
void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-15, 15, -15, 15);
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("polygon");
    glutInitWindowSize(320, 320);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}