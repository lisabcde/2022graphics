#include <GL/glut.h>
#include <opencv/highgui.h>
void myTexture()
{/// Ipl �O Intel performance library ���Y�g
    IplImage * img = cvLoadImage("earth.jpg");///Ū��
    cvShowImage("img", img);///�q��
    cvWaitKey(0);///�����N���~��
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week09 texture");

    glutDisplayFunc(display);
    myTexture();

    glutMainLoop();
}
