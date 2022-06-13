#include <GL/glut.h>
#include <stdio.h>
#include "glm.h"
GLMmodel * pmodel = NULL;
GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * bot = NULL;
GLMmodel * arm1 = NULL;
GLMmodel * arm2 = NULL;
GLMmodel * hand1 = NULL;
GLMmodel * hand2 = NULL;

float angle[20],oldX=0;
int angleID=0;
FILE *fout = NULL, *fin=NULL;
void myWrite(){
    if(fout==NULL)fout=fopen("file.txt","w+");
    for(int i=0;i<20;i++){
        printf("%.2f",angle[i]);
        fprintf(fout, "%.2f",angle[i]);
    }
}
void myRead(){
    if(fout!=NULL){ fclose(fout); fout=NULL;}
    if(fin==NULL) fin= fopen("file.txt","r");
    for(int i=0;i<20;i++){
        fscanf(fin, "%f", &angle[i] );

    }
    glutPostRedisplay();///�����e��!!
}
void keyboard( unsigned char key ,int x,int y)
{
    printf("Hello World:%c\n",key);
    if(key=='r') myRead();
    if(key=='s') myWrite();///save
    if( key=='0' ) angleID=0;///�w�]�O�o�@��
    if( key=='1' ) angleID=1;
    if( key=='2' ) angleID=2;
    if( key=='3' ) angleID=3;
}
void mouse(int button, int state , int x, int y)///mouse���U�h
{
    oldX = x;
}
void motion(int x,int y)
{
    angle[angleID] += (x-oldX);
    ///myWrite();///�S���n�@���g��
    oldX=x;
    glutPostRedisplay();
}
GLMmodel * myReadOne(char * filename)
{
    GLMmodel * one =NULL;
    if( one == NULL)
    {
        one = glmReadOBJ(filename);
        glmUnitize(one);
        glmFacetNormals(one);
        glmVertexNormals(one,90);
    }
    return one;
}
void display()///�ǳƳ̷s��display(),����C�@����Ū�i��
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(head == NULL) head=myReadOne("data/head.obj");
    glmDraw(head,GLM_SMOOTH);

    glutSwapBuffers();
}
void displayNoParts()///�ǳƷs��
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(pmodel == NULL)
    {
        pmodel = glmReadOBJ("data/Gundam.obj");
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel,90);
    }
    glmDraw(pmodel,GLM_SMOOTH);
    glutSwapBuffers();
}
void displayOld()///���ª���W
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1);
    glRectf(0.3, 0.5, -0.3, -0.2);///�|���Rectangle�A��զ⨭��
    glPushMatrix();
        glTranslatef(0.3, 0.5, 0);///���U�n����0.5,0.5
        glRotatef(angle[0], 0, 0, 1);///Z�b�A(2)����45��
        glTranslatef(-0.3, -0.4, 0);///(1)����त�ߩ�쥿����
        glColor3f(1, 0, 0);
        glRectf(0.3, 0.5, 0.8, 0.3);///�e���u

        glPushMatrix();
            glTranslatef(0.8, 0.4, 0);///(3)��U��y���b���`�W
            glRotatef(angle[1], 0, 0, 1);///(2)����
            glTranslatef(-0.8, -0.4, 0 );///(1)��U��y�����त�ߡA�񥿤���
        glColor3f(0,1,0);
        glRectf(0.8, 0.5, 1.1, 0.3);///�e�U��y
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3, 0.5, 0);///���U�n����0.5,0.5
        glRotatef(angle[2], 0, 0, 1);///Z�b�A(2)����45��
        glTranslatef(0.3, -0.4, 0);///(1)����त�ߩ�쥿����
        glColor3f(1, 0, 0);
        glRectf(-0.3, 0.5, -0.8, 0.3);///�e���u

        glPushMatrix();
            glTranslatef(-0.8, 0.4, 0);///(3)��U��y���b���`�W
            glRotatef(angle[3], 0, 0, 1);///(2)����
            glTranslatef(0.8, -0.4, 0 );///(1)��U��y�����त�ߡA�񥿤���
        glColor3f(0,1,0);
        glRectf(-0.8, 0.5, -1.1, 0.3);///�e�U��y
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();///2�Q�洫��buffer
}
int main(int argc,char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("Week13 rect TRT");
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutDisplayFunc(display);
    glutMainLoop();
}
