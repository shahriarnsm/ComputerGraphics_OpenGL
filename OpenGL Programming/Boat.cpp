#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>


static float tx = -90, ty = 0;

void quad_move()
{
    tx+=.1;
    //ty+=.01;
    if(tx > 200)
    {
        tx = -90;
    }

    glutPostRedisplay();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(tx,ty,0);

    //water color
    glColor3f(0.3, 0.3, 1);
    glRectf(-10.0, -100.0, 200.0, -25.0);
    glEnd();

    //Boat color
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-2.0f, -15.0f);
    glVertex2f(80.0f, -15.0f);
    glVertex2f(55.0f, -60.0f);
    glVertex2f(20.0f, -60.0f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glRectf(35.0, 8.0, 40.0, -15.0);
    glEnd();

    glPopMatrix();


    glutPostRedisplay();

    //quad_move();

    glFlush();
}


void init(void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}


int main(int argc, char** argv)
{glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1000, 600);
    glutInitWindowPosition (50, 50);
    glutCreateWindow ("Transformation");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
