#include <stdio.h>
#include <GL/glut.h>
int N=0;///�@�}�l�S�������I
int x[1000],y[1000];///�̦h�i�H��1000�ӳ��I��!!
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<N;i++){///�ΰj��,�eN�ӳ��I
        glVertex2f((x[i]-150)/150.0,-(y[i]-150)/150.0);
    }            ///��@�b�B���@�b�By�n�[�W�t��
    glEnd();
    glutSwapBuffers();
}
///void mouse(int button,int state,int mouseX,int mouseY)
void motion(int mouseX,int mouseY)
{
    //if(state==GLUT_DOWN){
        N++;
        x[N-1]=mouseX;///�̫�@�ӷs�W�����I��x�y��
        y[N-1]=mouseY;///�̫�@�ӷs�W�����I��y�y��
        printf("�{�b���U�ƹ�,�o��s�y�� %d %d\n",x[N-1],y[N-1]);
    //}
    display();
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week05 �Ʋ�mouse");

    glutDisplayFunc(display);
    ///glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}
