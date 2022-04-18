#include <GL/glut.h>
#include <opencv/highgui.h>
void myTexture()
{/// Ipl 是 Intel performance library 的縮寫
    IplImage * img = cvLoadImage("earth.jpg");///讀檔
    cvShowImage("img", img);///秀圖
    cvWaitKey(0);///等任意鍵繼續
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
