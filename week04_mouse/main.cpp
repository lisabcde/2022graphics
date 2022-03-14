#include <GL/glut.h>
#include <stdio.h>
int mouseX=0,mouseY,N=0;///N個點!!!
int mx[100],my[100];///用來記錄,等一下要畫出來喔!!
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    glBegin(GL_LINE_LOOP);
        for(int i=0;i<N;i++){
            glVertex2f((mx[i]-150)/150.0,-(my[i]-150)/150.0);
        }
        glEnd();
    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
    //printf("%d %d %d %d\n",button,state,x,y);
    mouseX=x;mouseY=y;
    if(state==GLUT_DOWN){///按下去的(放開的不算數)
        printf(" glVertex2f( (%-150)/150.0, -(%d-150)/150.0 );\n",x,y);
        N++;
        mx[N-1]=x;my[N-1]=y;
    }
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04 mouse");

    glutDisplayFunc(display);///Display顯示
    glutMouseFunc(mouse);///Mouse滑鼠
    glutMainLoop();
}
