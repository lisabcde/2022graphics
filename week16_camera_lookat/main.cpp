
void motion(int x,int y)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt((x-250))
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");

    glutDisplayFunc(display);
    glutMainFunc(motion);

    glutMainLoop();
}
