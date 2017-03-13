#include <graphics.h>
#include "animation.h"
#define DELAY_TIME 10			//Microseconds

void init(void)
{
	int gd=DETECT;
	int gm;

	initgraph(&gd, &gm, NULL);
}

void draw(void)
{
		int points[]={100, 210, -100, -190};
		int n = (sizeof(points))/(2*sizeof(points[0]));
		int fpoints[n*2];

		int triangle[]={100, 40, 80, 80, 140, 80, 100, 40};
		int m = 4;
		int ftriangle[8];

		flipAxis(ftriangle, triangle, m);
		drawpoly(m, ftriangle);

		float I[3][3];				toIdentity(I);
		float T[3][3];

//		translateMat(T, 0, -10);	combine(T, I);
//		rotateMat(T, 26.57);		combine(T, I);
//		toIdentity(T); T[0][0]=-1;	combine(T, I);
//		rotateMat(T, -26.57);		combine(T, I);
//		translateMat(T, 0, 10);		combine(T, I);

		translateMat(T, 0.533, -8.933);	combine(T, I);
		rotateMat(T, 180);				combine(T, I);
		translateMat(T, -0.533, 8.933);	combine(T, I);
		
		valMat(I, points, n);
		flipAxis(fpoints, points, n);
		drawpoly(n, fpoints);

		valMat(I, triangle, m);
		flipAxis(ftriangle, triangle, m);
		drawpoly(m, ftriangle);
}

void end(void)
{
	while(getchar() == 0);						// Don't close it 
	closegraph();
}

int main(int args, char *argv[])
{
	init();							// Initialise

	line(0, getmaxy()/2, getmaxx(), getmaxy()/2);
	line(getmaxx()/2, 0, getmaxx()/2, getmaxy());
	draw();							// Draw on the graph
	
	end();							
	return 0;
}
