
#include <GL/glut.h>

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glFlush();
}
void drawsquare(int x , int y)
{
    int n, i;
    float m, ax, ay, bx, by, cx, cy, dx, dy, x1, y1, x2, y2, x3, y3, x4, y4, a, b;
    a = x;
    b = 500 -y;
    n = 25;
    m = 0.9;
    ax = a;
    ay = b ;
    bx = 150.0 +a;  by = b;
    cx= 150.0 + a ; cy= 150.0 + b;
    dx = a ;  dy = 150.0 + b ;
    glClear(GL_COLOR_BUFFER_BIT);
    for ( i=1; i <= n ; ++i )
    {
        glBegin(GL_LINE_LOOP);
        glVertex2f(ax , ay);
        glVertex2f(bx , by);
        glVertex2f(cx , cy);
        glVertex2f(dx , dy);
        glEnd();
            x1 = ax + m * (bx - ax );
    y1 = ay + m * (by - ay );
    x2 = bx + m * (cx - bx);
    y2 = by + m * ( cy - by );
    x3 = cx + m * ( dx - cx );
    y3 = cy + m * ( dy - cy);
    x4 = dx + m * (ax - dx );
    y4 = dy + m * (ay -dy );
    ax = x1; ay = y1;
    bx = x2 ; by = y2;
    cx = x3 ; cy = y3;
    dx = x4 ; dy = y4;
    }

    glFlush();
}



void mymovemouse(int x , int y)
{
    drawsquare(x,y);
}
void mouse(int button , int state , int x , int y)
{
    if( button == GLUT_LEFT_BUTTON&&state == GLUT_DOWN) drawsquare(x,y);
    if( button == GLUT_RIGHT_BUTTON&&state == GLUT_UP);
}
void init()
{
    glClearColor(0.0 , 0.0 ,0.0 ,2.0);
    glColor3f(1.0 , 0.0 , 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);


}
int main( int argc , char ** argv)
{
    glutInit(&argc , argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500 , 500);
    glutInitWindowPosition(0.0 , 0.0);
    glutCreateWindow("square inside square");
    glutMouseFunc(mouse);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}


