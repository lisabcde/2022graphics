#include <GL/glut.h>
#include <stdio.h>///為了printf, fprintf, fopen, fclose
float angle[20],oldX=0;
int angleID=0; ///0:第0個關節,1:第1個關節...
FILE *fout = NULL;
void myWrite()
{
    if(fout==NULL) fout = fopen("file.txt", "w+");
    for(int i=0; i<20; i++){
            printf("%.2f",angle[1]);
        fprintf(fout, "%.2f",angle[1]);
    }
    printf("\n");
    fprintf(fout, "\n");
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}
void mouse(int button,int state,int x,int y)
{
    oldX = x ;
}
void motion(int x,int y)
{
    angle[angleID] += (x-oldX);
    myWrite();
    oldX = x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectf(0.3,0.5,-0.3,-0.2);
    glPushMatrix();
        glTranslatef(0.3,0.5,0);
        glRotatef(angle[0],0,0,1);
        glTranslatef(-0.3,-0.4,0);
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.8,0.3);
        glPushMatrix();
            glTranslatef(0.8,0.4,0);
            glRotatef(angle[1],0,0,1);
            glTranslatef(-0.8,-0.4,0);
            glColor3f(0,1,0);
            glRectf(0.8,0.5,1.1,0.3);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3,0.5,0);
        glRotatef(angle[2],0,0,1);
        glTranslatef(+0.3,-0.4,0);
        glColor3f(1,0,0);
        glRectf(-0.3,0.5,-0.8,0.3);
        glPushMatrix();
            glTranslatef(-0.8,0.4,0);
            glRotatef(angle[3],0,0,1);
            glTranslatef(+0.8,-0.4,0);
            glColor3f(0,1,0);
            glRectf(-0.8,0.5,-1.1,0.3);
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char**argv)
{
    glutInit( &argc , argv );
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Homework13_many_TRT");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMainLoop();
}
