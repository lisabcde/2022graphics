#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef( angle, 0, 0, 1);///����
        glTranslatef(0.4,-0.07,0);///���k�U����(����ܦ����त��)
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.1;
}
int main(int argc,char**argv)
{
    glutInit( &argc , argv );
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week12 TRT");
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}