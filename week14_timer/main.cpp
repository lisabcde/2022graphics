#include <GL/glut.h>
#include <mmsystem.h>
#include <stdio.h>
void timer(int t){///t的單位是ms
    ///1000代表1秒, 1500代表1.5秒
    printf("鬧鐘%d, 我起床了\n", t);///起床做事
    PlaySound("do.wav",NULL,SND_ASYNC);///發出聲音
    printf("設定下一個鬧鐘\n");
    glutTimerFunc(2000,timer, t+1);
    printf("設好鬧鐘,再回去睡\n");
}
void display()
{

}
int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14 timer");

    glutTimerFunc(3000,timer, 0);///3秒後, 叫timer
    glutDisplayFunc(display);
    glutMainLoop();
}
