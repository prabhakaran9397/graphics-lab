#include <unistd.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void drawDot(GLint x, GLint y)
{
	glBegin(GL_POINTS);
		glVertex2f(x, y);
	glEnd();
}

void drawLineD(GLint sx, GLint sy, GLint ex, GLint ey)					//DDA Method Line
{
	int dx = abs(sx-ex);
	int dy = abs(sy-ey);
	int step = dx>dy ? dx : dy;
	float xinc = 1.0*dx/step;
	float yinc = 1.0*dy/step;
	float x = sx;
	float y = sy;
	for(int i=0; i<step; ++i, x+=xinc, y+=yinc) {
		drawDot(round(x), round(y));
	}
}

void drawLineC(GLint sx, GLint sy, GLint ex, GLint ey)					//Counter Method Line
{
	int dx = abs(sx-ex);
	int dy = abs(sy-ey);
	int step = dx>dy ? dx : dy;
	int count = dx<dy ? dx : dy;
	int x = sx;
	int y = sy;
	for(int i=0; i<step; ++i) {
		drawDot(x, y);
		x = dx>dy ? x+1 : (count<step ? x : x+1);
		y = dy>dx ? y+1 : (count<step ? y : y+1);
		count = count<step? count+(dx<dy ? dx : dy) : count-step;
	}
}

void drawLineS(GLint sx, GLint sy, GLint ex, GLint ey)					//Graphic Library Line
{
	glBegin(GL_LINES);
		glVertex2f(sx, sy);
		glVertex2f(ex, ey);
	glEnd();	
}

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawLineC(200, 200, 500, 270);
	drawLineD(100, 100, 400, 170);
	drawLineD(0, 0, 300, 70);
	glFlush();
}

int main(int args, char *argv[])
{
	glutInit(&args, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Hello World!");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();

	return 0;
}
