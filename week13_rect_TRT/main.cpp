#include <GL/glut.h>
float angle=45,oldX=0;
void mouse(int button,int state,int x,int y)
{
    oldX = x ;
}
void motion(int x,int y)
{
    angle  += (x-oldX);
    oldX = x;
    glutPostRedisplay();///重畫畫面
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1); ///白色的
    glRectf(0.5,0.5,-0.5,-0.5);
    glPushMatrix();
        glTranslatef(0.5,0.5,0); ///等一下方塊要掛在0.5,0.5的位置
        glRotatef(angle,0,0,1); ///旋轉
        glTranslatef(-0.5,-0.4,0);
        glColor3f(1,0,0); ///紅色的
        glRectf(0.5,0.5,1.0,0.3);
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char**argv)
{
    glutInit( &argc , argv );
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Homework13_TRT");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMainLoop();
}
